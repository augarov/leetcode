/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 *
 * https://leetcode.com/problems/determine-if-two-strings-are-close/description/
 *
 * algorithms
 * Medium (54.16%)
 * Likes:    3813
 * Dislikes: 314
 * Total Accepted:    420.5K
 * Total Submissions: 776.6K
 * Testcase Example:  '"abc"\n"bca"'
 *
 * Two strings are considered close if you can attain one from the other using
 * the following operations:
 *
 *
 * Operation 1: Swap any two existing characters.
 *
 *
 * For example, abcde -> aecdb
 *
 *
 * Operation 2: Transform every occurrence of one existing character into
 * another existing character, and do the same with the other
 * character.
 *
 * For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into
 * a's)
 *
 *
 *
 *
 * You can use the operations on either string as many times as necessary.
 *
 * Given two strings, word1 and word2, return true if word1 and word2 are
 * close, and false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: word1 = "abc", word2 = "bca"
 * Output: true
 * Explanation: You can attain word2 from word1 in 2 operations.
 * Apply Operation 1: "abc" -> "acb"
 * Apply Operation 1: "acb" -> "bca"
 *
 *
 * Example 2:
 *
 *
 * Input: word1 = "a", word2 = "aa"
 * Output: false
 * Explanation: It is impossible to attain word2 from word1, or vice versa, in
 * any number of operations.
 *
 *
 * Example 3:
 *
 *
 * Input: word1 = "cabbba", word2 = "abbccc"
 * Output: true
 * Explanation: You can attain word2 from word1 in 3 operations.
 * Apply Operation 1: "cabbba" -> "caabbb"
 * Apply Operation 2: "caabbb" -> "baaccc"
 * Apply Operation 2: "baaccc" -> "abbccc"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word1.length, word2.length <= 10^5
 * word1 and word2 contain only lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Complexity
    // Time: O(n + m)
    // Space: O(1)
    bool closeStrings(string word1, string word2) {
        // The first operation in a swap, meaning the order of symbols doesn't matter,
        // because with swaps a string can be transformed to any other
        // that consists of the same characters

        // Now we only need to determine if the number of characters can match
        // Using the second operation we essentially swap the number of symbol occurrences
        // Meaning we can transform a set of occurrences into any other
        // that consists of the same numbers

        // Now, all we need to do is confirm that the two strings have the same set of symbols and
        // the sets of occurrences of the symbols are also the same

        constexpr auto min = 'a';
        constexpr auto max = 'z';
        constexpr auto range = max - min + 1;
        using occurrences = std::array<uint32_t, range>;

        auto occs1 = occurrences();
        auto occs2 = occurrences();
        std::memset(occs1.data(), 0, sizeof(uint32_t) * range);
        std::memset(occs2.data(), 0, sizeof(uint32_t) * range);

        for (auto ch : word1) {
            ++occs1[ch - min];
        }

        for (auto ch : word2) {
            ++occs2[ch - min];
        }

        // Check that charset is the same
        for (size_t i = 0; i < range; ++i) {
            bool has1 = occs1[i] > 0;  // Symbol in the first word
            bool has2 = occs2[i] > 0;  // Symbol in the second word
            if (has1 != has2) {
                return false;
            }
        }

        // Now we can sort the arrays to validate that occurrences sets also match
        std::sort(occs1.begin(), occs1.end());
        std::sort(occs2.begin(), occs2.end());
        return occs1 == occs2;
    }
};
// @lc code=end
