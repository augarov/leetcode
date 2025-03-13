/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (67.62%)
 * Likes:    17712
 * Dislikes: 928
 * Total Accepted:    2.9M
 * Total Submissions: 4.2M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Given an integer array nums and an integer k, return the k^th largest
 * element in the array.
 *
 * Note that it is the k^th largest element in the sorted order, not the k^th
 * distinct element.
 *
 * Can you solve it without sorting?
 *
 *
 * Example 1:
 * Input: nums = [3,2,1,5,6,4], k = 2
 * Output: 5
 * Example 2:
 * Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
 * Output: 4
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Complexity
    // Time: O(NlogN)
    // Space: O(1)
    int findKthLargest(vector<int>& nums, int k) {
        // Using min heap (smallest element on the top)
        // By keeping the heap size at size=k,
        // we guarantee that k-th largest (i.e smallest from top k) is on top
        using min_heap_t = std::priority_queue<int, std::vector<int>, std::greater<int>>;
        min_heap_t heap;

        size_t i = 0, sz = nums.size();

        // Fill first k elements
        while (heap.size() < k) {
            heap.push(nums[i++]);
        }

        // Keep pushing the new elements and removing the smallest
        for (; i < sz; ++i) {
            heap.push(nums[i]);
            heap.pop();
        }

        // k-th largest is on top
        return heap.top();
    }
};
// @lc code=end
