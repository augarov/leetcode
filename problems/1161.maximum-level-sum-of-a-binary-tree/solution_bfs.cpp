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
    // Complexity
    // Time: O(n)
    // Space: O(n)
    int maxLevelSum(TreeNode* root) {
        // Use BFS to calculate level sums

        if (!root) {
            return 0;
        }

        using level_t = std::vector<std::reference_wrapper<const TreeNode>>;
        level_t level;
        level.push_back(*root);

        int max_level = 0, curr_level = 1;
        auto max = std::numeric_limits<int64_t>::min();

        while (!level.empty()) {
            auto next_level = level_t();

            // Pre-allocate array for the next level
            next_level.reserve(level.size() * 2);

            int64_t sum = 0;
            for (auto node_ref : level) {
                // Calculate sum and fill the next level
                const auto& node = node_ref.get();
                sum += node.val;
                if (node.left) {
                    next_level.push_back(*node.left);
                }
                if (node.right) {
                    next_level.push_back(*node.right);
                }
            }

            // Try to improve maximum
            if (sum > max) {
                max = sum;
                max_level = curr_level;
            }

            ++curr_level;
            level = std::move(next_level);
        }

        return max_level;
    }
};
// @lc code=end
