/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/description/
 *
 * algorithms
 * Easy (79.38%)
 * Likes:    11435
 * Dislikes: 571
 * Total Accepted:    1.3M
 * Total Submissions: 1.7M
 * Testcase Example:  '2'
 *
 * Given an integer n, return an array ans of length n + 1 such that for each i
 * (0 <= i <= n), ans[i] is the number of 1's in the binary representation of
 * i.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: [0,1,1]
 * Explanation:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 *
 *
 * Example 2:
 *
 *
 * Input: n = 5
 * Output: [0,1,1,2,1,2]
 * Explanation:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 * 3 --> 11
 * 4 --> 100
 * 5 --> 101
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 10^5
 *
 *
 *
 * Follow up:
 *
 *
 * It is very easy to come up with a solution with a runtime of O(n log n). Can
 * you do it in linear time O(n) and possibly in a single pass?
 * Can you do it without using any built-in function (i.e., like
 * __builtin_popcount in C++)?
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Complexity
    // Time: O(N)
    // Space: O(1)
    vector<int> countBits(int n) {
        // For each range [2^(i-1), 2^i),
        // the counts are greater exactly by 1
        // then the respective element in the range [0, 2^(i-1))

        // E.g
        //  0, 1, 10, 11, 100, 101, 110, 111, ...
        // [0][1]
        //  ----- [1,  2]
        //  ------------- [1,  2,   2,   3]
        //  ...

        auto ans = std::vector<int>(n + 1, 0);

        size_t prev_range_sz = 1;
        size_t i = 1;
        while (i <= n) {
            for (size_t j = 0; j < prev_range_sz && i <= n; ++j, ++i) {
                ans[i] = ans[j] + 1;
            }
            prev_range_sz <<= 1;
        }

        return ans;
    }
};
// @lc code=end
