/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 *
 * https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
 *
 * algorithms
 * Medium (60.10%)
 * Likes:    7720
 * Dislikes: 257
 * Total Accepted:    643.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[10,16],[2,8],[1,6],[7,12]]'
 *
 * There are some spherical balloons taped onto a flat wall that represents the
 * XY-plane. The balloons are represented as a 2D integer array points where
 * points[i] = [xstart, xend] denotes a balloon whose horizontal diameter
 * stretches between xstart and xend. You do not know the exact y-coordinates
 * of the balloons.
 *
 * Arrows can be shot up directly vertically (in the positive y-direction) from
 * different points along the x-axis. A balloon with xstart and xend is burst
 * by an arrow shot at x if xstart <= x <= xend. There is no limit to the
 * number of arrows that can be shot. A shot arrow keeps traveling up
 * infinitely, bursting any balloons in its path.
 *
 * Given the array points, return the minimum number of arrows that must be
 * shot to burst all balloons.
 *
 *
 * Example 1:
 *
 *
 * Input: points = [[10,16],[2,8],[1,6],[7,12]]
 * Output: 2
 * Explanation: The balloons can be burst by 2 arrows:
 * - Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
 * - Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
 *
 *
 * Example 2:
 *
 *
 * Input: points = [[1,2],[3,4],[5,6],[7,8]]
 * Output: 4
 * Explanation: One arrow needs to be shot for each balloon for a total of 4
 * arrows.
 *
 *
 * Example 3:
 *
 *
 * Input: points = [[1,2],[2,3],[3,4],[4,5]]
 * Output: 2
 * Explanation: The balloons can be burst by 2 arrows:
 * - Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
 * - Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= points.length <= 10^5
 * points[i].length == 2
 * -2^31 <= xstart < xend <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Complexity
    // Time: O(NlogN)
    // Space: O(1)
    int findMinArrowShots(vector<vector<int>>& points) {
        // Greedy approach:
        // Accumulate the groups of overlapping balloons
        // and shoot the entire group before some balloon leave it

        if (points.empty()) {
            return 0;
        }

        // Sort balloons by the start coordinate
        std::sort(points.begin(), points.end(),
                  [](const auto& lhs, const auto& rhs) { return lhs[0] < rhs[0]; });

        int overlapping_balloons_end = std::numeric_limits<int>::max();

        size_t arrows = 0;
        for (size_t i = 0, sz = points.size(); i < sz; ++i) {
            const auto& balloon = points[i];
            if (balloon[0] > overlapping_balloons_end) {
                // The next balloon starts when overlappin group is finished
                // Shot the current balloon gorup, and start a new one
                ++arrows;
                overlapping_balloons_end = balloon[1];
            } else {
                // Baloon joins overlapping group
                overlapping_balloons_end = std::min(overlapping_balloons_end, balloon[1]);
            }
        }

        // Shaot the last group
        ++arrows;

        return arrows;
    }
};
// @lc code=end
