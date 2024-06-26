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

#include "moe_select_kernel.h"

#include "ppl/common/destructor.h"
#include "ppl/kernel/llm/cuda/pmx/moe_select.h"

#include <iostream>

namespace ppl { namespace nn { namespace llm { namespace cuda { namespace opmx {

ppl::common::RetCode MoeSelectKernel::DoExecute(KernelExecContext* ctx) {

    PPLNN_LLM_CUDA_DEBUG_TRACE("Entry LlmCudaKernel: [%s]\n", GetName().c_str());

    PPLNN_LLM_CUDA_REQUIRED_INPUT(x, 0);
    PPLNN_LLM_CUDA_REQUIRED_INPUT(scores, 1);

    PPLNN_LLM_CUDA_REQUIRED_OUTPUT(x_expand_permute, 0);
    PPLNN_LLM_CUDA_REQUIRED_OUTPUT(expert_weights, 1);
    PPLNN_LLM_CUDA_REQUIRED_OUTPUT(invert_permutation, 2);
    PPLNN_LLM_CUDA_REQUIRED_OUTPUT(expert_offset, 3);

    PPLNN_LLM_CUDA_DEBUG_TRACE("Input [x]:\n");
    PPLNN_LLM_CUDA_TENSOR_PRINT_DEBUG_MSG(x);
    PPLNN_LLM_CUDA_DEBUG_TRACE("Input [scores]:\n");
    PPLNN_LLM_CUDA_TENSOR_PRINT_DEBUG_MSG(scores);

    PPLNN_LLM_CUDA_DEBUG_TRACE("num_experts: %d\n", param_->num_experts);
    PPLNN_LLM_CUDA_DEBUG_TRACE("num_experts_per_token: %d\n", param_->num_experts_per_token);

    PPLNN_LLM_CUDA_RESHAPE_OUTPUTS();

    PPLNN_LLM_CUDA_REALLOC_TENSOR_BUFFER(x_expand_permute);
    PPLNN_LLM_CUDA_DEBUG_TRACE("Output [x_expand_permute]:\n");
    PPLNN_LLM_CUDA_TENSOR_PRINT_DEBUG_MSG(x_expand_permute);

    PPLNN_LLM_CUDA_REALLOC_TENSOR_BUFFER(expert_weights);
    PPLNN_LLM_CUDA_DEBUG_TRACE("Output [expert_weights]:\n");
    PPLNN_LLM_CUDA_TENSOR_PRINT_DEBUG_MSG(expert_weights);

    PPLNN_LLM_CUDA_REALLOC_TENSOR_BUFFER(invert_permutation);
    PPLNN_LLM_CUDA_DEBUG_TRACE("Output [invert_permutation]:\n");
    PPLNN_LLM_CUDA_TENSOR_PRINT_DEBUG_MSG(invert_permutation);

    PPLNN_LLM_CUDA_REALLOC_TENSOR_HOST_BUFFER(expert_offset);
    PPLNN_LLM_CUDA_DEBUG_TRACE("Output [expert_offset]:\n");
    PPLNN_LLM_CUDA_TENSOR_PRINT_DEBUG_MSG(expert_offset);

    auto x_shape = x->GetShape();
    auto scores_shape = scores->GetShape();
    
    if (ppl::common::DATATYPE_FLOAT16 != x_shape->GetDataType()) {
        LOG(ERROR) << "currently only support fp16";
        return ppl::common::RC_UNSUPPORTED;
    }

    void* temp_buffer = nullptr;
    auto config = ppl::kernel::llm::cuda::pmx::moe_select_prepare(
        invert_permutation->GetShape(), param_->num_experts);
    config.temp_buffer_size = (config.temp_buffer_size +  8 - 1) / 8 * 8;   // padding to 8 bytes

    BufferDesc tmp_buffer_desc;
    int64_t temp_buffer_size = config.temp_buffer_size + expert_offset->GetShape()->CalcBytesExcludingPadding();

    auto status = GetCudaDevice()->AllocTmpBuffer(temp_buffer_size, &tmp_buffer_desc);
    if (status != ppl::common::RC_SUCCESS) {
        LOG(ERROR) << "alloc tmp buffer size[" << temp_buffer_size << "] for kernel[" << GetName()
                << "] failed: " << ppl::common::GetRetCodeStr(status);
        return status;
    }
    ppl::common::Destructor __tmp_buffer_guard([this, &tmp_buffer_desc]() -> void {
        GetCudaDevice()->FreeTmpBuffer(&tmp_buffer_desc);
    });

    temp_buffer = tmp_buffer_desc.addr;

    void* expert_offset_device_ptr = (void*)((char*)temp_buffer + config.temp_buffer_size);

    status = ppl::kernel::llm::cuda::pmx::moe_select(
        GetStream(),
        x_shape,
        x->GetBufferPtr(),
        scores_shape,
        scores->GetBufferPtr(),
        param_->num_experts,
        param_->num_experts_per_token,
        config,
        temp_buffer,
        x_expand_permute->GetBufferPtr(),
        expert_weights->GetBufferPtr(),
        invert_permutation->GetBufferPtr(),
        expert_offset_device_ptr
    );

    if (status != ppl::common::RC_SUCCESS) {
        LOG(ERROR) << "kernel[" << GetName() << "] failed: " << ppl::common::GetRetCodeStr(status);
        return status;
    }

    const BufferDesc expert_offset_desc(expert_offset_device_ptr);
    status = GetCudaDevice()->CopyToHost(
        expert_offset->GetBufferPtr(), expert_offset_desc, *expert_offset->GetShape());
    if (status != ppl::common::RC_SUCCESS) {
        LOG(ERROR) << "copy expert offset to host failed for kernel[" << GetName()
                << "] failed: " << ppl::common::GetRetCodeStr(status);
        return status;
    }

    return ppl::common::RC_SUCCESS;

}

}}}}}
