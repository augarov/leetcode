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

        // Allocate strings for all permutations
        auto ans = std::vector<std::string>(perm_count, std::string(perm_sz, '\0'));
        fillCombinations(ans, digits, 0, 1);

        return ans;
    }

    auto fillCombinations(std::vector<std::string>& ans, std::string_view digits, size_t curr_digit,
                          size_t repeat) -> void {
        if (curr_digit >= digits.size()) {
            return;
        }

        // Retrieve mapping for the current digit
        const auto letters = mapping[digits[curr_digit] - '2'];
        auto letter_idx = 0;

        // Iterate over all combinations
        const auto sz = ans.size();
        size_t i = 0;
        while (i < sz) {
            const auto curr_letter = letters[letter_idx];
            for (size_t j = 0; j < repeat && i < sz; ++j, ++i) {
                // Set current letter on the given place
                ans[i][curr_digit] = curr_letter;
            }
            letter_idx = (letter_idx + 1) % letters.size();
        }

        // Recursively invoke for the next letter
        fillCombinations(ans, digits, curr_digit + 1, letters.size() * repeat);
    }
};
// @lc code=end
