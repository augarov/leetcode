/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (44.27%)
 * Likes:    18413
 * Dislikes: 763
 * Total Accepted:    1.6M
 * Total Submissions: 3.6M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given two strings s and t of lengths m and n respectively, return the
 * minimum window substring of s such that every character in t (including
 * duplicates) is included in the window. If there is no such substring, return
 * the empty string "".
 *
 * The testcases will be generated such that the answer is unique.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
 * from string t.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "a", t = "a"
 * Output: "a"
 * Explanation: The entire string s is the minimum window.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a", t = "aa"
 * Output: ""
 * Explanation: Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 *
 *
 *
 * Constraints:
 *
 *
 * m == s.length
 * n == t.length
 * 1 <= m, n <= 10^5
 * s and t consist of uppercase and lowercase English letters.
 *
 *
 *
 * Follow up: Could you find an algorithm that runs in O(m + n) time?
 *
 */

// @lc code=l
class Solution {
public:
    // Complexity
    // Time: O(n)
    // Space: O(1)
    string minWindow(string s, string t) {
        if (t.size() > s.size() || t.empty()) {
            return "";
        }

        constexpr char min = 'A';
        constexpr char max = 'z';
        constexpr auto range = max - min + 1;

        // Character dict
        // Positive numbers - character surplus
        // Negative number - character deficit
        using charmap = std::array<int32_t, range>;

        auto chardict = charmap();
        chardict.fill(0);
        for (char ch : t) {
            // Initialize with the given characters from t as deficit
            --chardict[ch - min];
        }

        // Total deficit
        uint32_t remaining = t.size();

        std::string_view ans;

        const uint32_t sz = s.size();
        for (uint32_t r = 0, l = 0; r < sz; ++r) {
            const auto last_idx = s[r] - min;

            // Add encountered symbol to the map
            if (chardict[last_idx] < 0) {
                --remaining;
            }
            ++chardict[last_idx];

            if (remaining) {
                // We still have deficit in some characters,
                // meaning the desired substring is not found yet
                continue;
            }

            // Now, we have all the needed character
            // We can try to minimize the window from the left
            auto first_idx = s[l] - min;
            while (chardict[first_idx] > 0) {
                // Remove first character from the found array
                --chardict[first_idx];

                // Move the left boundary further
                ++l;
                first_idx = s[l] - min;
            }

            // Try to improve the minimum
            const auto w = r - l + 1;
            if (ans.empty() || w < ans.size()) {
                ans = std::string_view(&s[l], w);
            }
        }

        return std::string(ans);
    }
};
// @lc code=end
