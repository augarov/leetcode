/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (67.53%)
 * Likes:    11947
 * Dislikes: 147
 * Total Accepted:    1.3M
 * Total Submissions: 1.9M
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to
 * efficiently store and retrieve keys in a dataset of strings. There are
 * various applications of this data structure, such as autocomplete and
 * spellchecker.
 *
 * Implement the Trie class:
 *
 *
 * Trie() Initializes the trie object.
 * void insert(String word) Inserts the string word into the trie.
 * boolean search(String word) Returns true if the string word is in the trie
 * (i.e., was inserted before), and false otherwise.
 * boolean startsWith(String prefix) Returns true if there is a previously
 * inserted string word that has the prefix prefix, and false otherwise.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * Output
 * [null, null, true, false, true, null, true]
 *
 * Explanation
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // return True
 * trie.search("app");     // return False
 * trie.startsWith("app"); // return True
 * trie.insert("app");
 * trie.search("app");     // return True
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length, prefix.length <= 2000
 * word and prefix consist only of lowercase English letters.
 * At most 3 * 10^4 calls in total will be made to insert, search, and
 * startsWith.
 *
 *
 */

// @lc code=start
class Trie {
public:
    Trie() : _root(std::make_unique<Node>()) {}

    // Complexity
    // Time: O(N)
    // Space: O(N)
    void insert(string word) {
        // Insert nodes into trie structure
        auto node = _root.get();
        for (auto c : word) {
            size_t idx = c - 'a';
            if (!node->_children[idx]) {
                // Allocate on the way down if needed
                node->_children[idx] = std::make_unique<Node>();
            }
            node = node->_children[idx].get();
        }
        // Mark the last node as a leaf
        node->_set = true;
    }

    // Complexity
    // Time: O(N)
    // Space: O(1)
    bool search(const string& word) const {
        // If node exists and marked as leaf,
        // we have a word in the trie that matches the given one exactly
        auto node = findNode(word);
        return node && node->_set;
    }

    // Complexity
    // Time: O(N)
    // Space: O(1)
    bool startsWith(const string& prefix) const {
        // If node exists, we have some word in the trie that have the given prefix
        auto node = findNode(prefix);
        return node;
    }

private:
    struct Node {
        constexpr static size_t letters_count = 'z' - 'a' + 1;

        using ptr_t = std::unique_ptr<Node>;
        using children_t = std::array<ptr_t, letters_count>;

        children_t _children;  // Suffixes
        bool _set = false;     // Marks the end of the word / leaf

        Node() { std::fill(_children.begin(), _children.end(), nullptr); }
    };

    // Complexity
    // Time: O(N)
    // Space: O(1)
    Node* findNode(std::string_view prefix) const noexcept {
        // Traverse the trie and find the last node for the given prefix
        auto node = _root.get();
        for (auto c : prefix) {
            size_t idx = c - 'a';
            node = node->_children[idx].get();
            if (!node) {
                return nullptr;
            }
        }
        return node;
    }

    Node::ptr_t _root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
