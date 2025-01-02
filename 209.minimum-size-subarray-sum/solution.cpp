/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (48.36%)
 * Likes:    13054
 * Dislikes: 470
 * Total Accepted:    1.3M
 * Total Submissions: 2.6M
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of positive integers nums and a positive integer target,
 * return the minimal length of a subarray whose sum is greater than or equal
 * to target. If there is no such subarray, return 0 instead.
 *
 *
 * Example 1:
 *
 *
 * Input: target = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: The subarray [4,3] has the minimal length under the problem
 * constraint.
 *
 *
 * Example 2:
 *
 *
 * Input: target = 4, nums = [1,4,4]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: target = 11, nums = [1,1,1,1,1,1,1,1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= target <= 10^9
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 *
 *
 *
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution of which the time complexity is O(n log(n)).
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        constexpr auto res_init = std::numeric_limits<int>::max();

        auto res = res_init;

        uint32_t sz = nums.size();
        uint32_t l = 0, r = 0;
        for (; r < sz; ++r) {
            target -= nums[r];

            if (target <= 0) {
                while (nums[l] + target <= 0) {
                    target += nums[l];
                    ++l;
                }

                const auto w = r - l + 1;
                if (res > w) {
                    res = w;
                }
            }
        }

        if (res == res_init) {
            return 0;
        }

        return res;
    }
};
// @lc code=end
