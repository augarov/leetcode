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
    // Time: O(n log n)
    // Space: O(n)
    bool uniqueOccurrences(vector<int>& arr) {
        const auto sz = arr.size();
        if (sz < 2) {
            return true;
        }

        std::sort(arr.begin(), arr.end());

        std::unordered_set<uint32_t> occs;

        uint32_t occ = 1;
        for (size_t i = 1; i < sz; ++i) {
            if (arr[i - 1] != arr[i]) {
                if (occs.contains(occ)) {
                    return false;
                }
                occs.insert(occ);
                occ = 1;
            } else {
                ++occ;
            }
        }
        if (occs.contains(occ)) {
            return false;
        }

        return true;
    }
};
// @lc code=end
