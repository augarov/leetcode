/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 *
 * https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
 *
 * algorithms
 * Easy (52.26%)
 * Likes:    5416
 * Dislikes: 1475
 * Total Accepted:    643.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '"ABCABC"\n"ABC"'
 *
 * For two strings s and t, we say "t divides s" if and only if s = t + t + t +
 * ... + t + t (i.e., t is concatenated with itself one or more times).
 * 
 * Given two strings str1 and str2, return the largest string x such that x
 * divides both str1 and str2.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: str1 = "ABCABC", str2 = "ABC"
 * Output: "ABC"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: str1 = "ABABAB", str2 = "ABAB"
 * Output: "AB"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: str1 = "LEET", str2 = "CODE"
 * Output: ""
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= str1.length, str2.length <= 1000
 * str1 and str2 consist of English uppercase letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    uint32_t gcd(uint32_t a, uint32_t b) {
        if (a > b) {
            return gcd(a - b, b);
        }
        if (b > a) {
            return gcd(a, b - a);
        }
        return a;
    }

    bool check_gcd(std::string_view s, std::string_view gcd) {
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] != gcd[i % gcd.size()]) {
                return false;
            }
        }
        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        auto gcd_sz = gcd(str1.size(), str2.size());
        auto gcd = std::string_view(str1.data(), gcd_sz);
        if (check_gcd(str1, gcd) && check_gcd(str2, gcd)) {
            return std::string(gcd);
        }
        return "";
    }
};
// @lc code=end

