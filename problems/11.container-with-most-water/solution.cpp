/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (56.73%)
 * Likes:    30219
 * Dislikes: 1897
 * Total Accepted:    3.6M
 * Total Submissions: 6.3M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * You are given an integer array height of length n. There are n vertical
 * lines drawn such that the two endpoints of the i^th line are (i, 0) and (i,
 * height[i]).
 * 
 * Find two lines that together with the x-axis form a container, such that the
 * container contains the most water.
 * 
 * Return the maximum amount of water a container can store.
 * 
 * Notice that you may not slant the container.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The above vertical lines are represented by array
 * [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
 * container can contain is 49.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: height = [1,1]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == height.length
 * 2 <= n <= 10^5
 * 0 <= height[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        uint32_t l = 0, r = height.size() - 1;
        uint32_t m = 0;

        while (l < r) {
            const auto w = r - l;

            // When decreasing the width of the container,
            // we only can reach higher area by increasing the height

            // We scan from both ends and choose which pointer to advance
            // based on the relative heights:
            //    if h[l] < h[r], then only increasing of h[l] can contribute to greater area,
            //       so we advance l
            //    and vise versa
            if (height[l] < height[r]) {
                m = std::max(height[l] * w, m);
                ++l;
            } else {
                m = std::max(height[r] * w, m);
                --r; 
            }
        }

        return m;
    }
};
// @lc code=end

