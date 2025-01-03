/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 *
 * https://leetcode.com/problems/unique-number-of-occurrences/description/
 *
 * algorithms
 * Easy (77.82%)
 * Likes:    5208
 * Dislikes: 144
 * Total Accepted:    757.7K
 * Total Submissions: 973.5K
 * Testcase Example:  '[1,2,2,1,1,3]'
 *
 * Given an array of integers arr, return true if the number of occurrences of
 * each value in the array is unique or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [1,2,2,1,1,3]
 * Output: true
 * Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two
 * values have the same number of occurrences.
 *
 * Example 2:
 *
 *
 * Input: arr = [1,2]
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 1000
 * -1000 <= arr[i] <= 1000
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Complexity
    // Time: O(n)
    // Space: O(1)
    bool uniqueOccurrences(vector<int>& arr) {
        // Since the input values are extreamly small, we can use array
        // to replace hashing with address arithmetics
        constexpr int min = -1000;
        constexpr int max = 1000;
        using set = std::array<uint16_t, max - min + 1>;

        auto counts = set();
        std::memset(counts.data(), 0, counts.size() * sizeof(uint16_t));

        for (auto v : arr) {
            ++counts[v - min];
        }

        std::unordered_set<uint32_t> occs;
        for (auto c : counts) {
            if (!c) {
                continue;
            }
            if (occs.contains(c)) {
                return false;
            }
            occs.insert(c);
        }

        return true;
    }
};
// @lc code=end
