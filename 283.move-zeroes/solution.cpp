/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (62.36%)
 * Likes:    17299
 * Dislikes: 496
 * Total Accepted:    3.6M
 * Total Submissions: 5.8M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an integer array nums, move all 0's to the end of it while maintaining
 * the relative order of the non-zero elements.
 * 
 * Note that you must do this in-place without making a copy of the array.
 * 
 * 
 * Example 1:
 * Input: nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * Example 2:
 * Input: nums = [0]
 * Output: [0]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you minimize the total number of operations done?
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t tgt = 0;
        size_t sz = nums.size();
        for (size_t i = 0; i < sz; ++i) {
            if (nums[i] != 0) {
                if (i > tgt) {
                    nums[tgt] = nums[i];
                    nums[i] = 0;
                }
                ++tgt;
            }
        }
    }
};
// @lc code=end

