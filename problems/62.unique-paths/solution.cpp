/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (65.41%)
 * Likes:    17268
 * Dislikes: 463
 * Total Accepted:    2.2M
 * Total Submissions: 3.4M
 * Testcase Example:  '3\n7'
 *
 * There is a robot on an m x n grid. The robot is initially located at the
 * top-left corner (i.e., grid[0][0]). The robot tries to move to the
 * bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move
 * either down or right at any point in time.
 *
 * Given the two integers m and n, return the number of possible unique paths
 * that the robot can take to reach the bottom-right corner.
 *
 * The test cases are generated so that the answer will be less than or equal
 * to 2 * 10^9.
 *
 *
 * Example 1:
 *
 *
 * Input: m = 3, n = 7
 * Output: 28
 *
 *
 * Example 2:
 *
 *
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation: From the top-left corner, there are a total of 3 ways to reach
 * the bottom-right corner:
 * 1. Right -> Down -> Down
 * 2. Down -> Down -> Right
 * 3. Down -> Right -> Down
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= m, n <= 100
 *
 *
 */

// @lc code=start

class Solution {
public:
    // Complexity
    // Time: O(m * n)
    // Space: O(n)
    int uniquePaths(int m, int n) {
        // If grid is located horizontally,
        // rotate it to save on allocation
        if (m < n) {
            std::swap(m, n);
        }

        // Corner cases
        if (n < 3) {
            if (n == 2) {
                return m;
            }
            return 1;
        }

        // Calculate unique ways for each coordinate
        auto dp = std::vector<uint32_t>(n, 1);
        for (size_t y = 1; y < m; ++y) {
            dp[0] = 1;  // Only one way to reach the first col's cell
            for (size_t x = 1; x < n; ++x) {
                // dp[x]   -> unique paths to reach grid[x][y-1]
                // dp[x-1] -> unique paths to reach grid[x-1][y]
                // sum     -> unique paths to reach grid[x][y]
                dp[x] += dp[x - 1];
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end
