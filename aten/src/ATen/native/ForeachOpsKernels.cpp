#include <ATen/ATen.h>
#include <ATen/native/ForeachUtils.h>

namespace at { namespace native {

std::vector<Tensor> foreach_exp_fallback(TensorList tensors) {
  verify_list(tensors);

  std::vector<Tensor> result;
  for (const auto& t : tensors) {
    auto temp = t.exp();
    result.emplace_back(temp);
  }

  return result;
}

std::vector<Tensor> foreach_exp_fallback_(TensorList tensors) {
  verify_list(tensors);

  for (auto& t : tensors) {
    t.exp_();
  }

  return tensors.vec();
}

std::vector<Tensor> foreach_sqrt_fallback(TensorList tensors) {
  verify_list(tensors);

  std::vector<Tensor> result;
  for (const auto& t : tensors) {
    auto temp = t.sqrt();
    result.emplace_back(temp);
  }

  return result;
}

std::vector<Tensor> foreach_sqrt_fallback_(TensorList tensors) {
  verify_list(tensors);

  for (auto& t : tensors) {
    t.sqrt_();
  }

  return tensors.vec();
}

std::vector<Tensor> foreach_add_scalar_kernel_fallback(TensorList tensors, Scalar scalar) {
  verify_list(tensors);

  std::vector<Tensor> result;
  for (const auto& t : tensors) {
    auto temp = t.add(scalar);
    result.emplace_back(temp);
  }

  return result;
}

std::vector<Tensor> foreach_add_scalar_kernel_fallback_(TensorList tensors, Scalar scalar) {
  verify_list(tensors);

  for (auto& t : tensors) {
    t.add_(scalar);
  }

  return tensors.vec();
}

std::vector<Tensor> foreach_sub_scalar_kernel_fallback(TensorList tensors, Scalar scalar) {
  verify_list(tensors);

  std::vector<Tensor> result;
  for (const auto& t: tensors) {
    auto temp = t.sub(scalar);
    result.emplace_back(temp);
  }

  return result;
}

std::vector<Tensor> foreach_sub_scalar_kernel_fallback_(TensorList tensors, Scalar scalar) {
  verify_list(tensors);

  for (auto& t: tensors) {
    t.sub_(scalar);
  }

  return tensors.vec();
}

std::vector<Tensor> foreach_div_scalar_kernel_fallback(TensorList tensors, Scalar scalar) {
  verify_list(tensors);

  std::vector<Tensor> result;
  for (const auto& t: tensors) {
    auto temp = t.div(scalar);
    result.emplace_back(temp);
  }

  return result;
}

std::vector<Tensor> foreach_div_scalar_kernel_fallback_(TensorList tensors, Scalar scalar) {
  verify_list(tensors);

  for (auto& t: tensors) {
    t.div_(scalar);
  }

  return tensors.vec();
}

std::vector<Tensor> foreach_mul_scalar_kernel_fallback(TensorList tensors, Scalar scalar) {
  verify_list(tensors);

  std::vector<Tensor> result;
  for (const auto& t: tensors) {
    auto temp = t.mul(scalar);
    result.emplace_back(temp);
  }

  return result;
}

std::vector<Tensor> foreach_mul_scalar_kernel_fallback_(TensorList tensors, Scalar scalar) {
  verify_list(tensors);

  for (auto& t: tensors) {
    t.mul_(scalar);
  }

  return tensors.vec();
}

std::vector<Tensor> foreach_add_list_kernel_fallback(TensorList tensors1, TensorList tensors2) {
  verify_list(tensors1, tensors2);

  std::vector<Tensor> result;
  for (int i = 0; i < tensors1.size(); i++) {
    auto temp = tensors1[i].add(tensors2[i]);
    result.emplace_back(temp);
  }

  return result;
}

std::vector<Tensor> foreach_add_list_kernel_fallback_(TensorList tensors1, TensorList tensors2) {
  verify_list(tensors1, tensors2);

  for (int i = 0; i < tensors1.size(); i++) {
    tensors1[i].add_(tensors2[i]);
  }

  return tensors1.vec();
}

std::vector<Tensor> foreach_sub_list_kernel_fallback(TensorList tensors1, TensorList tensors2) {
  verify_list(tensors1, tensors2);

  std::vector<Tensor> result;
  for (int i = 0; i < tensors1.size(); i++) {
    auto temp = tensors1[i].sub(tensors2[i]);
    result.emplace_back(temp);
  }

  return result;
}

std::vector<Tensor> foreach_sub_list_kernel_fallback_(TensorList tensors1, TensorList tensors2) {
  verify_list(tensors1, tensors2);

  for (int i = 0; i < tensors1.size(); i++) {
    tensors1[i].sub_(tensors2[i]);
  }

  return tensors1.vec();
}

std::vector<Tensor> foreach_mul_list_kernel_fallback(TensorList tensors1, TensorList tensors2) {
  verify_list(tensors1, tensors2);

  std::vector<Tensor> result;
  for (int i = 0; i < tensors1.size(); i++) {
    auto temp = tensors1[i].mul(tensors2[i]);
    result.emplace_back(temp);
  }

  return result;
}

std::vector<Tensor> foreach_mul_list_kernel_fallback_(TensorList tensors1, TensorList tensors2) {
  verify_list(tensors1, tensors2);

  for (int i = 0; i < tensors1.size(); i++) {
    tensors1[i].mul_(tensors2[i]);
  }

  return tensors1.vec();
}

std::vector<Tensor> foreach_div_list_kernel_fallback(TensorList tensors1, TensorList tensors2) {
  verify_list(tensors1, tensors2);

  std::vector<Tensor> result;
  for (int i = 0; i < tensors1.size(); i++) {
    auto temp = tensors1[i].div(tensors2[i]);
    result.emplace_back(temp);
  }

  return result;
}

std::vector<Tensor> foreach_div_list_kernel_fallback_(TensorList tensors1, TensorList tensors2) {
  verify_list(tensors1, tensors2);

  for (int i = 0; i < tensors1.size(); i++) {
    tensors1[i].div_(tensors2[i]);
  }

  return tensors1.vec();
}

std::vector<Tensor> foreach_addcdiv_fallback(TensorList input, TensorList tensors1, TensorList tensors2, Scalar scalar) {
  TORCH_CHECK(input.size() > 0, "Tensor list must have at least one tensor.");
  TORCH_CHECK(input.size() == tensors1.size(), "Tensor lists must be of the same length.");
  TORCH_CHECK(tensors1.size() == tensors2.size(), "Tensor lists must be of the same length.");

  std::vector<Tensor> result;
  for (int i = 0; i < input.size(); i++) {
    auto temp = input[i].addcdiv(tensors1[i], tensors2[i], scalar);
    result.emplace_back(temp);
  }

  return result;
}

std::vector<Tensor> foreach_addcmul_fallback(TensorList input, TensorList tensors1, TensorList tensors2, Scalar scalar) {
  TORCH_CHECK(input.size() > 0, "Tensor list must have at least one tensor.");
  TORCH_CHECK(input.size() == tensors1.size(), "Tensor lists must be of the same length.");
  TORCH_CHECK(tensors1.size() == tensors2.size(), "Tensor lists must be of the same length.");

  std::vector<Tensor> result;
  for (int i = 0; i < input.size(); i++) {
    auto temp = input[i].addcmul(tensors1[i], tensors2[i], scalar);
    result.emplace_back(temp);
  }

  return result;
}

std::vector<Tensor> foreach_addcdiv_fallback_(TensorList input, TensorList tensors1, TensorList tensors2, Scalar scalar) {
  TORCH_CHECK(input.size() > 0, "Tensor list must have at least one tensor.");
  TORCH_CHECK(input.size() == tensors1.size(), "Tensor lists must be of the same length.");
  TORCH_CHECK(tensors1.size() == tensors2.size(), "Tensor lists must be of the same length.");

  for (int i = 0; i < input.size(); i++) {
    input[i].addcdiv_(tensors1[i], tensors2[i], scalar);
  }

  return input.vec();
}

std::vector<Tensor> foreach_addcmul_fallback_(TensorList input, TensorList tensors1, TensorList tensors2, Scalar scalar) {
  TORCH_CHECK(input.size() > 0, "Tensor list must have at least one tensor.");
  TORCH_CHECK(input.size() == tensors1.size(), "Tensor lists must be of the same length.");
  TORCH_CHECK(tensors1.size() == tensors2.size(), "Tensor lists must be of the same length.");

  for (int i = 0; i < input.size(); i++) {
    input[i].addcmul_(tensors1[i], tensors2[i], scalar);
  }

  return input.vec();
}

}} // namespace at::native
