/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 *
 * https://leetcode.com/problems/koko-eating-bananas/description/
 *
 * algorithms
 * Medium (48.83%)
 * Likes:    11782
 * Dislikes: 769
 * Total Accepted:    1M
 * Total Submissions: 2.1M
 * Testcase Example:  '[3,6,7,11]\n8'
 *
 * Koko loves to eat bananas. There are n piles of bananas, the i^th pile has
 * piles[i] bananas. The guards have gone and will come back in h hours.
 *
 * Koko can decide her bananas-per-hour eating speed of k. Each hour, she
 * chooses some pile of bananas and eats k bananas from that pile. If the pile
 * has less than k bananas, she eats all of them instead and will not eat any
 * more bananas during this hour.
 *
 * Koko likes to eat slowly but still wants to finish eating all the bananas
 * before the guards return.
 *
 * Return the minimum integer k such that she can eat all the bananas within h
 * hours.
 *
 *
 * Example 1:
 *
 *
 * Input: piles = [3,6,7,11], h = 8
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: piles = [30,11,23,4,20], h = 5
 * Output: 30
 *
 *
 * Example 3:
 *
 *
 * Input: piles = [30,11,23,4,20], h = 6
 * Output: 23
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= piles.length <= 10^4
 * piles.length <= h <= 10^9
 * 1 <= piles[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Complexity
    // Time: O(NlogN)
    // Space: O(1)
    int minEatingSpeed(vector<int>& piles, int h) {
        // Utilize binary search to find the minimum speed

        const auto sz = piles.size();
        if (sz == 0 || sz > h) {
            return -1;
        }

        // Sort piles to apply upper bound for hours calculation
        std::sort(piles.begin(), piles.end());
        uint64_t sum = std::accumulate(piles.begin(), piles.end(), 0ull);

        uint64_t lo_speed = ceilDiv(sum, h);  // 1. Speed can't be less then total bananas / hours
        uint64_t hi_speed = piles[sz - 1];    // 2. The size of largest pile is the upper bound,
                                              //  it guarantees all piles will be eaten in sz hours

        while (lo_speed < hi_speed) {
            // Apply binary search to find the answer
            const auto mid_speed = hi_speed / 2 + lo_speed / 2;
            auto hours_to_finish = calculateMinHoursBinary(piles, mid_speed, h);
            if (hours_to_finish > h) {
                // Speed is too low, update lo_speed
                lo_speed = mid_speed + 1;
            } else {
                // Speed is high enough, try to optimize further
                hi_speed = mid_speed;
            }
        }

        return hi_speed;
    }

    uint64_t ceilDiv(uint64_t a, uint64_t b) { return (a + b - 1) / b; }

    uint64_t calculateMinHoursBinary(const std::vector<int>& piles, uint64_t speed, int max_hours) {
        // For sorted piles, we can use binary search to find the bound,
        // where Koko needs more hours to eat the next pile
        // E.g
        // speed = 5
        // [1, 2, 3, 5, 6, 8, 11, 12, 30]
        // [------------^---------------] -> upper_bound(hours=1) = [6,...]
        //             [------^^--------] -> upper_bound(hours=2) = [11,...]
        //                   [--------^^] -> upper_bound(hours=3) = [30,...]
        //                           [--] -> upper_bound(hours=6) = [30]

        const auto end = piles.end();

        auto bracket_begin = piles.begin();
        if (bracket_begin == end) {
            return -1;
        }

        auto hours_per_pile = ceilDiv(*bracket_begin, speed);

        // Find the end of current bracket
        auto bracket_end = std::upper_bound(bracket_begin, end, hours_per_pile * speed);

        // Total hours to consume the piles in the current bracket
        uint64_t total_hours = std::distance(bracket_begin, bracket_end) * hours_per_pile;

        while (bracket_end != end && total_hours <= max_hours) {
            // Hours rate to consume the next bracket's piles
            hours_per_pile = ceilDiv(*bracket_begin, speed);

            // Next bracket
            bracket_begin = bracket_end;
            bracket_end = std::upper_bound(bracket_begin, end, hours_per_pile * speed);

            // Increment hours
            total_hours += std::distance(bracket_begin, bracket_end) * hours_per_pile;
        }

        return total_hours;
    }
};
// @lc code=end
