module;
#include <print>
#include <vector>
#include <unordered_map>
export module prefix_sums;

int sub_array_sum(const std::vector<int>& nums, int k) {
  const auto count = nums.size();
  if (nums.empty() || count > 2 * 10e4) {
      return 0;
  }
  
  // Brute force solution
  int result = 0;
  // for (int idx = 0; idx < count; ++idx) {
  //     int sum = nums[idx];

  //     if (sum == k) {
  //         ++result;
  //     }
  //     for (int next = idx + 1; next < count; ++next) {
  //         sum += nums[next];
  //         if (sum == k) {
  //             ++result;
  //         }
  //     }
  // }
  
  int sum = 0;
  std::vector<int> prefix_sum;
  prefix_sum.reserve(count);
  prefix_sum.push_back(nums.front());
  for (int idx = 1; idx < count; ++idx) {
      prefix_sum.push_back(prefix_sum.back() + nums[idx]);
  }

  std::unordered_map<int /* prefix[i] - k */,  int /* prefix[i]*/> cals;
  for (auto sum : prefix_sum) {
      if (sum == k) {
          ++result;
      }
      const auto prefix_window = sum - k;
      if (cals.find(prefix_window) != cals.end()) {
          result += cals[prefix_window];  // WHU??

      }
      cals[sum]++;
  }
  
  return result;
}

export namespace pfs{
  
  void test_prefix_sum_contiguous_array() {
      std::vector<int> arr = {1, 2, 3, 4, 5};
      {
        std::println("Subarray sum [1, 2, 3, 4, 5](0): {} ", sub_array_sum(arr, 0));
        std::println("Subarray sum [1, 2, 3, 4, 5](1): {} ", sub_array_sum(arr, 1));      
        std::println("Subarray sum [1, 2, 3, 4, 5](3): {} ", sub_array_sum(arr, 3));
        std::println("Subarray sum [1, 2, 3, 4, 5](6): {} ", sub_array_sum(arr, 6));
        std::println("Subarray sum [1, 2, 3, 4, 5](7): {} ", sub_array_sum(arr, 7));
        std::println("Subarray sum [1, 2, 3, 4, 5](9): {} ", sub_array_sum(arr, 9));
        std::println("Subarray sum [1, 2, 3, 4, 5](10): {} ", sub_array_sum(arr, 10));
        std::println("Subarray sum [1, 2, 3, 4, 5](15): {} ", sub_array_sum(arr, 15));        
      }
      {
        arr = {1, 1, 1};
        std::println("Subarray sum [1, 1, 1](2): {} ", sub_array_sum(arr, 2));
        std::println("Subarray sum [1, 1, 1](3): {} ", sub_array_sum(arr, 3));
        std::println("Subarray sum [1, 1, 1](4): {} ", sub_array_sum(arr, 4));
      }
  }
} // namespace  pfs