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
    // Complexity
    // Time: O(n log n)
    // Space: O(1)
    int minSubArrayLen(int target, vector<int>& nums) {
        constexpr auto min_init = std::numeric_limits<int>::max();
        auto min_w = min_init;

        // Build prefix sums for fast calculation of subarray sum with
        // subarray_sum[i+1:j] = prefix_sum[j] - prefix_sum[i]

        const auto sz = nums.size();
        for (size_t i = 1; i < sz; ++i) {
            nums[i] += nums[i - 1];
        }

        // The integers are positive, so the prefix sums will be automatically sorted.
        // In general case can be solved with sorting prefix sums while storing the indices.

        // For each prefix sum find another one that is >= target + curreent sum
        const auto b = nums.begin(), e = nums.end();
        for (auto it = nums.begin(); it != e; ++it) {
            auto target_it = std::lower_bound(it + 1, e, target + *it);
            if (target_it != e) {
                const auto w = std::distance(it, target_it);
                if (w < min_w) {
                    min_w = w;
                }
            }
        }

        // Check if we can find a good sum from the beginning (i.e prefix itself)
        if (auto target_it = std::lower_bound(b, e, target); target_it != e) {
            const auto w = std::distance(b, target_it) + 1;
            if (w < min_w) {
                min_w = w;
            }
        }

        if (min_w == min_init) {
            return 0;
        }

        return min_w;
    }
};
// @lc code=end
