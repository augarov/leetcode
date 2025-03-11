/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 *
 * https://leetcode.com/problems/delete-node-in-a-bst/description/
 *
 * algorithms
 * Medium (52.53%)
 * Likes:    9606
 * Dislikes: 328
 * Total Accepted:    651.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[5,3,6,2,4,null,7]\n3'
 *
 * Given a root node reference of a BST and a key, delete the node with the
 * given key in the BST. Return the root node reference (possibly updated) of
 * the BST.
 *
 * Basically, the deletion can be divided into two stages:
 *
 *
 * Search for a node to remove.
 * If the node is found, delete the node.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,3,6,2,4,null,7], key = 3
 * Output: [5,4,6,2,null,null,7]
 * Explanation: Given key to delete is 3. So we find the node with value 3 and
 * delete it.
 * One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
 * Please notice that another valid answer is [5,2,6,null,4,null,7] and it's
 * also accepted.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,3,6,2,4,null,7], key = 0
 * Output: [5,3,6,2,4,null,7]
 * Explanation: The tree does not contain a node with value = 0.
 *
 *
 * Example 3:
 *
 *
 * Input: root = [], key = 0
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -10^5 <= Node.val <= 10^5
 * Each node has a unique value.
 * root is a valid binary search tree.
 * -10^5 <= key <= 10^5
 *
 *
 *
 * Follow up: Could you solve it with time complexity O(height of tree)?
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    auto step(TreeNode* parent, int key) -> TreeNode*& {
        return key < parent->val ? parent->left : parent->right;
    }

    // Complexity
    // Time: O(logN) / O(H)
    // Space: O(1)
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }

        if (root->val == key) {
            // Remmove root
            auto rem = root;
            if (root->right) {
                root = rem->right;
                rem->right = nullptr;

                if (rem->left) {
                    auto desc = root;
                    while (desc->left) {
                        desc = desc->left;
                    }
                    desc->left = rem->left;
                    rem->left = nullptr;
                }
            } else if (root->left) {
                root = rem->left;
            } else {
                root = nullptr;
            }

            delete rem;
            return root;
        }

        // Search for the key
        auto parent = root;
        auto child = step(parent, key);
        while (child && child->val != key) {
            parent = child;
            child = step(parent, key);
        }

        if (!child) {
            return root;
        }

        auto& child_ref = step(parent, key);
        if (child->right) {
            // Right grandchild exists
            // Move it in place of child
            child_ref = child->right;
            child->right = nullptr;
            if (child->left) {
                // Left grandchld exists
                // Move to the leftmost descendant of the right grandchild
                auto desc = child_ref;
                while (desc->left) {
                    desc = desc->left;
                }
                desc->left = child->left;
                child->left = nullptr;
            }
        } else if (child->left) {
            // Right grandchild doesnt exist
            // Left grandchld exists
            // Move it in place of child
            child_ref = child->left;
            child->left = nullptr;
        } else {
            // No grandchildren
            // Reset child to null
            child_ref = nullptr;
        }

        return root;
    }
};
// @lc code=end
