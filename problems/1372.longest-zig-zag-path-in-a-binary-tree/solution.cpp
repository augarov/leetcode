/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
 *
 * https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/
 *
 * algorithms
 * Medium (66.36%)
 * Likes:    3604
 * Dislikes: 79
 * Total Accepted:    227.6K
 * Total Submissions: 342.9K
 * Testcase Example:  '[1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]'
 *
 * You are given the root of a binary tree.
 *
 * A ZigZag path for a binary tree is defined as follow:
 *
 *
 * Choose any node in the binary tree and a direction (right or left).
 * If the current direction is right, move to the right child of the current
 * node; otherwise, move to the left child.
 * Change the direction from right to left or from left to right.
 * Repeat the second and third steps until you can't move in the tree.
 *
 *
 * Zigzag length is defined as the number of nodes visited - 1. (A single node
 * has a length of 0).
 *
 * Return the longest ZigZag path contained in that tree.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
 * Output: 3
 * Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,1,1,null,1,null,null,1,1,null,1]
 * Output: 4
 * Explanation: Longest ZigZag path in blue nodes (left -> right -> left ->
 * right).
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 5 * 10^4].
 * 1 <= Node.val <= 100
 *
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
    enum class direction {
        left,
        right,
    };

    int longestZigZagFrom(TreeNode* node, int current_length, direction d) {
        if (!node) {
            return current_length;
        }

        // To find longest path,
        // continue zigzag in opposite direction or start over in the same direction
        if (d == direction::left) {
            return std::max(longestZigZagFrom(node->right, current_length + 1, direction::right),
                            longestZigZagFrom(node->left, 0, d));
        }

        return std::max(longestZigZagFrom(node->left, current_length + 1, direction::left),
                        longestZigZagFrom(node->right, 0, d));
    }

public:
    // Complexity
    // Time: O(N)
    // Space: O(1)
    int longestZigZag(TreeNode* root) {
        if (!root) {
            return 0;
        }

        // We can go in both directions from root, because there is no parent node
        return std::max(longestZigZagFrom(root->left, 0, direction::left),
                        longestZigZagFrom(root->right, 0, direction::right));
    }
};
// @lc code=end
