/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
 *
 * https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
 *
 * algorithms
 * Medium (59.60%)
 * Likes:    4494
 * Dislikes: 91
 * Total Accepted:    647.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,3,4,7,1,2,6]'
 *
 * You are given the head of a linked list. Delete the middle node, and return
 * the head of the modified linked list.
 *
 * The middle node of a linked list of size n is the ⌊n / 2⌋^th node from the
 * start using 0-based indexing, where ⌊x⌋ denotes the largest integer less
 * than or equal to x.
 *
 *
 * For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2,
 * respectively.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,3,4,7,1,2,6]
 * Output: [1,3,4,1,2,6]
 * Explanation:
 * The above figure represents the given linked list. The indices of the nodes
 * are written below.
 * Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
 * We return the new list after removing this node.
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2,3,4]
 * Output: [1,2,4]
 * Explanation:
 * The above figure represents the given linked list.
 * For n = 4, node 2 with value 3 is the middle node, which is marked in red.
 *
 *
 * Example 3:
 *
 *
 * Input: head = [2,1]
 * Output: [2]
 * Explanation:
 * The above figure represents the given linked list.
 * For n = 2, node 1 with value 1 is the middle node, which is marked in red.
 * Node 0 with value 2 is the only node remaining after removing node 1.
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [1, 10^5].
 * 1 <= Node.val <= 10^5
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Complexity
    // Time: O(N)
    // Space: O(1)
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr) {
            return nullptr;
        }

        // Two pointers, slow makes 1 step at a time, and fast - two steps
        auto slow = head, fast = head->next->next;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Once fast reaches the end, slow points to the middle
        // Delete the middle
        auto middle = slow->next;
        slow->next = slow->next->next;
        delete middle;

        return head;
    }
};
// @lc code=end
