/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 *
 * https://leetcode.com/problems/merge-strings-alternately/description/
 *
 * algorithms
 * Easy (81.35%)
 * Likes:    4184
 * Dislikes: 113
 * Total Accepted:    1.3M
 * Total Submissions: 1.6M
 * Testcase Example:  '"abc"\n"pqr"'
 *
 * You are given two strings word1 and word2. Merge the strings by adding
 * letters in alternating order, starting with word1. If a string is longer
 * than the other, append the additional letters onto the end of the merged
 * string.
 * 
 * Return the merged string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = "abc", word2 = "pqr"
 * Output: "apbqcr"
 * Explanation: The merged string will be merged as so:
 * word1:  a   b   c
 * word2:    p   q   r
 * merged: a p b q c r
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = "ab", word2 = "pqrs"
 * Output: "apbqrs"
 * Explanation: Notice that as word2 is longer, "rs" is appended to the end.
 * word1:  a   b 
 * word2:    p   q   r   s
 * merged: a p b q   r   s
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: word1 = "abcd", word2 = "pq"
 * Output: "apbqcd"
 * Explanation: Notice that as word1 is longer, "cd" is appended to the end.
 * word1:  a   b   c   d
 * word2:    p   q 
 * merged: a p b q c   d
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word1.length, word2.length <= 100
 * word1 and word2 consist of lowercase English letters.
 * 
 */

// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {    
        uint32_t i1 = 0, i2 = 0;
        const uint32_t s1 = word1.size(), s2 = word2.size();
    
        auto res = std::string();
        res.reserve(s1 + s2);
        while (i1 < s1 && i2 < s2) {
            res += word1[i1++];
            res += word2[i2++];
        }

        while (i1 < s1) {
            res += word1[i1++];
        }

        while (i2 < s2) {
            res += word2[i2++];
        }

        return res;
    }
};
// @lc code=end

