/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (65.97%)
 * Likes:    12609
 * Dislikes: 1056
 * Total Accepted:    1.7M
 * Total Submissions: 2.6M
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given the root of a binary tree, imagine yourself standing on the right side
 * of it, return the values of the nodes you can see ordered from top to
 * bottom.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,null,5,null,4]
 *
 * Output: [1,3,4]
 *
 * Explanation:
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,3,4,null,null,null,5]
 *
 * Output: [1,3,4,5]
 *
 * Explanation:
 *
 *
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1,null,3]
 *
 * Output: [1,3]
 *
 *
 * Example 4:
 *
 *
 * Input: root = []
 *
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
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
public:
    void dfs(TreeNode* node, size_t depth, std::vector<int>& right_side_view) {
        // To get right side view, we need to retrieve "rightmost" element on each level of the tree
        // Traverse the tree using DFS, moving first to the right child
        // Thus, we will automatically reach the rightmost element of each level first

        if (!node) {
            return;
        }

        // Check if we already visited this level
        if (right_side_view.size() <= depth) {
            // Update the right side view with the new value
            right_side_view.push_back(node->val);
        }

        // Move to the right child first
        dfs(node->right, depth + 1, right_side_view);
        dfs(node->left, depth + 1, right_side_view);
    }

    // Complexity
    // Time: O(N)
    // Space: O(N)
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> right_side_view;
        dfs(root, 0, right_side_view);
        return right_side_view;
    }
};
// @lc code=end
