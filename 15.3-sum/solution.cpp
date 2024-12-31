/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (35.96%)
 * Likes:    31881
 * Dislikes: 2993
 * Total Accepted:    4.2M
 * Total Submissions: 11.7M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation: 
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not
 * matter.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> res;


        for (size_t i = 0, sz = nums.size(); i < sz; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            if (nums[i] > 0) {
                break;
            }

            auto j = i + 1;
            auto k = sz - 1;
            while (j < k) {
                if (j-1 > i && nums[j] == nums[j-1]) {
                    ++j;
                    continue;
                }

                const auto s = nums[i] + nums[j] + nums[k];
                if (s > 0) {
                    --k;
                } else if (s < 0) {
                    ++j;
                } else {
                    res.push_back(std::vector<int>{nums[i], nums[j], nums[k]});
                    ++j; --k;
                }
            }
        }

        return res;
    }
};
// @lc code=end

