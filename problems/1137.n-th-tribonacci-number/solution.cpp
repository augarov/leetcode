/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 *
 * https://leetcode.com/problems/n-th-tribonacci-number/description/
 *
 * algorithms
 * Easy (63.65%)
 * Likes:    4599
 * Dislikes: 198
 * Total Accepted:    908.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '4'
 *
 * The Tribonacci sequence Tn is defined as follows: 
 *
 * T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
 *
 * Given n, return the value of Tn.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4
 * Output: 4
 * Explanation:
 * T_3 = 0 + 1 + 1 = 2
 * T_4 = 1 + 1 + 2 = 4
 *
 *
 * Example 2:
 *
 *
 * Input: n = 25
 * Output: 1389537
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 37
 * The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31
 * - 1.
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Complexity
    // Time: O(1)
    // Space: O(1)
    int tribonacci(int n) { return tribonacci_values[n]; }

private:
    using tribonacci_values_t = std::array<int, 38>;
    constexpr static auto tribonacci_values = std::invoke([]() noexcept {
        auto res = tribonacci_values_t();
        res[0] = 0;
        res[1] = 1;
        res[2] = 1;
        for (size_t i = 3; i < res.size(); ++i) {
            res[i] = res[i - 1] + res[i - 2] + res[i - 3];
        }
        return res;
    });
};
// @lc code=end
