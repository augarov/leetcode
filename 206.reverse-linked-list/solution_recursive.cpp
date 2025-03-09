/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (78.65%)
 * Likes:    22596
 * Dislikes: 508
 * Total Accepted:    5M
 * Total Submissions: 6.4M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, reverse the list, and return the
 * reversed list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2]
 * Output: [2,1]
 *
 *
 * Example 3:
 *
 *
 * Input: head = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is the range [0, 5000].
 * -5000 <= Node.val <= 5000
 *
 *
 *
 * Follow up: A linked list can be reversed either iteratively or recursively.
 * Could you implement both?
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
    // Time:  O(n)
    // Space: O(1)
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return head;
        }

        return reverseListRecursive(head);
    }

    ListNode* reverseListRecursive(ListNode* head) {
        if (!head->next) {
            return head;
        }

        // Extract front node
        auto tail = head->next;
        head->next = nullptr;

        // Recursively reverse tail
        auto new_head = reverseListRecursive(tail);

        // Tail is now is the last node of the sublist
        // Push the extracted node to the end
        tail->next = head;

        return new_head;
    }
};
// @lc code=end
