/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 *
 * https://leetcode.com/problems/increasing-triplet-subsequence/description/
 *
 * algorithms
 * Medium (39.25%)
 * Likes:    8317
 * Dislikes: 596
 * Total Accepted:    701.1K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given an integer array nums, return true if there exists a triple of indices
 * (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such
 * indices exists, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,4,5]
 * Output: true
 * Explanation: Any triplet where i < j < k is valid.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,4,3,2,1]
 * Output: false
 * Explanation: No triplet exists.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,1,5,0,4,6]
 * Output: true
 * Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4]
 * == 4 < nums[5] == 6.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5 * 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you implement a solution that runs in O(n) time complexity
 * and O(1) space complexity?
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet_impl(vector<int>& nums, size_t i) {
        const auto sz = nums.size();
        if(sz < i + 3) {
            // Less then 3 values in the array
            return false;
        }

        int a = nums[i++];
        while (i < sz && nums[i] <= a) {
            a = nums[i++];
        }

        if (sz < i + 2) {
            // Less then 2 values remaining
            return false;
        }

        int b = nums[i++];
        for (; i < sz; ++i) {
            if (nums[i] > b) {
                return true;
            }

            if (nums[i] > a) {
                // Update second minimum
                b = nums[i];
            } else if (nums[i] < a) {
                // Value less then first minimum - check subarray
                if (increasingTriplet_impl(nums, i)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool increasingTriplet(vector<int>& nums) {
        return increasingTriplet_impl(nums, 0);
    }
};
// @lc code=end

