/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 *
 * https://leetcode.com/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (54.95%)
 * Likes:    8514
 * Dislikes: 233
 * Total Accepted:    739.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,2],[2,3],[3,4],[1,3]]'
 *
 * Given an array of intervals intervals where intervals[i] = [starti, endi],
 * return the minimum number of intervals you need to remove to make the rest
 * of the intervals non-overlapping.
 *
 * Note that intervals which only touch at a point are non-overlapping. For
 * example, [1, 2] and [2, 3] are non-overlapping.
 *
 *
 * Example 1:
 *
 *
 * Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
 * Output: 1
 * Explanation: [1,3] can be removed and the rest of the intervals are
 * non-overlapping.
 *
 *
 * Example 2:
 *
 *
 * Input: intervals = [[1,2],[1,2],[1,2]]
 * Output: 2
 * Explanation: You need to remove two [1,2] to make the rest of the intervals
 * non-overlapping.
 *
 *
 * Example 3:
 *
 *
 * Input: intervals = [[1,2],[2,3]]
 * Output: 0
 * Explanation: You don't need to remove any of the intervals since they're
 * already non-overlapping.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= intervals.length <= 10^5
 * intervals[i].length == 2
 * -5 * 10^4 <= starti < endi <= 5 * 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Complexity
    // Time: O(NlogN)
    // Space: O(N)
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        struct interval {
            int32_t start = 0;
            int32_t end = 0;
        };

        const auto sz = intervals.size();

        // Store all intervals as an array
        // Not a must, we can work directly with vector<vector<int>>
        // and reduce space complexity, but I prefer cache locality
        std::vector<interval> is;
        is.reserve(sz);
        for (const auto& i : intervals) {
            is.emplace_back(i[0], i[1]);
        }

        // Sort the intervals by end
        std::sort(is.begin(), is.end(),
                  [](const auto& lhs, const auto& rhs) { return lhs.end < rhs.end; });

        // When intervals are strictly ordered,
        // we can scan them and find the longest non-ovelapping sequence
        auto non_overlapping_end = is[0].end;
        size_t non_overlapping_count = 1;
        for (size_t i = 1; i < sz; ++i) {
            // Greedy approach:
            // Take the first non-overlapping because
            // it is also the shortest due to the sorting
            if (is[i].start >= non_overlapping_end) {
                non_overlapping_end = is[i].end;
                ++non_overlapping_count;
            }
        }

        return sz - non_overlapping_count;
    }
};
// @lc code=end
