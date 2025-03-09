/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (32.63%)
 * Likes:    2046
 * Dislikes: 316
 * Total Accepted:    524.3K
 * Total Submissions: 1.6M
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string s and an array of strings words. All the strings of
 * words are of the same length.
 *
 * A concatenated string is a string that exactly contains all the strings of
 * any permutation of words concatenated.
 *
 *
 * For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef",
 * "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is
 * not a concatenated string because it is not the concatenation of any
 * permutation of words.
 *
 *
 * Return an array of the starting indices of all the concatenated substrings
 * in s. You can return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "barfoothefoobarman", words = ["foo","bar"]
 *
 * Output: [0,9]
 *
 * Explanation:
 *
 * The substring starting at 0 is "barfoo". It is the concatenation of
 * ["bar","foo"] which is a permutation of words.
 * The substring starting at 9 is "foobar". It is the concatenation of
 * ["foo","bar"] which is a permutation of words.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "wordgoodgoodgoodbestword", words =
 * ["word","good","best","word"]
 *
 * Output: []
 *
 * Explanation:
 *
 * There is no concatenated substring.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 *
 * Output: [6,9,12]
 *
 * Explanation:
 *
 * The substring starting at 6 is "foobarthe". It is the concatenation of
 * ["foo","bar","the"].
 * The substring starting at 9 is "barthefoo". It is the concatenation of
 * ["bar","the","foo"].
 * The substring starting at 12 is "thefoobar". It is the concatenation of
 * ["the","foo","bar"].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 30
 * s and words[i] consist of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Complexity
    // Time: O(n)
    // Space: O(m)
    vector<int> findSubstring(string s, vector<string>& _words) {
        const auto& words = _words;
        const auto word_sz = words[0].size();

        const auto sv = std::string_view(s);

        if (word_sz * words.size() > sv.size()) {
            return {};
        }

        std::vector<int> ans;

        // Idea:
        // Words are all the same size, so matching their permutations
        // is essentially the same as matching integer permutations
        // The only difference is that we need to match for all possible offsets of the word
        // E.g
        // s = "barfoothefoobarman", w = ["bar", "foo"]
        //  -> bar foo the foo bar man => permutations [bar,foo], [foo,bar]
        //      arf oot hef oob arm    => no permutations
        //       rfo oth efo oba rma   => no permuatations
        // s = "abcabcabc", w = ["ab", "ca"]
        //  -> ab ca bc ab  => permutations [ab,ca]
        //      bc ab ca bc => permutations [ab,ca]

        auto dict = std::unordered_map<std::string_view, size_t>();

        // Build mapping word -> {count, idx}
        for (const auto& w : words) {
            ++dict[w];
        }

        // For each possible offset scan the consecutive words in the string
        // as if it was a simple array
        auto seen = std::unordered_map<std::string_view, size_t>();
        size_t curr_size = 0;
        for (size_t offset = 0; offset < word_sz; ++offset) {
            // Reset state
            seen.clear();
            curr_size = 0;

            for (size_t i = offset; i <= sv.size() - word_sz; i += word_sz) {
                const auto candidate = sv.substr(i, word_sz);
                auto it = dict.find(candidate);
                if (it == dict.end()) {
                    // Permutation is broken, reset state
                    seen.clear();
                    curr_size = 0;
                    continue;
                }

                // Update state
                auto& seen_count = seen[candidate];
                ++seen_count;
                ++curr_size;

                while (seen_count > it->second) {
                    // We used more words than we have in the dictionary
                    // Moving left-side until we get this word
                    const auto start = i - (curr_size - 1) * word_sz;
                    const auto first_word = sv.substr(start, word_sz);
                    --seen[first_word];  // Removing first word from permutation
                    --curr_size;
                }

                if (curr_size == words.size()) {
                    // We completed the permutation
                    ans.push_back(i - (curr_size - 1) * word_sz);
                }
            }
        }

        return ans;
    }
};
// @lc code=end
