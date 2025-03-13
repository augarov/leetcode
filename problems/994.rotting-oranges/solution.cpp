/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 *
 * https://leetcode.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (55.97%)
 * Likes:    13691
 * Dislikes: 430
 * Total Accepted:    1.2M
 * Total Submissions: 2.1M
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * You are given an m x n grid where each cell can have one of three
 * values:
 *
 *
 * 0 representing an empty cell,
 * 1 representing a fresh orange, or
 * 2 representing a rotten orange.
 *
 *
 * Every minute, any fresh orange that is 4-directionally adjacent to a rotten
 * orange becomes rotten.
 *
 * Return the minimum number of minutes that must elapse until no cell has a
 * fresh orange. If this is impossible, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation: The orange in the bottom left corner (row 2, column 0) is never
 * rotten, because rotting only happens 4-directionally.
 *
 *
 * Example 3:
 *
 *
 * Input: grid = [[0,2]]
 * Output: 0
 * Explanation: Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] is 0, 1, or 2.
 *
 *
 */

// @lc code=start
class Solution {
public:
    struct cell {
        uint32_t x;
        uint32_t y;
    };

    enum : int {
        empty = 0,
        fresh = 1,
        rotten = 2,
    };

    auto visitOrange(std::vector<std::vector<int>>& grid, uint32_t x, uint32_t y,
                     std::queue<cell>& rotten_q) {
        auto& orange = grid[x][y];
        if (orange != fresh) {
            return;
        }
        rotten_q.push(cell(x, y));
        orange = rotten;
    }

    // Complexity
    // Time: O(N^2)
    // Space: O(N^2)
    int orangesRotting(vector<vector<int>>& grid) {
        // Use BFS to "simulate" how do orages rot

        std::queue<cell> rotten_q;
        uint32_t fresh_count = 0;

        uint32_t sz_x = grid.size();
        if (sz_x == 0) {
            return 0;
        }

        // Initialize queue with rotten oranges
        // Count the fresh oranges
        uint32_t sz_y = grid[0].size();
        for (uint32_t x = 0; x < sz_x; ++x) {
            for (uint32_t y = 0; y < sz_y; ++y) {
                auto orange = grid[x][y];
                if (orange == rotten) {
                    rotten_q.push(cell(x, y));
                } else if (orange == fresh) {
                    ++fresh_count;
                }
            }
        }

        if (rotten_q.empty()) {
            if (fresh_count) {
                return -1;
            }
            return 0;
        }

        int minutes = 0;
        while (!rotten_q.empty()) {
            // Add adjacent-to-rot oranges to rotten queue

            auto rotten_count = rotten_q.size();
            for (uint32_t i = 0; i < rotten_count; ++i) {
                auto c = rotten_q.front();
                rotten_q.pop();

                // Check oranges in all four directions

                if (c.x > 0) {
                    visitOrange(grid, c.x - 1, c.y, rotten_q);
                }

                if (c.x < sz_x - 1) {
                    visitOrange(grid, c.x + 1, c.y, rotten_q);
                }

                if (c.y > 0) {
                    visitOrange(grid, c.x, c.y - 1, rotten_q);
                }

                if (c.y < sz_y - 1) {
                    visitOrange(grid, c.x, c.y + 1, rotten_q);
                }
            }

            // Increment minutes, decrement fresh oranges
            fresh_count -= rotten_q.size();
            ++minutes;
        }

        if (fresh_count) {
            return -1;
        }

        // Minutes are off by one,
        // because we do extra iteration to check that no fresh oranges are reachable
        return minutes - 1;
    }
};
// @lc code=end
