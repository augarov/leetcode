/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (58.80%)
 * Likes:    7809
 * Dislikes: 984
 * Total Accepted:    1.5M
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two integer arrays nums1 and nums2, return an array of their
 * intersection. Each element in the result must appear as many times as it
 * shows in both arrays and you may return the result in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 * Explanation: [9,4] is also accepted.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect_impl(const vector<int>& shrt, const vector<int>& lng) {
        std::unordered_map<int, size_t> counts;
        std::vector<int> res;
        for (auto v : shrt) {
            ++counts[v];
        }

        for (auto v : lng) {
            auto it = counts.find(v);
            if (it == counts.end()) {
                continue;
            }
            if (it->second <= 0) {
                continue;
            }
            it->second--;
            res.push_back(v);
        }
    
        return res;
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect_impl(nums2, nums1);
        }
        return intersect_impl(nums1, nums2);
    }
};
// @lc code=end

