/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 *
 * https://leetcode.com/problems/number-of-provinces/description/
 *
 * algorithms
 * Medium (68.02%)
 * Likes:    10240
 * Dislikes: 384
 * Total Accepted:    1.1M
 * Total Submissions: 1.7M
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * There are n cities. Some of them are connected, while some are not. If city
 * a is connected directly with city b, and city b is connected directly with
 * city c, then city a is connected indirectly with city c.
 *
 * A province is a group of directly or indirectly connected cities and no
 * other cities outside of the group.
 *
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
 * i^th city and the j^th city are directly connected, and isConnected[i][j] =
 * 0 otherwise.
 *
 * Return the total number of provinces.
 *
 *
 * Example 1:
 *
 *
 * Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 200
 * n == isConnected.length
 * n == isConnected[i].length
 * isConnected[i][j] is 1 or 0.
 * isConnected[i][i] == 1
 * isConnected[i][j] == isConnected[j][i]
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool visitProvince(size_t i, vector<vector<int>>& isConnected, std::vector<bool>& visited) {
        if (visited[i]) {
            // Already visited as part of another province
            return false;
        }

        visited[i] = true;

        size_t sz = isConnected.size();
        for (size_t j = 0; j < sz; ++j) {
            if (isConnected[i][j]) {
                // DFS to all connected cities
                visitProvince(j, isConnected, visited);
            }
        }

        return true;
    }

    // Complexity
    // Time: O(N^2)
    // Space: O(N)
    int findCircleNum(vector<vector<int>>& isConnected) {
        size_t sz = isConnected.size();
        auto visited = std::vector<bool>(sz, false);

        int province_count = 0;
        for (size_t i = 0; i < sz; ++i) {
            // Try visiting all the provinces
            if (visitProvince(i, isConnected, visited)) {
                ++province_count;
            }
        }

        return province_count;
    }
};
// @lc code=end
