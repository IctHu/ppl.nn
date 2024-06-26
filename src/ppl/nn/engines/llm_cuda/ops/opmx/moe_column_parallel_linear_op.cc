// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#include "moe_column_parallel_linear_op.h"

#include "ppl/nn/engines/llm_cuda/kernels/opmx/moe_column_parallel_linear_kernel.h"
#include "ppl/nn/oputils/opmx/reshape_moe_column_parallel_linear.h"
#include "ppl/nn/common/logger.h"

using namespace std;
using namespace ppl::common;

namespace ppl { namespace nn { namespace llm { namespace cuda { namespace opmx {

RetCode MoeColumnParallelLinearOp::CommonInit() {
    infer_type_and_format_func_ = GenericInferTypeAndFormat;
    infer_dims_func_ = [this](InputOutputInfo* info) -> RetCode {
        return ppl::nn::opmx::ReshapeMoeColumnParallelLinear(info, param_.get(), nccl_param_->size);
    };
    return RC_SUCCESS;
}

RetCode MoeColumnParallelLinearOp::DoInit(const OptKernelOptions& options) {
    auto status = GenericLoadParam<ppl::nn::opmx::MoeColumnParallelLinearParam>(options, &param_);
    if (status != RC_SUCCESS) {
        LOG(ERROR) << "GenericLoadParam failed: " << GetRetCodeStr(status);
        return status;
    }
    nccl_param_ = options.device->GetTensorParallelNcclParam();

    return CommonInit();
}

KernelImpl* MoeColumnParallelLinearOp::CreateKernelImpl() const {
    return CreateKernelImplWithParam<MoeColumnParallelLinearKernel>(param_.get());
}

}}}}} // namespace ppl::nn::llm::cuda::opmx
