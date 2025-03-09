/*
 * @lc app=leetcode id=2352 lang=cpp
 *
 * [2352] Equal Row and Column Pairs
 *
 * https://leetcode.com/problems/equal-row-and-column-pairs/description/
 *
 * algorithms
 * Medium (70.31%)
 * Likes:    2303
 * Dislikes: 169
 * Total Accepted:    283.6K
 * Total Submissions: 403.4K
 * Testcase Example:  '[[3,2,1],[1,7,6],[2,7,7]]'
 *
 * Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri,
 * cj) such that row ri and column cj are equal.
 *
 * A row and column pair is considered equal if they contain the same elements
 * in the same order (i.e., an equal array).
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
 * Output: 1
 * Explanation: There is 1 equal row and column pair:
 * - (Row 2, Column 1): [2,7,7]
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
 * Output: 3
 * Explanation: There are 3 equal row and column pairs:
 * - (Row 0, Column 0): [3,1,2,2]
 * - (Row 2, Column 2): [2,4,2,2]
 * - (Row 3, Column 2): [2,4,2,2]
 *
 *
 *
 * Constraints:
 *
 *
 * n == grid.length == grid[i].length
 * 1 <= n <= 200
 * 1 <= grid[i][j] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Complexity
    // Time: O(n * n log n)
    // Space: O(n * n)
    int equalPairs(vector<vector<int>>& grid) {
        // Finding the duplicates of the arrays is not that different
        // from finding duplicates of trivial values

        // Vectors have comparison operator, so we can use std::map

        using arr_map = std::map<std::vector<int>, size_t>;

        // We have to create a second copy of the grid and transpose one of them
        // because we need to compare row-vectors with col-vectors
        auto copy = grid;
        const auto sz = copy.size();
        for (size_t i = 0; i < sz; ++i) {
            for (size_t j = i + 1; j < sz; ++j) {
                std::swap(grid[i][j], grid[j][i]);
            }
        }

        auto rows_map = arr_map();

        for (size_t i = 0; i < sz; ++i) {
            ++rows_map[std::move(copy[i])];
        }

        int ans = 0;

        for (size_t i = 0; i < sz; ++i) {
            auto it = rows_map.find(grid[i]);
            if (it != rows_map.end()) {
                ans += it->second;
            }
        }

        return ans;
    }
};
// @lc code=end
