/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 *
 * https://leetcode.com/problems/find-the-highest-altitude/description/
 *
 * algorithms
 * Easy (83.67%)
 * Likes:    2971
 * Dislikes: 370
 * Total Accepted:    508K
 * Total Submissions: 607.2K
 * Testcase Example:  '[-5,1,5,0,-7]'
 *
 * There is a biker going on a road trip. The road trip consists of n + 1
 * points at different altitudes. The biker starts his trip on point 0 with
 * altitude equal 0.
 *
 * You are given an integer array gain of length n where gain[i] is the net
 * gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n).
 * Return the highest altitude of a point.
 *
 *
 * Example 1:
 *
 *
 * Input: gain = [-5,1,5,0,-7]
 * Output: 1
 * Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
 *
 *
 * Example 2:
 *
 *
 * Input: gain = [-4,-3,-2,-1,4,3,2]
 * Output: 0
 * Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is
 * 0.
 *
 *
 *
 * Constraints:
 *
 *
 * n == gain.length
 * 1 <= n <= 100
 * -100 <= gain[i] <= 100
 *
 *
 */

// @lc code=start
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        const auto sz = gain.size();
        if (sz == 0) {
            return 0;
        }

        int max_h = std::max(0, gain[0]);

        // Compute prefix sum and find max
        for (size_t i = 1; i < sz; ++i) {
            gain[i] += gain[i - 1];
            if (gain[i] > max_h) {
                max_h = gain[i];
            }
        }
        return max_h;
    }
};
// @lc code=end
