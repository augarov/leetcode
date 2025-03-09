/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 *
 * https://leetcode.com/problems/maximum-average-subarray-i/description/
 *
 * algorithms
 * Easy (44.27%)
 * Likes:    3687
 * Dislikes: 344
 * Total Accepted:    665.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 * You are given an integer array nums consisting of n elements, and an integer
 * k.
 *
 * Find a contiguous subarray whose length is equal to k that has the maximum
 * average value and return this value. Any answer with a calculation error
 * less than 10^-5 will be accepted.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,12,-5,-6,50,3], k = 4
 * Output: 12.75000
 * Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [5], k = 1
 * Output: 5.00000
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= k <= n <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        const auto sz = nums.size();

        int32_t sum = 0;

        size_t i = 0;
        for (; i < k; ++i) {
            sum += nums[i];
        }

        auto max_sum = sum;
        for (; i < sz; ++i) {
            sum -= nums[i - k];
            sum += nums[i];

            if (max_sum < sum) {
                max_sum = sum;
            }
        }

        return static_cast<double>(max_sum) / k;
    }
};
// @lc code=end
