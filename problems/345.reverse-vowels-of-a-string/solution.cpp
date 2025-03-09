/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (55.90%)
 * Likes:    4777
 * Dislikes: 2817
 * Total Accepted:    1.1M
 * Total Submissions: 2M
 * Testcase Example:  '"IceCreAm"'
 *
 * Given a string s, reverse only all the vowels in the string and return it.
 * 
 * The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both
 * lower and upper cases, more than once.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "IceCreAm"
 * 
 * Output: "AceCreIm"
 * 
 * Explanation:
 * 
 * The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes
 * "AceCreIm".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "leetcode"
 * 
 * Output: "leotcede"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s consist of printable ASCII characters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        size_t l = 0, r = s.size() - 1;

        auto vow = std::bitset<256>();
        for (auto v : {'a', 'e', 'i', 'o', 'u'}) {
            vow.set(v);
            vow.set(std::toupper(v));
        }

        while (l < r) {
            if (!vow.test(s[l])) {
                ++l;
                continue;
            }
            if (!vow.test(s[r])) {
                --r;
                continue;
            }
            std::swap(s[l], s[r]);
            ++l;
            --r;
        }

        return s;
    }
};
// @lc code=end

