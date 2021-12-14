#include <iostream>

#define LANTERN_BUILD

#include "lantern/lantern.h"

#include <torch/torch.h>

#include "utils.hpp"

void *_lantern_vector_int64_t(int64_t *x, size_t x_size)
{
  LANTERN_FUNCTION_START
  auto out = std::vector<int64_t>(x, x + x_size);
  return (void *)new LanternObject<std::vector<int64_t>>(out);
  LANTERN_FUNCTION_END
}

int64_t _lantern_vector_int64_t_size(void* self)
{
  LANTERN_FUNCTION_START
  return reinterpret_cast<std::vector<int64_t> *>(self)->size();
  LANTERN_FUNCTION_END
}

int64_t _lantern_vector_int64_t_at (void* self, int64_t index)
{
  return reinterpret_cast<std::vector<int64_t> *>(self)->at(index);
}

void *_lantern_vector_double(double *x, size_t x_size)
{
  LANTERN_FUNCTION_START
  auto out = std::vector<double>(x, x + x_size);
  return (void *)new LanternObject<std::vector<double>>(out);
  LANTERN_FUNCTION_END
}

void* _lantern_vector_double_new ()
{
  return (void *)new std::vector<double>();
}

void* _lantern_vector_int64_t_new ()
{
  return (void *)new std::vector<int64_t>();
}

void _lantern_vector_double_push_back(void* self, double x)
{
  reinterpret_cast<std::vector<double>*>(self)->push_back(x);
}

void _lantern_vector_int64_t_push_back(void* self, int64_t x)
{
  reinterpret_cast<std::vector<int64_t>*>(self)->push_back(x);
}

double _lantern_vector_double_size(void* self)
{
  LANTERN_FUNCTION_START
  return reinterpret_cast<std::vector<double> *>(self)->size();
  LANTERN_FUNCTION_END
}

double _lantern_vector_double_at (void* self, int64_t index)
{
  return reinterpret_cast<std::vector<double> *>(self)->at(index);
}

void * _lantern_optional_vector_double(double * x, size_t x_size, bool is_null)
{
  LANTERN_FUNCTION_START
  c10::optional<torch::ArrayRef<double>> out;
  
  if (is_null)
    out = c10::nullopt;
  else 
    out = torch::ArrayRef<double>(x, x + x_size);;
  
  return make_unique::optional::DoubleArrayRef(out);
  LANTERN_FUNCTION_END
}

void * _lantern_optional_vector_int64_t(int64_t * x, size_t x_size, bool is_null)
{
  LANTERN_FUNCTION_START
  c10::optional<torch::ArrayRef<int64_t>> out;

  if (is_null)
    out = c10::nullopt;
  else 
    out = torch::ArrayRef<int64_t>(x, x + x_size);

  return make_unique::optional::IntArrayRef(out);
  LANTERN_FUNCTION_END
}

void *_lantern_IntArrayRef(int64_t *x, size_t x_size)
{
  LANTERN_FUNCTION_START
  torch::IntArrayRef out = std::vector<int64_t>(x, x + x_size);
  return (void *)new LanternObject<torch::IntArrayRef>(out);
  LANTERN_FUNCTION_END
}

void *_lantern_int(int x)
{
  LANTERN_FUNCTION_START
  return (void *)new LanternObject<int>(x);
  LANTERN_FUNCTION_END
}

void *_lantern_int64_t(int64_t x)
{
  LANTERN_FUNCTION_START
  return (void *)new LanternObject<int64_t>(x);
  LANTERN_FUNCTION_END
}

void *_lantern_double(double x)
{
  LANTERN_FUNCTION_START
  return (void *)new LanternObject<double>(x);
  LANTERN_FUNCTION_END
}

void *_lantern_optional_double(double x, bool is_null)
{
  LANTERN_FUNCTION_START
  c10::optional<double> out;
  if (is_null)
    out = c10::nullopt;
  else
    out = x;

  return (void *)new LanternObject<c10::optional<double>>(out);
  LANTERN_FUNCTION_END
}

void *_lantern_optional_int64_t(int64_t x, bool is_null)
{
  LANTERN_FUNCTION_START
  c10::optional<int64_t> out;
  if (is_null)
    out = c10::nullopt;
  else
    out = x;

  return (void *)new LanternObject<c10::optional<int64_t>>(out);
  LANTERN_FUNCTION_END
}

void *_lantern_bool(bool x)
{
  LANTERN_FUNCTION_START
  return (void *)new LanternObject<bool>(x);
  LANTERN_FUNCTION_END
}

bool _lantern_bool_get (void* x)
{
  LANTERN_FUNCTION_START
  return from_raw::bool_t(x);
  LANTERN_FUNCTION_END
}

int64_t _lantern_int64_t_get(void* x)
{
  LANTERN_FUNCTION_START
  return from_raw::int64_t(x);
  LANTERN_FUNCTION_END
}

double _lantern_double_get (void* x) 
{
  LANTERN_FUNCTION_START
  return from_raw::double_t(x);
  LANTERN_FUNCTION_END
}

void* _lantern_optional_bool (bool x, bool is_null)
{
  LANTERN_FUNCTION_START
  c10::optional<bool> out;
  if (is_null)
    out = c10::nullopt;
  else
    out = x;

  return make_unique::optional::bool_t(out);
  LANTERN_FUNCTION_END
}

void *_lantern_vector_get(void *x, int i)
{
  LANTERN_FUNCTION_START
  auto v = from_raw::tuple(x);
  return v.at(i);
  LANTERN_FUNCTION_END
}

void *_lantern_Tensor_undefined()
{
  LANTERN_FUNCTION_START
  torch::Tensor x = {};
  return make_unique::Tensor(x);
  LANTERN_FUNCTION_END
}

void *_lantern_vector_string_new()
{
  LANTERN_FUNCTION_START
  return (void *)new std::vector<std::string>();
  LANTERN_FUNCTION_END
}

void _lantern_vector_string_push_back(void *self, const char *x)
{
  LANTERN_FUNCTION_START
  reinterpret_cast<std::vector<std::string> *>(self)->push_back(std::string(x));
  LANTERN_FUNCTION_END_VOID
}

int64_t _lantern_vector_string_size(void *self)
{
  LANTERN_FUNCTION_START
  return reinterpret_cast<std::vector<std::string> *>(self)->size();
  LANTERN_FUNCTION_END_RET(0)
}

const char *_lantern_vector_string_at(void *self, int64_t i)
{
  LANTERN_FUNCTION_START
  auto str = reinterpret_cast<std::vector<std::string> *>(self)->at(i);
  char *cstr = new char[str.length() + 1];
  strcpy(cstr, str.c_str());
  return cstr;
  LANTERN_FUNCTION_END
}

void *_lantern_vector_bool_new()
{
  LANTERN_FUNCTION_START
  return (void *)new std::vector<bool>();
  LANTERN_FUNCTION_END
}

void _lantern_vector_bool_push_back(void *self, bool x)
{
  LANTERN_FUNCTION_START
  reinterpret_cast<std::vector<bool> *>(self)->push_back(x);
  LANTERN_FUNCTION_END_VOID
}

int64_t _lantern_vector_bool_size(void *self)
{
  LANTERN_FUNCTION_START
  return reinterpret_cast<std::vector<bool> *>(self)->size();
  LANTERN_FUNCTION_END_RET(0)
}

bool _lantern_vector_bool_at(void *self, int64_t i)
{
  LANTERN_FUNCTION_START
  return reinterpret_cast<std::vector<bool> *>(self)->at(i);
  LANTERN_FUNCTION_END_RET(false)
}

void * _lantern_string_new (const char * value)
{
  LANTERN_FUNCTION_START
  return (void *)new LanternObject<std::string>(std::string(value));
  LANTERN_FUNCTION_END
}

const char * _lantern_string_get (void* self)
{
  auto str = *reinterpret_cast<std::string*>(self);
  char *cstr = new char[str.length() + 1];
  strcpy(cstr, str.c_str());
  return cstr;
}

void _lantern_print_stuff (void* x)
{
  LANTERN_FUNCTION_START
  auto v = reinterpret_cast<LanternPtr<c10::optional<torch::Device>>*>(x);
  std::cout << v->get().value().type() << std::endl;
  LANTERN_FUNCTION_END_VOID
}

void lantern_host_handler() {}
bool lantern_loaded = false;
void check_lantern_loaded() {}

void* _lantern_nn_functional_pad_circular (void* input, void* padding)
{
  LANTERN_FUNCTION_START
  auto input_ = from_raw::Tensor(input);
  auto padding_ = from_raw::IntArrayRef(padding);
  auto out = torch::nn::functional::_pad_circular(input_, padding_);
  return make_unique::Tensor(out);
  LANTERN_FUNCTION_END
}

namespace make_unique {
  void* Tensor (const torch::Tensor& x)
  {
    return make_ptr<torch::Tensor>(x);
  }
  void* TensorList (const torch::TensorList& x)
  {
    return make_ptr<std::vector<torch::Tensor>>(x.vec());
  }
  void* ScalarType (const torch::ScalarType& x)
  {
    return make_ptr<torch::ScalarType>(x);
  }
  void* Scalar (const torch::Scalar& x)
  {
    return make_ptr<torch::Scalar>(x);
  }
  void* TensorOptions (const torch::TensorOptions& x)
  {
    return make_ptr<torch::TensorOptions>(x);
  }
  void* Device (torch::Device& x) 
  {
    return (void*) new LanternPtr<torch::Device>(x);
  }
  void* Dtype (const torch::Dtype& x)
  {
    return make_ptr<torch::Dtype>(x);
  }
  void* Dimname (torch::Dimname& x)
  {
    return (void*) new LanternPtr<torch::Dimname>(x);
  }
  void* DimnameList (const torch::DimnameList& x)
  {
    return (void*) new LanternPtr<std::vector<torch::Dimname>>(x.vec());
  }
  void* Generator (const torch::Generator& x)
  {
    return make_ptr<LanternObject<torch::Generator>>(x);
  }
  void* MemoryFormat (const torch::MemoryFormat& x)
  {
    return make_ptr<LanternObject<torch::MemoryFormat>>(x);
  }
  void* IntArrayRef (const torch::IntArrayRef& x)
  {
    return make_ptr<std::vector<std::int64_t>>(x.vec());
  }
  void * TensorDict (const c10::Dict<std::string,torch::Tensor>& x)
  {
    return make_ptr<c10::Dict<std::string,torch::Tensor>>(x);
  }
  void * CompilationUnit (torch::jit::CompilationUnit& x)
  {
    return (void*) new torch::jit::CompilationUnit(std::move(x));
  }
  void* QScheme (const torch::QScheme& x)
  {
    return make_ptr<torch::QScheme>(x);
  }
  void* variable_list (const torch::autograd::variable_list& x)
  {
    return make_ptr<torch::autograd::variable_list>(x);
  }
  void* Layout (const torch::Layout& x)
  {
    return make_ptr<torch::Layout>(x);
  }
  void* Storage (const torch::Storage& x)
  {
    return make_ptr<torch::Storage>(x);
  }
  void* string (const std::string& x)
  {
    return make_ptr<std::string>(x);
  }
  void* int64_t (const std::int64_t& x)
  {
    return make_ptr<std::int64_t>(x);
  }
  void* double_t (const double& x)
  {
    return make_ptr<double>(x);
  }
  void* bool_t (const bool& x)
  {
    return make_ptr<bool>(x);
  }

  namespace vector {

    void* string (const std::vector<std::string>& x)
    {
      return make_ptr<std::vector<std::string>>(x);
    }
    void* int64_t (const std::vector<std::int64_t>& x)
    {
      return make_ptr<std::vector<std::int64_t>>(x);
    }
    void* bool_t (const std::vector<bool>& x)
    {
      return make_ptr<Vector<bool>>(x);
    }
    void* double_t (const std::vector<double>& x)
    {
      return make_ptr<std::vector<double>>(x);
    }
    void* Scalar (const std::vector<torch::Scalar>& x)
    {
      return make_ptr<std::vector<torch::Scalar>>(x);
    }

  }

  namespace optional {
    
    void* bool_t (const c10::optional<bool>& x)
    {
      return make_ptr<c10::optional<bool>>(x);
    }

    void* string (const c10::optional<std::string>& x)
    {
      return make_ptr<c10::optional<std::string>>(x);
    }

    void* TensorList (const c10::List<c10::optional<torch::Tensor>>& x)
    {
      return make_ptr<LanternObject<c10::List<c10::optional<torch::Tensor>>>>(x);
    }

    void* IntArrayRef (const c10::optional<torch::ArrayRef<std::int64_t>>& x)
    {
      return make_ptr<OptionalArrayRef<std::int64_t>>(x);
    }

    void* DoubleArrayRef (const c10::optional<torch::ArrayRef<double>>& x)
    {
      return make_ptr<OptionalArrayRef<double>>(x);
    }

  }

}

#define LANTERN_FROM_RAW(name, type) \
  type& name(void* x) {return reinterpret_cast<LanternObject<type>*>(x)->get();}


namespace alias {
  using TensorDict = c10::Dict<std::string,torch::Tensor>;
}

namespace from_raw {
  LANTERN_FROM_RAW(Tensor, torch::Tensor)
  LANTERN_FROM_RAW(TensorList, std::vector<torch::Tensor>)
  LANTERN_FROM_RAW(ScalarType, torch::ScalarType)
  LANTERN_FROM_RAW(Scalar, torch::Scalar)
  LANTERN_FROM_RAW(TensorOptions, torch::TensorOptions)
  torch::Device& Device (void* x) {
    return reinterpret_cast<LanternPtr<torch::Device>*>(x)->get();
  }
  LANTERN_FROM_RAW(Dtype, torch::Dtype)
  torch::Dimname& Dimname (void* x) {
    return reinterpret_cast<LanternPtr<torch::Dimname>*>(x)->get();
  }
  std::vector<torch::Dimname>& DimnameList (void* x) {
    return reinterpret_cast<LanternPtr<std::vector<torch::Dimname>>*>(x)->get();
  }
  LANTERN_FROM_RAW(Generator, torch::Generator)
  LANTERN_FROM_RAW(MemoryFormat, torch::MemoryFormat)
  LANTERN_FROM_RAW(IntArrayRef, std::vector<std::int64_t>)
  LANTERN_FROM_RAW(TensorDict, alias::TensorDict)
  torch::jit::CompilationUnit& CompilationUnit (void* x) {
    return *reinterpret_cast<torch::jit::CompilationUnit*>(x);
  }
  LANTERN_FROM_RAW(QScheme, torch::QScheme)
  LANTERN_FROM_RAW(variable_list, torch::autograd::variable_list)
  LANTERN_FROM_RAW(Layout, torch::Layout)
  LANTERN_FROM_RAW(Storage, torch::Storage)
  LANTERN_FROM_RAW(string, std::string)
  LANTERN_FROM_RAW(int64_t, std::int64_t)
  LANTERN_FROM_RAW(bool_t, bool)
  LANTERN_FROM_RAW(double_t, double)

  namespace optional {

    // It's OK to return by value here because we are never modifying optional DimnameLists in
    // place. For consistency we should return by reference, but that would require a few changes
    // code generation in the R side, in order for R to own the memory in the 'optional' case.
    c10::optional<torch::DimnameList> DimnameList (void* x) {
      if (!x) return c10::nullopt;
      return from_raw::DimnameList(x);
    }

    c10::optional<torch::Generator> Generator (void* x) {
      if (!x) return c10::nullopt;
      return from_raw::Generator(x);
    }

    c10::optional<torch::Tensor> Tensor (void* x) {
      if (!x) return c10::nullopt;
      return *reinterpret_cast<c10::optional<torch::Tensor>*>(x);
    }

    c10::optional<double> double_t (void* x) {
      if (!x) return c10::nullopt;
      return *reinterpret_cast<c10::optional<double>*>(x);
    }

    c10::optional<std::int64_t> int64_t (void* x) {
      if (!x) return c10::nullopt;
      return reinterpret_cast<LanternObject<c10::optional<std::int64_t>>*>(x)->get();
    }

    c10::optional<bool> bool_t (void* x) {
      if (!x) return c10::nullopt;
      return *reinterpret_cast<c10::optional<bool>*>(x);
    }

    c10::optional<torch::ScalarType> ScalarType (void* x) {
      if (!x) return c10::nullopt;
      return *reinterpret_cast<torch::ScalarType*>(x);
    }

    c10::optional<std::string> string (void* x)
    {
      if (!x) return c10::nullopt;
      return reinterpret_cast<LanternObject<std::string>*>(x)->get();
    }

    c10::optional<torch::MemoryFormat> MemoryFormat (void* x) {
      if (!x) return c10::nullopt;
      return from_raw::MemoryFormat(x);
    }

    c10::optional<torch::Scalar> Scalar (void* x) {
      if (!x) return c10::nullopt;
      return from_raw::Scalar(x);
    }

    c10::List<c10::optional<torch::Tensor>>& TensorList (void* x) {
      return reinterpret_cast<LanternObject<c10::List<c10::optional<torch::Tensor>>>*>(x)->get();
    }

    OptionalArrayRef<std::int64_t>& IntArrayRef (void* x) {
      return reinterpret_cast<LanternObject<OptionalArrayRef<std::int64_t>>*>(x)->get();
    }

    OptionalArrayRef<double>& DoubleArrayRef (void* x) {
      return reinterpret_cast<LanternObject<OptionalArrayRef<double>>*>(x)->get();
    }

  }

  namespace vector {
    LANTERN_FROM_RAW(string, std::vector<std::string>)
    LANTERN_FROM_RAW(int64_t, std::vector<std::int64_t>)
    LANTERN_FROM_RAW(bool_t, Vector<bool>)
    LANTERN_FROM_RAW(double_t, std::vector<double>)
    LANTERN_FROM_RAW(Scalar, std::vector<torch::Scalar>)
  }

  LANTERN_FROM_RAW(tuple, std::vector<void*>)
}

