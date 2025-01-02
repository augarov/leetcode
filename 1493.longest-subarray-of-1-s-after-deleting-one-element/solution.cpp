/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 *
 * https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/
 *
 * algorithms
 * Medium (68.36%)
 * Likes:    4101
 * Dislikes: 88
 * Total Accepted:    358K
 * Total Submissions: 523.5K
 * Testcase Example:  '[1,1,0,1]'
 *
 * Given a binary array nums, you should delete one element from it.
 *
 * Return the size of the longest non-empty subarray containing only 1's in the
 * resulting array. Return 0 if there is no such subarray.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,0,1]
 * Output: 3
 * Explanation: After deleting the number in position 2, [1,1,1] contains 3
 * numbers with value of 1's.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,1,1,0,1,1,0,1]
 * Output: 5
 * Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1]
 * longest subarray with value of 1's is [1,1,1,1,1].
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,1,1]
 * Output: 2
 * Explanation: You must delete one element.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 *
 *
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const uint32_t sz = nums.size();

        int max_w = 0;

        int l = 0, r = 0;
        for (; r < sz; ++r) {
            const auto w = r - l;  // Compute subarray size with one element "removed"
            if (w > max_w) {
                max_w = w;
            }

            if (!nums[r]) {
                // Zero encountered
                ++r;
                break;
            }
        }

        for (; r < sz; ++r) {
            if (!nums[r]) {
                // Another zero encountered, "moving" left side over the previosu one
                while (nums[l]) {
                    ++l;
                }
                ++l;
            }

            const auto w = r - l;
            if (w > max_w) {
                max_w = w;
            }
        }

        return max_w;
    }
};
// @lc code=end
