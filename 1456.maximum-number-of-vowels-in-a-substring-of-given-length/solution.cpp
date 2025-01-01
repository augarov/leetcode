/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 *
 * https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
 *
 * algorithms
 * Medium (59.44%)
 * Likes:    3599
 * Dislikes: 138
 * Total Accepted:    438.7K
 * Total Submissions: 737.9K
 * Testcase Example:  '"abciiidef"\n3'
 *
 * Given a string s and an integer k, return the maximum number of vowel
 * letters in any substring of s with length k.
 *
 * Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abciiidef", k = 3
 * Output: 3
 * Explanation: The substring "iii" contains 3 vowel letters.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aeiou", k = 2
 * Output: 2
 * Explanation: Any substring of length 2 contains 2 vowels.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "leetcode", k = 3
 * Output: 2
 * Explanation: "lee", "eet" and "ode" contain 2 vowels.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters.
 * 1 <= k <= s.length
 *
 *
 */

// @lc code=start
class Solution {
public:
    static constexpr char letter_idx(char ch) { return ch - 'a'; }

    int maxVowels(string s, int k) {
        std::bitset<26> chars;
        for (char ch : {'a', 'e', 'i', 'o', 'u'}) {
            chars.set(letter_idx(ch));
        }

        int vowels = 0;
        size_t i = 0;
        for (; i < k; ++i) {
            vowels += chars.test(letter_idx(s[i]));
        }

        auto mx = vowels;
        for (const auto sz = s.size(); i < sz; ++i) {
            vowels += chars.test(letter_idx(s[i]));
            vowels -= chars.test(letter_idx(s[i - k]));
            if (vowels > mx) {
                mx = vowels;
            }
        }

        return mx;
    }
};
// @lc code=end
