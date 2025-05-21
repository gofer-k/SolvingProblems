module;
#include <vector>
#include <print>

export module rotation_cases;

/**
 * Find the index of the minimum element in a rotated sorted array.
 * The array is rotated at some pivot unknown to you beforehand.
 * Complexity: O(log n)
 */
size_t min_element_pos_in_rotated_sorted_array(const std::vector<int>& nums) {
  int left = 0;
  int right = nums.size() - 1;

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (nums[mid] > nums[right]) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}

/**
 * 
 * Find the minimum element in a rotated sorted array.
 * The array is rotated at some pivot unknown to you beforehand.
 * Complexity: O(log n)
 */
int min_element_in_rotated_sorted_array(const std::vector<int>& nums) {
  size_t pos = min_element_pos_in_rotated_sorted_array(nums);  
  return nums[pos];
}

/**
 * Find the number of rotations in a sorted array.
 * The array is rotated at some pivot unknown to you beforehand.
 * The number of rotations is equal to the index of the minimum element.
 * Complexity: O(log n)
 */
int minimum_rotations_in_sorted_array(const std::vector<int>& nums) {
  // Whole array is sorted
  if ( nums.front() < nums.back() ) {
    return nums.size();;
  }
  // Array is not rotated}
  return min_element_pos_in_rotated_sorted_array(nums);;
}

void rotate_sorted_array_in_place(std::vector<int>& nums, int k) {
  // Rotate the array in place
  k = k % nums.size();
  std::reverse(nums.begin(), nums.end());
  std::reverse(nums.begin(), nums.begin() + k);
  std::reverse(nums.begin() + k, nums.end());
}

export namespace rot_cases {
  void test_min_element_pos_in_rotated_sorted_array() {
    std::vector<int> nums{4,5,6,7,0,1,2};
    std::println("min_element_pos_in_rotated_sorted_array [4,5,6,7,0,1,2] = {}", min_element_pos_in_rotated_sorted_array(nums));
    nums = {3,4,5,1,2};
    std::println("min_element_pos_in_rotated_sorted_array [3,4,5,1,2] = {}", min_element_pos_in_rotated_sorted_array(nums));
    nums = {11,13,15,17};
    std::println("min_element_pos_in_rotated_sorted_array [11,13,15,17] = {}", min_element_pos_in_rotated_sorted_array(nums));
  }

  void test_min_element_in_rotated_sorted_array() {
    std::vector<int> nums{4,5,6,7,0,1,2};
    std::println("min_element_in_rotated_sorted_array [3,4,5,1,2] = {}", min_element_in_rotated_sorted_array(nums));
    nums = {3,4,5,1,2};
    std::println("min_element_in_rotated_sorted_array [3,4,5,1,2] = {}", min_element_in_rotated_sorted_array(nums));
    nums = {11,13,15,17};
    std::println("min_element_in_rotated_sorted_array [11,13,15,17] = {}", min_element_in_rotated_sorted_array(nums));
  }

  void test_minimum_rotations_in_sorted_array() {
    std::vector<int> nums{4,5,6,7,0,1,2};
    std::println("minimum_rotations_in_sorted_array [4,5,6,7,0,1,2] = {}", minimum_rotations_in_sorted_array(nums));
    nums = {3,4,5,1,2};
    std::println("minimum_rotations_in_sorted_array [3,4,5,1,2] = {}", minimum_rotations_in_sorted_array(nums));
    nums = {11,13,15,17};
    std::println("minimum_rotations_in_sorted_array [11,13,15,17] = {}", minimum_rotations_in_sorted_array(nums));
  }
} // namespace rot_cases