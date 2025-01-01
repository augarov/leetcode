/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (35.93%)
 * Likes:    40880
 * Dislikes: 1971
 * Total Accepted:    6.7M
 * Total Submissions: 18.7M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const auto sz = s.size();
        if (sz < 2) {
            return sz;
        }

        // Two pointers representing left and right sides of the substring
        uint32_t l = 0, r = 0;
        uint32_t curr_sub_sz = 0, max_sub_sz = 0;

        std::bitset<128> chars;

        while (r < sz) {
            // Check if the encountered character is already in the substring
            if (!chars.test(s[r])) {
                // We are good, advance the right-side
                chars.set(s[r]);
                ++r;
                ++curr_sub_sz;
                max_sub_sz = std::max(curr_sub_sz, max_sub_sz);
            } else {
                // We already have this character, advance the left side until we reach duplicating character
                while (s[l] != s[r]) {
                    chars.reset(s[l]);
                    ++l;
                    --curr_sub_sz;
                }

                // Advance once again to get rid of it
                ++l;

                // No need to reset chars and decrease current size,
                // because we need to set them back once advancing the right side
                ++r;               
            }
        }

        return max_sub_sz;
    }
};
// @lc code=end

