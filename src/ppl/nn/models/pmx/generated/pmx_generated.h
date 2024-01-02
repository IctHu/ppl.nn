// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_PMX_PPL_NN_PMX_H_
#define FLATBUFFERS_GENERATED_PMX_PPL_NN_PMX_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 2 &&
              FLATBUFFERS_VERSION_MINOR == 0 &&
              FLATBUFFERS_VERSION_REVISION == 8,
             "Non-compatible flatbuffers version included");

#include "types_generated.h"

namespace ppl {
namespace nn {
namespace pmx {

struct Edge;
struct EdgeBuilder;

struct NodeType;
struct NodeTypeBuilder;

struct Node;
struct NodeBuilder;

struct GraphTopo;
struct GraphTopoBuilder;

struct NodeInfo;
struct NodeInfoBuilder;

struct Constant;
struct ConstantBuilder;

struct Shape;
struct ShapeBuilder;

struct Partition;
struct PartitionBuilder;

struct GraphData;
struct GraphDataBuilder;

struct Graph;
struct GraphBuilder;

struct Engine;
struct EngineBuilder;

struct Model;
struct ModelBuilder;

enum ConstantFlag : uint32_t {
  ConstantFlag_EXTERNAL_DATA = 1,
  ConstantFlag_MIN = ConstantFlag_EXTERNAL_DATA,
  ConstantFlag_MAX = ConstantFlag_EXTERNAL_DATA
};

inline const ConstantFlag (&EnumValuesConstantFlag())[1] {
  static const ConstantFlag values[] = {
    ConstantFlag_EXTERNAL_DATA
  };
  return values;
}

inline const char * const *EnumNamesConstantFlag() {
  static const char * const names[2] = {
    "EXTERNAL_DATA",
    nullptr
  };
  return names;
}

inline const char *EnumNameConstantFlag(ConstantFlag e) {
  if (flatbuffers::IsOutRange(e, ConstantFlag_EXTERNAL_DATA, ConstantFlag_EXTERNAL_DATA)) return "";
  const size_t index = static_cast<size_t>(e) - static_cast<size_t>(ConstantFlag_EXTERNAL_DATA);
  return EnumNamesConstantFlag()[index];
}

struct Edge FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef EdgeBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NAME = 4
  };
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           verifier.EndTable();
  }
};

struct EdgeBuilder {
  typedef Edge Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(Edge::VT_NAME, name);
  }
  explicit EdgeBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Edge> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Edge>(end);
    return o;
  }
};

inline flatbuffers::Offset<Edge> CreateEdge(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0) {
  EdgeBuilder builder_(_fbb);
  builder_.add_name(name);
  return builder_.Finish();
}

inline flatbuffers::Offset<Edge> CreateEdgeDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  return ppl::nn::pmx::CreateEdge(
      _fbb,
      name__);
}

struct NodeType FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef NodeTypeBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_DOMAIN = 4,
    VT_NAME = 6,
    VT_VERSION = 8
  };
  const flatbuffers::String *domain() const {
    return GetPointer<const flatbuffers::String *>(VT_DOMAIN);
  }
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  uint32_t version() const {
    return GetField<uint32_t>(VT_VERSION, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_DOMAIN) &&
           verifier.VerifyString(domain()) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyField<uint32_t>(verifier, VT_VERSION, 4) &&
           verifier.EndTable();
  }
};

struct NodeTypeBuilder {
  typedef NodeType Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_domain(flatbuffers::Offset<flatbuffers::String> domain) {
    fbb_.AddOffset(NodeType::VT_DOMAIN, domain);
  }
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(NodeType::VT_NAME, name);
  }
  void add_version(uint32_t version) {
    fbb_.AddElement<uint32_t>(NodeType::VT_VERSION, version, 0);
  }
  explicit NodeTypeBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<NodeType> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<NodeType>(end);
    return o;
  }
};

inline flatbuffers::Offset<NodeType> CreateNodeType(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> domain = 0,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    uint32_t version = 0) {
  NodeTypeBuilder builder_(_fbb);
  builder_.add_version(version);
  builder_.add_name(name);
  builder_.add_domain(domain);
  return builder_.Finish();
}

inline flatbuffers::Offset<NodeType> CreateNodeTypeDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *domain = nullptr,
    const char *name = nullptr,
    uint32_t version = 0) {
  auto domain__ = domain ? _fbb.CreateString(domain) : 0;
  auto name__ = name ? _fbb.CreateString(name) : 0;
  return ppl::nn::pmx::CreateNodeType(
      _fbb,
      domain__,
      name__,
      version);
}

struct Node FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef NodeBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NAME = 4,
    VT_TYPE = 6,
    VT_INPUTS = 8,
    VT_OUTPUTS = 10,
    VT_EXTRA_INPUTS = 12
  };
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  const ppl::nn::pmx::NodeType *type() const {
    return GetPointer<const ppl::nn::pmx::NodeType *>(VT_TYPE);
  }
  const flatbuffers::Vector<uint32_t> *inputs() const {
    return GetPointer<const flatbuffers::Vector<uint32_t> *>(VT_INPUTS);
  }
  const flatbuffers::Vector<uint32_t> *outputs() const {
    return GetPointer<const flatbuffers::Vector<uint32_t> *>(VT_OUTPUTS);
  }
  const flatbuffers::Vector<uint32_t> *extra_inputs() const {
    return GetPointer<const flatbuffers::Vector<uint32_t> *>(VT_EXTRA_INPUTS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyOffset(verifier, VT_TYPE) &&
           verifier.VerifyTable(type()) &&
           VerifyOffset(verifier, VT_INPUTS) &&
           verifier.VerifyVector(inputs()) &&
           VerifyOffset(verifier, VT_OUTPUTS) &&
           verifier.VerifyVector(outputs()) &&
           VerifyOffset(verifier, VT_EXTRA_INPUTS) &&
           verifier.VerifyVector(extra_inputs()) &&
           verifier.EndTable();
  }
};

struct NodeBuilder {
  typedef Node Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(Node::VT_NAME, name);
  }
  void add_type(flatbuffers::Offset<ppl::nn::pmx::NodeType> type) {
    fbb_.AddOffset(Node::VT_TYPE, type);
  }
  void add_inputs(flatbuffers::Offset<flatbuffers::Vector<uint32_t>> inputs) {
    fbb_.AddOffset(Node::VT_INPUTS, inputs);
  }
  void add_outputs(flatbuffers::Offset<flatbuffers::Vector<uint32_t>> outputs) {
    fbb_.AddOffset(Node::VT_OUTPUTS, outputs);
  }
  void add_extra_inputs(flatbuffers::Offset<flatbuffers::Vector<uint32_t>> extra_inputs) {
    fbb_.AddOffset(Node::VT_EXTRA_INPUTS, extra_inputs);
  }
  explicit NodeBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Node> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Node>(end);
    return o;
  }
};

inline flatbuffers::Offset<Node> CreateNode(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    flatbuffers::Offset<ppl::nn::pmx::NodeType> type = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint32_t>> inputs = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint32_t>> outputs = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint32_t>> extra_inputs = 0) {
  NodeBuilder builder_(_fbb);
  builder_.add_extra_inputs(extra_inputs);
  builder_.add_outputs(outputs);
  builder_.add_inputs(inputs);
  builder_.add_type(type);
  builder_.add_name(name);
  return builder_.Finish();
}

inline flatbuffers::Offset<Node> CreateNodeDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    flatbuffers::Offset<ppl::nn::pmx::NodeType> type = 0,
    const std::vector<uint32_t> *inputs = nullptr,
    const std::vector<uint32_t> *outputs = nullptr,
    const std::vector<uint32_t> *extra_inputs = nullptr) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  auto inputs__ = inputs ? _fbb.CreateVector<uint32_t>(*inputs) : 0;
  auto outputs__ = outputs ? _fbb.CreateVector<uint32_t>(*outputs) : 0;
  auto extra_inputs__ = extra_inputs ? _fbb.CreateVector<uint32_t>(*extra_inputs) : 0;
  return ppl::nn::pmx::CreateNode(
      _fbb,
      name__,
      type,
      inputs__,
      outputs__,
      extra_inputs__);
}

struct GraphTopo FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef GraphTopoBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NAME = 4,
    VT_EDGES = 6,
    VT_NODES = 8,
    VT_CONSTANTS = 10,
    VT_INPUTS = 12,
    VT_OUTPUTS = 14,
    VT_EXTRA_INPUTS = 16
  };
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  const flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Edge>> *edges() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Edge>> *>(VT_EDGES);
  }
  const flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Node>> *nodes() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Node>> *>(VT_NODES);
  }
  const flatbuffers::Vector<uint32_t> *constants() const {
    return GetPointer<const flatbuffers::Vector<uint32_t> *>(VT_CONSTANTS);
  }
  const flatbuffers::Vector<uint32_t> *inputs() const {
    return GetPointer<const flatbuffers::Vector<uint32_t> *>(VT_INPUTS);
  }
  const flatbuffers::Vector<uint32_t> *outputs() const {
    return GetPointer<const flatbuffers::Vector<uint32_t> *>(VT_OUTPUTS);
  }
  const flatbuffers::Vector<uint32_t> *extra_inputs() const {
    return GetPointer<const flatbuffers::Vector<uint32_t> *>(VT_EXTRA_INPUTS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyOffset(verifier, VT_EDGES) &&
           verifier.VerifyVector(edges()) &&
           verifier.VerifyVectorOfTables(edges()) &&
           VerifyOffset(verifier, VT_NODES) &&
           verifier.VerifyVector(nodes()) &&
           verifier.VerifyVectorOfTables(nodes()) &&
           VerifyOffset(verifier, VT_CONSTANTS) &&
           verifier.VerifyVector(constants()) &&
           VerifyOffset(verifier, VT_INPUTS) &&
           verifier.VerifyVector(inputs()) &&
           VerifyOffset(verifier, VT_OUTPUTS) &&
           verifier.VerifyVector(outputs()) &&
           VerifyOffset(verifier, VT_EXTRA_INPUTS) &&
           verifier.VerifyVector(extra_inputs()) &&
           verifier.EndTable();
  }
};

struct GraphTopoBuilder {
  typedef GraphTopo Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(GraphTopo::VT_NAME, name);
  }
  void add_edges(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Edge>>> edges) {
    fbb_.AddOffset(GraphTopo::VT_EDGES, edges);
  }
  void add_nodes(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Node>>> nodes) {
    fbb_.AddOffset(GraphTopo::VT_NODES, nodes);
  }
  void add_constants(flatbuffers::Offset<flatbuffers::Vector<uint32_t>> constants) {
    fbb_.AddOffset(GraphTopo::VT_CONSTANTS, constants);
  }
  void add_inputs(flatbuffers::Offset<flatbuffers::Vector<uint32_t>> inputs) {
    fbb_.AddOffset(GraphTopo::VT_INPUTS, inputs);
  }
  void add_outputs(flatbuffers::Offset<flatbuffers::Vector<uint32_t>> outputs) {
    fbb_.AddOffset(GraphTopo::VT_OUTPUTS, outputs);
  }
  void add_extra_inputs(flatbuffers::Offset<flatbuffers::Vector<uint32_t>> extra_inputs) {
    fbb_.AddOffset(GraphTopo::VT_EXTRA_INPUTS, extra_inputs);
  }
  explicit GraphTopoBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<GraphTopo> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<GraphTopo>(end);
    return o;
  }
};

inline flatbuffers::Offset<GraphTopo> CreateGraphTopo(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Edge>>> edges = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Node>>> nodes = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint32_t>> constants = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint32_t>> inputs = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint32_t>> outputs = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint32_t>> extra_inputs = 0) {
  GraphTopoBuilder builder_(_fbb);
  builder_.add_extra_inputs(extra_inputs);
  builder_.add_outputs(outputs);
  builder_.add_inputs(inputs);
  builder_.add_constants(constants);
  builder_.add_nodes(nodes);
  builder_.add_edges(edges);
  builder_.add_name(name);
  return builder_.Finish();
}

inline flatbuffers::Offset<GraphTopo> CreateGraphTopoDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    const std::vector<flatbuffers::Offset<ppl::nn::pmx::Edge>> *edges = nullptr,
    const std::vector<flatbuffers::Offset<ppl::nn::pmx::Node>> *nodes = nullptr,
    const std::vector<uint32_t> *constants = nullptr,
    const std::vector<uint32_t> *inputs = nullptr,
    const std::vector<uint32_t> *outputs = nullptr,
    const std::vector<uint32_t> *extra_inputs = nullptr) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  auto edges__ = edges ? _fbb.CreateVector<flatbuffers::Offset<ppl::nn::pmx::Edge>>(*edges) : 0;
  auto nodes__ = nodes ? _fbb.CreateVector<flatbuffers::Offset<ppl::nn::pmx::Node>>(*nodes) : 0;
  auto constants__ = constants ? _fbb.CreateVector<uint32_t>(*constants) : 0;
  auto inputs__ = inputs ? _fbb.CreateVector<uint32_t>(*inputs) : 0;
  auto outputs__ = outputs ? _fbb.CreateVector<uint32_t>(*outputs) : 0;
  auto extra_inputs__ = extra_inputs ? _fbb.CreateVector<uint32_t>(*extra_inputs) : 0;
  return ppl::nn::pmx::CreateGraphTopo(
      _fbb,
      name__,
      edges__,
      nodes__,
      constants__,
      inputs__,
      outputs__,
      extra_inputs__);
}

struct NodeInfo FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef NodeInfoBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NODE_ID = 4,
    VT_DATA = 6
  };
  uint32_t node_id() const {
    return GetField<uint32_t>(VT_NODE_ID, 0);
  }
  const flatbuffers::Vector<uint8_t> *data() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_DATA);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_NODE_ID, 4) &&
           VerifyOffset(verifier, VT_DATA) &&
           verifier.VerifyVector(data()) &&
           verifier.EndTable();
  }
};

struct NodeInfoBuilder {
  typedef NodeInfo Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_node_id(uint32_t node_id) {
    fbb_.AddElement<uint32_t>(NodeInfo::VT_NODE_ID, node_id, 0);
  }
  void add_data(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data) {
    fbb_.AddOffset(NodeInfo::VT_DATA, data);
  }
  explicit NodeInfoBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<NodeInfo> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<NodeInfo>(end);
    return o;
  }
};

inline flatbuffers::Offset<NodeInfo> CreateNodeInfo(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t node_id = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data = 0) {
  NodeInfoBuilder builder_(_fbb);
  builder_.add_data(data);
  builder_.add_node_id(node_id);
  return builder_.Finish();
}

inline flatbuffers::Offset<NodeInfo> CreateNodeInfoDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t node_id = 0,
    const std::vector<uint8_t> *data = nullptr) {
  auto data__ = data ? _fbb.CreateVector<uint8_t>(*data) : 0;
  return ppl::nn::pmx::CreateNodeInfo(
      _fbb,
      node_id,
      data__);
}

struct Constant FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ConstantBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_EDGE_ID = 4,
    VT_FLAGS = 6,
    VT_DATA_OFFSET = 8,
    VT_DATA_BYTES = 10
  };
  uint32_t edge_id() const {
    return GetField<uint32_t>(VT_EDGE_ID, 0);
  }
  uint32_t flags() const {
    return GetField<uint32_t>(VT_FLAGS, 0);
  }
  uint64_t data_offset() const {
    return GetField<uint64_t>(VT_DATA_OFFSET, 0);
  }
  uint64_t data_bytes() const {
    return GetField<uint64_t>(VT_DATA_BYTES, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_EDGE_ID, 4) &&
           VerifyField<uint32_t>(verifier, VT_FLAGS, 4) &&
           VerifyField<uint64_t>(verifier, VT_DATA_OFFSET, 8) &&
           VerifyField<uint64_t>(verifier, VT_DATA_BYTES, 8) &&
           verifier.EndTable();
  }
};

struct ConstantBuilder {
  typedef Constant Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_edge_id(uint32_t edge_id) {
    fbb_.AddElement<uint32_t>(Constant::VT_EDGE_ID, edge_id, 0);
  }
  void add_flags(uint32_t flags) {
    fbb_.AddElement<uint32_t>(Constant::VT_FLAGS, flags, 0);
  }
  void add_data_offset(uint64_t data_offset) {
    fbb_.AddElement<uint64_t>(Constant::VT_DATA_OFFSET, data_offset, 0);
  }
  void add_data_bytes(uint64_t data_bytes) {
    fbb_.AddElement<uint64_t>(Constant::VT_DATA_BYTES, data_bytes, 0);
  }
  explicit ConstantBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Constant> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Constant>(end);
    return o;
  }
};

inline flatbuffers::Offset<Constant> CreateConstant(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t edge_id = 0,
    uint32_t flags = 0,
    uint64_t data_offset = 0,
    uint64_t data_bytes = 0) {
  ConstantBuilder builder_(_fbb);
  builder_.add_data_bytes(data_bytes);
  builder_.add_data_offset(data_offset);
  builder_.add_flags(flags);
  builder_.add_edge_id(edge_id);
  return builder_.Finish();
}

struct Shape FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ShapeBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_EDGE_ID = 4,
    VT_DATA_TYPE = 6,
    VT_DATA_FORMAT = 8,
    VT_DIMS = 10
  };
  uint32_t edge_id() const {
    return GetField<uint32_t>(VT_EDGE_ID, 0);
  }
  ppl::nn::pmx::DataType data_type() const {
    return static_cast<ppl::nn::pmx::DataType>(GetField<uint32_t>(VT_DATA_TYPE, 0));
  }
  ppl::nn::pmx::DataFormat data_format() const {
    return static_cast<ppl::nn::pmx::DataFormat>(GetField<uint32_t>(VT_DATA_FORMAT, 0));
  }
  const flatbuffers::Vector<int64_t> *dims() const {
    return GetPointer<const flatbuffers::Vector<int64_t> *>(VT_DIMS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_EDGE_ID, 4) &&
           VerifyField<uint32_t>(verifier, VT_DATA_TYPE, 4) &&
           VerifyField<uint32_t>(verifier, VT_DATA_FORMAT, 4) &&
           VerifyOffset(verifier, VT_DIMS) &&
           verifier.VerifyVector(dims()) &&
           verifier.EndTable();
  }
};

struct ShapeBuilder {
  typedef Shape Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_edge_id(uint32_t edge_id) {
    fbb_.AddElement<uint32_t>(Shape::VT_EDGE_ID, edge_id, 0);
  }
  void add_data_type(ppl::nn::pmx::DataType data_type) {
    fbb_.AddElement<uint32_t>(Shape::VT_DATA_TYPE, static_cast<uint32_t>(data_type), 0);
  }
  void add_data_format(ppl::nn::pmx::DataFormat data_format) {
    fbb_.AddElement<uint32_t>(Shape::VT_DATA_FORMAT, static_cast<uint32_t>(data_format), 0);
  }
  void add_dims(flatbuffers::Offset<flatbuffers::Vector<int64_t>> dims) {
    fbb_.AddOffset(Shape::VT_DIMS, dims);
  }
  explicit ShapeBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Shape> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Shape>(end);
    return o;
  }
};

inline flatbuffers::Offset<Shape> CreateShape(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t edge_id = 0,
    ppl::nn::pmx::DataType data_type = ppl::nn::pmx::DataType_UNKNOWN,
    ppl::nn::pmx::DataFormat data_format = ppl::nn::pmx::DataFormat_UNKNOWN,
    flatbuffers::Offset<flatbuffers::Vector<int64_t>> dims = 0) {
  ShapeBuilder builder_(_fbb);
  builder_.add_dims(dims);
  builder_.add_data_format(data_format);
  builder_.add_data_type(data_type);
  builder_.add_edge_id(edge_id);
  return builder_.Finish();
}

inline flatbuffers::Offset<Shape> CreateShapeDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t edge_id = 0,
    ppl::nn::pmx::DataType data_type = ppl::nn::pmx::DataType_UNKNOWN,
    ppl::nn::pmx::DataFormat data_format = ppl::nn::pmx::DataFormat_UNKNOWN,
    const std::vector<int64_t> *dims = nullptr) {
  auto dims__ = dims ? _fbb.CreateVector<int64_t>(*dims) : 0;
  return ppl::nn::pmx::CreateShape(
      _fbb,
      edge_id,
      data_type,
      data_format,
      dims__);
}

struct Partition FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef PartitionBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ENGINE_ID = 4,
    VT_NODES = 6,
    VT_CONSTANTS = 8
  };
  uint32_t engine_id() const {
    return GetField<uint32_t>(VT_ENGINE_ID, 0);
  }
  const flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::NodeInfo>> *nodes() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::NodeInfo>> *>(VT_NODES);
  }
  const flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Constant>> *constants() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Constant>> *>(VT_CONSTANTS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_ENGINE_ID, 4) &&
           VerifyOffset(verifier, VT_NODES) &&
           verifier.VerifyVector(nodes()) &&
           verifier.VerifyVectorOfTables(nodes()) &&
           VerifyOffset(verifier, VT_CONSTANTS) &&
           verifier.VerifyVector(constants()) &&
           verifier.VerifyVectorOfTables(constants()) &&
           verifier.EndTable();
  }
};

struct PartitionBuilder {
  typedef Partition Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_engine_id(uint32_t engine_id) {
    fbb_.AddElement<uint32_t>(Partition::VT_ENGINE_ID, engine_id, 0);
  }
  void add_nodes(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::NodeInfo>>> nodes) {
    fbb_.AddOffset(Partition::VT_NODES, nodes);
  }
  void add_constants(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Constant>>> constants) {
    fbb_.AddOffset(Partition::VT_CONSTANTS, constants);
  }
  explicit PartitionBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Partition> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Partition>(end);
    return o;
  }
};

inline flatbuffers::Offset<Partition> CreatePartition(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t engine_id = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::NodeInfo>>> nodes = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Constant>>> constants = 0) {
  PartitionBuilder builder_(_fbb);
  builder_.add_constants(constants);
  builder_.add_nodes(nodes);
  builder_.add_engine_id(engine_id);
  return builder_.Finish();
}

inline flatbuffers::Offset<Partition> CreatePartitionDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t engine_id = 0,
    const std::vector<flatbuffers::Offset<ppl::nn::pmx::NodeInfo>> *nodes = nullptr,
    const std::vector<flatbuffers::Offset<ppl::nn::pmx::Constant>> *constants = nullptr) {
  auto nodes__ = nodes ? _fbb.CreateVector<flatbuffers::Offset<ppl::nn::pmx::NodeInfo>>(*nodes) : 0;
  auto constants__ = constants ? _fbb.CreateVector<flatbuffers::Offset<ppl::nn::pmx::Constant>>(*constants) : 0;
  return ppl::nn::pmx::CreatePartition(
      _fbb,
      engine_id,
      nodes__,
      constants__);
}

struct GraphData FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef GraphDataBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_SHAPES = 4,
    VT_PARTITIONS = 6,
    VT_SHARED_DATA = 8
  };
  const flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Shape>> *shapes() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Shape>> *>(VT_SHAPES);
  }
  const flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Partition>> *partitions() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Partition>> *>(VT_PARTITIONS);
  }
  const flatbuffers::Vector<uint8_t> *shared_data() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_SHARED_DATA);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_SHAPES) &&
           verifier.VerifyVector(shapes()) &&
           verifier.VerifyVectorOfTables(shapes()) &&
           VerifyOffset(verifier, VT_PARTITIONS) &&
           verifier.VerifyVector(partitions()) &&
           verifier.VerifyVectorOfTables(partitions()) &&
           VerifyOffset(verifier, VT_SHARED_DATA) &&
           verifier.VerifyVector(shared_data()) &&
           verifier.EndTable();
  }
};

struct GraphDataBuilder {
  typedef GraphData Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_shapes(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Shape>>> shapes) {
    fbb_.AddOffset(GraphData::VT_SHAPES, shapes);
  }
  void add_partitions(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Partition>>> partitions) {
    fbb_.AddOffset(GraphData::VT_PARTITIONS, partitions);
  }
  void add_shared_data(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> shared_data) {
    fbb_.AddOffset(GraphData::VT_SHARED_DATA, shared_data);
  }
  explicit GraphDataBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<GraphData> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<GraphData>(end);
    return o;
  }
};

inline flatbuffers::Offset<GraphData> CreateGraphData(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Shape>>> shapes = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Partition>>> partitions = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> shared_data = 0) {
  GraphDataBuilder builder_(_fbb);
  builder_.add_shared_data(shared_data);
  builder_.add_partitions(partitions);
  builder_.add_shapes(shapes);
  return builder_.Finish();
}

inline flatbuffers::Offset<GraphData> CreateGraphDataDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<ppl::nn::pmx::Shape>> *shapes = nullptr,
    const std::vector<flatbuffers::Offset<ppl::nn::pmx::Partition>> *partitions = nullptr,
    const std::vector<uint8_t> *shared_data = nullptr) {
  auto shapes__ = shapes ? _fbb.CreateVector<flatbuffers::Offset<ppl::nn::pmx::Shape>>(*shapes) : 0;
  auto partitions__ = partitions ? _fbb.CreateVector<flatbuffers::Offset<ppl::nn::pmx::Partition>>(*partitions) : 0;
  auto shared_data__ = shared_data ? _fbb.CreateVector<uint8_t>(*shared_data) : 0;
  return ppl::nn::pmx::CreateGraphData(
      _fbb,
      shapes__,
      partitions__,
      shared_data__);
}

struct Graph FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef GraphBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TOPO = 4,
    VT_DATA = 6
  };
  const ppl::nn::pmx::GraphTopo *topo() const {
    return GetPointer<const ppl::nn::pmx::GraphTopo *>(VT_TOPO);
  }
  const ppl::nn::pmx::GraphData *data() const {
    return GetPointer<const ppl::nn::pmx::GraphData *>(VT_DATA);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_TOPO) &&
           verifier.VerifyTable(topo()) &&
           VerifyOffset(verifier, VT_DATA) &&
           verifier.VerifyTable(data()) &&
           verifier.EndTable();
  }
};

struct GraphBuilder {
  typedef Graph Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_topo(flatbuffers::Offset<ppl::nn::pmx::GraphTopo> topo) {
    fbb_.AddOffset(Graph::VT_TOPO, topo);
  }
  void add_data(flatbuffers::Offset<ppl::nn::pmx::GraphData> data) {
    fbb_.AddOffset(Graph::VT_DATA, data);
  }
  explicit GraphBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Graph> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Graph>(end);
    return o;
  }
};

inline flatbuffers::Offset<Graph> CreateGraph(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<ppl::nn::pmx::GraphTopo> topo = 0,
    flatbuffers::Offset<ppl::nn::pmx::GraphData> data = 0) {
  GraphBuilder builder_(_fbb);
  builder_.add_data(data);
  builder_.add_topo(topo);
  return builder_.Finish();
}

struct Engine FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef EngineBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NAME = 4,
    VT_DATA = 6
  };
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  const flatbuffers::Vector<uint8_t> *data() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_DATA);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyOffset(verifier, VT_DATA) &&
           verifier.VerifyVector(data()) &&
           verifier.EndTable();
  }
};

struct EngineBuilder {
  typedef Engine Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(Engine::VT_NAME, name);
  }
  void add_data(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data) {
    fbb_.AddOffset(Engine::VT_DATA, data);
  }
  explicit EngineBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Engine> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Engine>(end);
    return o;
  }
};

inline flatbuffers::Offset<Engine> CreateEngine(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data = 0) {
  EngineBuilder builder_(_fbb);
  builder_.add_data(data);
  builder_.add_name(name);
  return builder_.Finish();
}

inline flatbuffers::Offset<Engine> CreateEngineDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    const std::vector<uint8_t> *data = nullptr) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  auto data__ = data ? _fbb.CreateVector<uint8_t>(*data) : 0;
  return ppl::nn::pmx::CreateEngine(
      _fbb,
      name__,
      data__);
}

struct Model FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ModelBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_VERSION = 4,
    VT_ENGINES = 6,
    VT_GRAPH = 8,
    VT_PRODUCER = 10
  };
  uint32_t version() const {
    return GetField<uint32_t>(VT_VERSION, 0);
  }
  const flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Engine>> *engines() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Engine>> *>(VT_ENGINES);
  }
  const ppl::nn::pmx::Graph *graph() const {
    return GetPointer<const ppl::nn::pmx::Graph *>(VT_GRAPH);
  }
  const flatbuffers::String *producer() const {
    return GetPointer<const flatbuffers::String *>(VT_PRODUCER);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_VERSION, 4) &&
           VerifyOffset(verifier, VT_ENGINES) &&
           verifier.VerifyVector(engines()) &&
           verifier.VerifyVectorOfTables(engines()) &&
           VerifyOffset(verifier, VT_GRAPH) &&
           verifier.VerifyTable(graph()) &&
           VerifyOffset(verifier, VT_PRODUCER) &&
           verifier.VerifyString(producer()) &&
           verifier.EndTable();
  }
};

struct ModelBuilder {
  typedef Model Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_version(uint32_t version) {
    fbb_.AddElement<uint32_t>(Model::VT_VERSION, version, 0);
  }
  void add_engines(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Engine>>> engines) {
    fbb_.AddOffset(Model::VT_ENGINES, engines);
  }
  void add_graph(flatbuffers::Offset<ppl::nn::pmx::Graph> graph) {
    fbb_.AddOffset(Model::VT_GRAPH, graph);
  }
  void add_producer(flatbuffers::Offset<flatbuffers::String> producer) {
    fbb_.AddOffset(Model::VT_PRODUCER, producer);
  }
  explicit ModelBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Model> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Model>(end);
    return o;
  }
};

inline flatbuffers::Offset<Model> CreateModel(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t version = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ppl::nn::pmx::Engine>>> engines = 0,
    flatbuffers::Offset<ppl::nn::pmx::Graph> graph = 0,
    flatbuffers::Offset<flatbuffers::String> producer = 0) {
  ModelBuilder builder_(_fbb);
  builder_.add_producer(producer);
  builder_.add_graph(graph);
  builder_.add_engines(engines);
  builder_.add_version(version);
  return builder_.Finish();
}

inline flatbuffers::Offset<Model> CreateModelDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t version = 0,
    const std::vector<flatbuffers::Offset<ppl::nn::pmx::Engine>> *engines = nullptr,
    flatbuffers::Offset<ppl::nn::pmx::Graph> graph = 0,
    const char *producer = nullptr) {
  auto engines__ = engines ? _fbb.CreateVector<flatbuffers::Offset<ppl::nn::pmx::Engine>>(*engines) : 0;
  auto producer__ = producer ? _fbb.CreateString(producer) : 0;
  return ppl::nn::pmx::CreateModel(
      _fbb,
      version,
      engines__,
      graph,
      producer__);
}

inline const ppl::nn::pmx::Model *GetModel(const void *buf) {
  return flatbuffers::GetRoot<ppl::nn::pmx::Model>(buf);
}

inline const ppl::nn::pmx::Model *GetSizePrefixedModel(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<ppl::nn::pmx::Model>(buf);
}

inline const char *ModelIdentifier() {
  return "OPMX";
}

inline bool ModelBufferHasIdentifier(const void *buf) {
  return flatbuffers::BufferHasIdentifier(
      buf, ModelIdentifier());
}

inline bool SizePrefixedModelBufferHasIdentifier(const void *buf) {
  return flatbuffers::BufferHasIdentifier(
      buf, ModelIdentifier(), true);
}

inline bool VerifyModelBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<ppl::nn::pmx::Model>(ModelIdentifier());
}

inline bool VerifySizePrefixedModelBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<ppl::nn::pmx::Model>(ModelIdentifier());
}

inline void FinishModelBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<ppl::nn::pmx::Model> root) {
  fbb.Finish(root, ModelIdentifier());
}

inline void FinishSizePrefixedModelBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<ppl::nn::pmx::Model> root) {
  fbb.FinishSizePrefixed(root, ModelIdentifier());
}

}  // namespace pmx
}  // namespace nn
}  // namespace ppl

#endif  // FLATBUFFERS_GENERATED_PMX_PPL_NN_PMX_H_
