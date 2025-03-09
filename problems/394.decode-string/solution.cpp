/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (60.38%)
 * Likes:    13062
 * Dislikes: 640
 * Total Accepted:    931.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 *
 * You may assume that the input string is always valid; there are no extra
 * white spaces, square brackets are well-formed, etc. Furthermore, you may
 * assume that the original data does not contain any digits and that digits
 * are only for those repeat numbers, k. For example, there will not be input
 * like 3a or 2[4].
 *
 * The test cases are generated so that the length of the output will never
 * exceed 10^5.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 *
 *
 * Example 3:
 *
 *
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 30
 * s consists of lowercase English letters, digits, and square brackets
 * '[]'.
 * s is guaranteed to be a valid input.
 * All the integers in s are in the range [1, 300].
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Complexity
    // Time: O(n)
    // Space: O(n)
    string decodeString(string s) {
        // The idea:
        // Scan the string parsing the repeat counts and square brackets.
        // Store the info about the nested fragments on the stack.

        struct frag {
            uint32_t fragment_sz = 0;
            uint32_t repeats = 0;
        };

        // Stack of fragment state "leftovers"
        // Push on top every time we meet nested encoded strings
        std::vector<frag> st;
        std::string ans;

        // Flag to mark if we are currently inside the square brackets
        bool frag_started = false;
        frag curr = {};

        for (auto ch : s) {
            if (ch >= '0' && ch <= '9') {
                // Parse repeat count
                if (frag_started) {
                    // Nested encoded string case
                    // Save the current state in the stack
                    st.push_back(std::exchange(curr, {}));
                    frag_started = false;
                }
                curr.repeats = curr.repeats * 10 + (ch - '0');
                continue;
            }

            if (ch == '[') {
                frag_started = true;
                continue;
            }

            if (ch == ']') {
                // The fragment is finished

                if (curr.repeats > 1) {
                    // Ensure the memory is allocated to avoid relocation in the middle of append
                    // loop
                    ans.reserve(ans.size() + curr.fragment_sz * (curr.repeats - 1));

                    // Repeat the fragment requested number of times
                    auto frag = std::string_view(ans.data() + ans.size() - curr.fragment_sz,
                                                 curr.fragment_sz);
                    for (size_t i = 1; i < curr.repeats; ++i) {
                        ans.append(frag);
                    }
                }

                if (st.empty()) {
                    // State stack is empty, we are no longer inside the nested strings
                    frag_started = false;
                    curr = {};
                } else {
                    // We've left the nested string
                    // Get the state saved on the top of the stack
                    // and merge it with the fragment that we appended
                    auto total_added = curr.fragment_sz * curr.repeats;
                    curr = {
                        .fragment_sz = st[st.size() - 1].fragment_sz + total_added,
                        .repeats = st[st.size() - 1].repeats,
                    };
                    st.pop_back();
                }
                continue;
            }

            if (ch >= 'a' && ch <= 'z') {
                // Collect the encoded string characters
                if (frag_started) {
                    ++curr.fragment_sz;
                }
                ans.push_back(ch);
                continue;
            }
        }
        return ans;
    }
};

// @lc code=end
