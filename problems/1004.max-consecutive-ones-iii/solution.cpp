/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 *
 * https://leetcode.com/problems/max-consecutive-ones-iii/description/
 *
 * algorithms
 * Medium (64.77%)
 * Likes:    9011
 * Dislikes: 152
 * Total Accepted:    797.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,1,1,0,0,0,1,1,1,1,0]\n2'
 *
 * Given a binary array nums and an integer k, return the maximum number of
 * consecutive 1's in the array if you can flip at most k 0's.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 * Output: 6
 * Explanation: [1,1,1,0,0,1,1,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is
 * underlined.
 *
 * Example 2:
 *
 *
 * Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
 * Output: 10
 * Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is
 * underlined.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 * 0 <= k <= nums.length
 *
 *
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        uint32_t sz = nums.size();

        int mx = 0;

        if (k == 0) {
            // Handle k == 0 case separately to not mess with it later
            int curr = 0;
            for (auto v : nums) {
                if (!v) {
                    curr = 0;
                } else {
                    ++curr;
                    if (curr > mx) {
                        mx = curr;
                    }
                }
            }
            return mx;
        }

        uint32_t l = 0, r = 0;
        for (; r < sz; ++r) {
            if (!nums[r]) {
                // Zero encountered
                if (k) {
                    --k;
                } else {
                    // No flips left, advancing left side
                    while (nums[l]) {
                        // We can't go out-of-bounds here because k > 0
                        ++l;
                    }

                    ++l;  // Advance over the zero to release the flip
                }
            }

            const auto len = r - l + 1;
            if (len > mx) {
                mx = len;
            }
        }

        return mx;
    }
};
// @lc code=end
