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
    using line = std::pair<int, uint32_t>;

    uint32_t find_backward_container(std::vector<int>& height, std::vector<line>& farthest, bool direction) {
        uint32_t sz = height.size();
        if (sz < 2) {
            return 0;
        }

        uint32_t m = 0;

        farthest.clear();        
        farthest.emplace_back(height[direction ? 0 : sz - 1], 0);

        for (uint32_t x = 1; x < sz; ++x) {
            const auto idx = direction ? x : sz - 1 - x;

            // Find line which is greater/equal
            auto it = std::lower_bound(farthest.begin(), farthest.end(), line{height[idx], 0});
            if (it != farthest.end()) {
                const auto l = x - it->second;
                m = std::max(m, l * height[idx]);
            }

            if (farthest[farthest.size() - 1].first < height[idx]) {
                farthest.emplace_back(height[idx], x);
            }
        }

        return m;
    }

    int maxArea(vector<int>& height) {
        // Idea:
        // For each vertical line find the opposite line the same or greater height,
        // which can form the largetst container (i.e which is the farthest)

        // We need to do that in both directions to check both the containers by the left of each line, and by the right
        auto farthest = std::vector<line>();
        return std::max(
            find_backward_container(height, farthest, true),
            find_backward_container(height, farthest, false));
    }
};
// @lc code=end

