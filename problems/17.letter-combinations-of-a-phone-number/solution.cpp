/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (63.08%)
 * Likes:    19460
 * Dislikes: 1051
 * Total Accepted:    2.4M
 * Total Submissions: 3.9M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 *
 * A mapping of digits to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 * Example 1:
 *
 *
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * Example 2:
 *
 *
 * Input: digits = ""
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: digits = "2"
 * Output: ["a","b","c"]
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 *
 *
 */

// @lc code=start
class Solution {
public:
    constexpr static auto mapping = std::to_array<std::string_view>({
        /* 2 */ "abc",
        /* 3 */ "def",
        /* 4 */ "ghi",
        /* 5 */ "jkl",
        /* 6 */ "mno",
        /* 7 */ "pqrs",
        /* 8 */ "tuv",
        /* 9 */ "wxyz",
    });

    // Complexity
    // Time: O(2^N)
    // Space: O(2^N)
    vector<string> letterCombinations(string digits) {
        const auto perm_sz = digits.size();
        if (perm_sz == 0) {
            return {};
        }

        // Calculate permutations count
        auto perm_count = 1;
        for (const auto c : digits) {
            perm_count *= mapping[c - '2'].size();
        }

        // Reserve space for permutations
        auto ans = std::vector<std::string>();
        ans.reserve(perm_count);

        // DFS to cover all combinations
        auto buf = std::string(perm_sz, '\0');
        fillCombinations(ans, digits, buf);

        return ans;
    }

    auto fillCombinations(std::vector<std::string>& ans, std::string_view digits, std::string& str)
        -> void {
        if (digits.empty()) {
            ans.push_back(str);
            return;
        }

        // Retrieve mapping for the current digit
        const auto letters = mapping[digits[0] - '2'];
        const auto idx = str.size() - digits.size();
        digits.remove_prefix(1);

        for (auto c : letters) {
            str[idx] = c;
            fillCombinations(ans, digits, str);
        }
    }
};
// @lc code=end
