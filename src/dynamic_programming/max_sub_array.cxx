module;
#include <vector>
#include <numeric>
#include <print>

export module dyn_prog_max_sub_array;

// Function to find the maximum subarray sum using Kadane's algorithm
// Time complexity: O(n)
// Space complexity: O(1)
int max_sub_array(const std::vector<int>& nums) {
    int max_sum = nums[0];
    int current_sum = nums[0];

    for (std::size_t i = 1; i < nums.size(); ++i) {
        current_sum = std::max(nums[i], current_sum + nums[i]);        
        max_sum = std::max(max_sum, current_sum);
        std::println("idx: {}, current_sum: {}, max_sum: {}", i, current_sum, max_sum);        
    }

    return max_sum;
}


export namespace dyn_prog {    
    void test_max_sub_array() {
        std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int result = max_sub_array(nums);
        std::println("max_sub_array: {}", result); // Output: 6
    }
}
