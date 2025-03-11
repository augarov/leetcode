/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
 *
 * https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (67.28%)
 * Likes:    3648
 * Dislikes: 103
 * Total Accepted:    357.6K
 * Total Submissions: 531.6K
 * Testcase Example:  '[1,7,0,7,-8,null,null]'
 *
 * Given the root of a binary tree, the level of its root is 1, the level of
 * its children is 2, and so on.
 *
 * Return the smallest level x such that the sum of all the values of nodes at
 * level x is maximal.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,7,0,7,-8,null,null]
 * Output: 2
 * Explanation:
 * Level 1 sum = 1.
 * Level 2 sum = 7 + 0 = 7.
 * Level 3 sum = 7 + -8 = -1.
 * So we return the level with the maximum sum which is level 2.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^5 <= Node.val <= 10^5
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
    void updateSums(TreeNode* node, size_t level, std::vector<int64_t>& sums) {
        if (!node) {
            return;
        }

        if (sums.size() < level + 1) {
            sums.resize(level + 1, 0);
        }

        sums[level] += node->val;

        updateSums(node->left, level + 1, sums);
        updateSums(node->right, level + 1, sums);
    }

    // Complexity
    // Time: O(N)
    // Space: O(logN)
    int maxLevelSum(TreeNode* root) {
        // Use DFS to calculate all sums
        auto sums = std::vector<int64_t>{std::numeric_limits<int64_t>::min()};
        updateSums(root, 1, sums);

        // Find max
        int max_idx = 0;
        int64_t max_sum = sums[0];
        for (int idx = 0, sz = sums.size(); idx < sz; ++idx) {
            if (sums[idx] > max_sum) {
                max_sum = sums[idx];
                max_idx = idx;
            }
        }

        return max_idx;
    }
};
// @lc code=end
