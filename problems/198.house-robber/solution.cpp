/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Medium (51.99%)
 * Likes:    21956
 * Dislikes: 465
 * Total Accepted:    2.8M
 * Total Submissions: 5.3M
 * Testcase Example:  '[1,2,3,1]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security systems
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 *
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the
 * police.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 400
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Complexity
    // Time: O(N)
    // Space: O(1)
    int rob(vector<int>& nums) {
        const auto sz = nums.size();

        if (sz < 3) {
            return *std::ranges::max_element(nums);
        }

        nums[2] += nums[0];
        for (size_t i = 3; i < sz; ++i) {
            nums[i] += std::max(nums[i - 2], nums[i - 3]);
        }

        return std::max(nums[sz - 1], nums[sz - 2]);
    }
};
// @lc code=end
