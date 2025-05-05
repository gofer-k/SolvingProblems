module;
#include <print>
#include <vector>
export module minimize_binary_operations;

int minimize_binary_operations(std::vector<int> &nums)
{
  const auto count = nums.size();
  if (count < 3 || count > 10e5)
  {
    return -1;
  }

  int num_zeros = std::count_if(nums.begin(), nums.end(), [](int elem) { return elem == 0; });
  int num_oper = 0;  

  auto flip = [&num_zeros](int &elem, int &zeros) -> int{
    if (elem == 0) {
      --zeros;
    }
    else {
      ++zeros;
    }
    // Flip binary element value
    elem = 1 - elem;
    return elem;
  };

  while (num_zeros > 0) {
    int prev_num_zeros = num_zeros;
    for (size_t idx = 2; idx < count; ++idx) {
      if (nums[idx - 2] == 0) {
        nums[idx - 2] = flip(nums[idx - 2], prev_num_zeros);
        nums[idx - 1] = flip(nums[idx - 1], prev_num_zeros);
        nums[idx] = flip(nums[idx], prev_num_zeros);        
        num_oper += 1;
      }
    }
    if (prev_num_zeros == num_zeros)  {
      return -1;
    }
    num_zeros = prev_num_zeros;
  }
  return num_oper;
}

export namespace mso
{
  void test_minimize_binary_operations() {
    std::vector<int> nums = {0, 1, 1, 1, 0, 0};
    std::println("minimize_binary_operations(0, 1, 1, 1, 0, 0): {}", minimize_binary_operations(nums));
    nums = {0, 1, 1, 1};
    std::println("minimize_binary_operations(0, 1, 1, 1): {}", minimize_binary_operations(nums));
    nums = {1,0,0,1,1,1,0,1,1,1};
    std::println("minimize_binary_operations(1,0,0,1,1,1,0,1,1,1): {}", minimize_binary_operations(nums));    
  }
} // namespace mso