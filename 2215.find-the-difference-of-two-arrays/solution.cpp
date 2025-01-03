/*
 * @lc app=leetcode id=2215 lang=cpp
 *
 * [2215] Find the Difference of Two Arrays
 *
 * https://leetcode.com/problems/find-the-difference-of-two-arrays/description/
 *
 * algorithms
 * Easy (80.04%)
 * Likes:    2436
 * Dislikes: 107
 * Total Accepted:    450.8K
 * Total Submissions: 563K
 * Testcase Example:  '[1,2,3]\n[2,4,6]'
 *
 * Given two 0-indexed integer arrays nums1 and nums2, return a list answer of
 * size 2 where:
 *
 *
 * answer[0] is a list of all distinct integers in nums1 which are not present
 * in nums2.
 * answer[1] is a list of all distinct integers in nums2 which are not present
 * in nums1.
 *
 *
 * Note that the integers in the lists may be returned in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,3], nums2 = [2,4,6]
 * Output: [[1,3],[4,6]]
 * Explanation:
 * For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1
 * and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
 * For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4
 * and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
 *
 * Example 2:
 *
 *
 * Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
 * Output: [[3],[]]
 * Explanation:
 * For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] ==
 * nums1[3], their value is only included once and answer[0] = [3].
 * Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums1.length, nums2.length <= 1000
 * -1000 <= nums1[i], nums2[i] <= 1000
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Complexity
    // Time: O(n + m)
    // Space: O(1)
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        auto answer = vector<vector<int>>(2);

        constexpr int skip_val = -100000;

        // Since the input values are extreamly small, we can use bitset
        // to replace hashing with address arithmetics
        constexpr int min = -1000;
        constexpr int max = 1000;
        using set = std::bitset<max - min + 1>;
        auto n1 = set();
        auto n2 = set();

        // Put values into bitset
        for (auto& v : nums1) {
            if (n1.test(v - min)) {
                v = skip_val;  // Set the "skip" marker to values that are already in
            } else {
                n1.set(v - min);
            }
        }
        for (auto& v : nums2) {
            if (n2.test(v - min)) {
                v = skip_val;  // Set the "skip" marker to values that are already in
            } else {
                n2.set(v - min);
            }
        }

        // Find distinct elements in num2 that are not present in num1
        for (auto v : nums1) {
            if (v != skip_val && !n2.test(v - min)) {
                answer[0].push_back(v);
            }
        }

        // Find distinct elements in num1 that are not present in num2
        for (auto v : nums2) {
            if (v != skip_val && !n1.test(v - min)) {
                answer[1].push_back(v);
            }
        }

        return answer;
    }
};
// @lc code=end
