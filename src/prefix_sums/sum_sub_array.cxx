module;
#include <array>
#include <print>
#include <concepts>
#include <vector>
#include <ranges>
#include <algorithm>

export module sum_sub_array;

template <typename Range>
void print_vector_with_index(const Range &rng)
{
  auto elem_with_index =
      // mutable allows change captured idx among calls
      [idx = std::size_t{0}](const auto &elem) mutable
  {
    // Thanks CTAD allows specific the following:
    // std::pair<std::size_t, std::ranges::range_value_t<decltype(rng)>>(..)
    return std::pair(idx++, elem);
  };

  for (const auto &[idx, elem] :
       rng | std::ranges::views::transform(elem_with_index))
  {
    std::print("[{}: {}] ", idx, elem);
  }
  std::println();
}

template <typename Elem, size_t Size>
  requires(std::integral<Elem> && std::totally_ordered<Elem>)
std::array<Elem, Size> get_prefix_sum(std::array<Elem, Size> arr) {
  for (size_t i = 1; i < Size; ++i) {
    arr[i] = arr[i] + arr[i - 1];    
  }
  return arr;
}

/**
 * Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.
 * A subarray is defined as a contiguous sequence of numbers in an array.
 * A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1.
 * Note that a subarray of size 1 is ascending.
 */
template <typename Elem, size_t Size>
  requires(std::integral<Elem> && std::totally_ordered<Elem>)
Elem sum_sub_array(std::array<Elem, Size> arr, const size_t sub_array_size)
{
  if (sub_array_size > Size)
  {
    std::println("Subarray size is greater than array size");
    return Elem{};
  }

  auto prefix_sum = get_prefix_sum(arr);  
  print_vector_with_index(arr);
  print_vector_with_index(prefix_sum);

  Elem max_sum{};
  for (size_t i = 0; i <= Size - sub_array_size; ++i) {
    Elem window_sum = prefix_sum[i + sub_array_size - 1];
    if (i > 0) {
      window_sum -= prefix_sum[i - 1];
    }
    max_sum = std::max(max_sum, window_sum);
  }  
  return max_sum;
}

int maxAscendingSum(const std::vector<int>& nums) {
    if(nums.empty()) {            
        return 0;
    }

    int max_sum = nums[0];
    int current_sum = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {        
        if (nums[i] > nums[i - 1]) {
            current_sum += nums[i];
        } else {
            current_sum = nums[i];
        }
        max_sum = std::max(max_sum, current_sum);
    }
    return max_sum;
}

export namespace ssa
{
  void test_sum_sub_array()
  {
    std::array<int, 6> arr{1, 2, 3, 4, 5, 6};
    print_vector_with_index(arr);    
    std::println("Sum {}", sum_sub_array(arr, 4));

    std::vector<int> nums = {10,20,30,5,10,50};
    print_vector_with_index(nums);   
    std::println("maxAscendingSum {}", maxAscendingSum(nums));
    print_vector_with_index(nums);    
  }
} // namespace SumSubArray