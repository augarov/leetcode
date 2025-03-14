/*
 * @lc app=leetcode id=2542 lang=cpp
 *
 * [2542] Maximum Subsequence Score
 *
 * https://leetcode.com/problems/maximum-subsequence-score/description/
 *
 * algorithms
 * Medium (54.11%)
 * Likes:    2943
 * Dislikes: 189
 * Total Accepted:    119.4K
 * Total Submissions: 220.6K
 * Testcase Example:  '[1,3,3,2]\n[2,1,3,4]\n3'
 *
 * You are given two 0-indexed integer arrays nums1 and nums2 of equal length n
 * and a positive integer k. You must choose a subsequence of indices from
 * nums1 of length k.
 *
 * For chosen indices i0, i1, ..., ik - 1, your score is defined as:
 *
 *
 * The sum of the selected elements from nums1 multiplied with the minimum of
 * the selected elements from nums2.
 * It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) *
 * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
 *
 *
 * Return the maximum possible score.
 *
 * A subsequence of indices of an array is a set that can be derived from the
 * set {0, 1, ..., n-1} by deleting some or no elements.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
 * Output: 12
 * Explanation:
 * The four possible subsequence scores are:
 * - We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
 * - We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6.
 * - We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12.
 * - We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
 * Therefore, we return the max score, which is 12.
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
 * Output: 30
 * Explanation:
 * Choosing index 2 is optimal: nums1[2] * nums2[2] = 3 * 10 = 30 is the
 * maximum possible score.
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums1.length == nums2.length
 * 1 <= n <= 10^5
 * 0 <= nums1[i], nums2[j] <= 10^5
 * 1 <= k <= n
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Complexity
    // Time: O(NlogN)
    // Space: O(N)
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        using vals_t = std::pair<int, int>;

        const auto sz = nums1.size();

        // Corner cases:
        if (sz == 0 || k == 0) {
            return 0;
        }
        if (k == sz) {
            // Sum all and find glbal minimum
            auto sum1 = std::accumulate(nums1.begin(), nums1.end(), 0ll);
            auto min2 = *std::min_element(nums2.begin(), nums2.end());
            return sum1 * min2;
        }
        if (k == 1) {
            // Find maximum from products for each index
            int64_t max_prod = 0;
            for (size_t i = 0; i < sz; ++i) {
                const int64_t score = nums1[i] * nums2[i];
                max_prod = std::max(score, max_prod);
            }
        }

        // We need to check the product of all possible values from num2
        // with maximized sum of elements from num1

        // E.g
        // k = 3
        // nums1 = [ 3,  1,  4,  1,  5 ]
        // nums2 = [ 10, 9,  7,  6,  5 ]
        //         [ x   x   ^ ]         -> max_sum1 = 8,  min2 = 7  -> score = 56
        //         [ x   -   x   ^ ]     -> max_sum1 = 8,  min2 = 6  -> score = 48
        //         [ x   -   x   -   ^ ] -> max_sum1 = 12, min2 = 5  -> score = 60

        // All elements are non-negative, so we don't need to handle the case
        // with two negative products

        auto nums = std::vector<vals_t>();
        nums.reserve(sz);

        // Zip two arrays together
        for (size_t i = 0; i < sz; ++i) {
            // num1 -> first, num2 -> second
            nums.emplace_back(nums1[i], nums2[i]);
        }
        // Sort by nums2 in descending order
        std::sort(nums.begin(), nums.end(),
                  [](const vals_t& lhs, const vals_t& rhs) { return lhs.second > rhs.second; });

        size_t i = 0;

        // Min Heap to track maximum sum of scanned elements
        using min_heap_t = std::priority_queue<int, std::vector<int>, std::greater<int>>;
        min_heap_t sum_heap;

        // Init the heap with first k-1 element from nums1
        // Calculate their sum
        int64_t sum1 = 0;
        for (; i < k - 1; ++i) {
            sum1 += nums[i].first;
            sum_heap.push(nums[i].first);
        }

        // Consume the elements one-by-one
        int64_t max_prod = 0;
        for (; i < sz; ++i) {
            // Values are sorted, the current element from num2 is always minimum
            const auto min2 = nums[i].second;

            // Current sum is sum of top k-1 previous elements + current element from num1
            // We use the current one unconditionally,
            // because we use associated element from num2 as minimum
            sum1 += nums[i].first;

            const int64_t score = min2 * sum1;
            max_prod = std::max(score, max_prod);

            // Recalculate sum:
            // 1. Consume the next value from num1
            // 2. Drop the minimal value to maximize the sum
            // -> sum1 is a sum of top k-1 elements of nums1[:i+1]
            sum_heap.push(nums[i].first);
            auto min_val = sum_heap.top();
            sum_heap.pop();
            sum1 -= min_val;
        }

        return max_prod;
    }
};
// @lc code=end
