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

#include <ranges>

class Solution {
public:
    // Complexity
    // Time: O(NlogN)
    // Space: O(1)
    int minEatingSpeed(const std::vector<int>& piles, int h) {
        // Utilize binary search to find the minimum speed

        const auto sz = piles.size();
        if (sz == 0 || sz > h) {
            return -1;
        }

        const uint64_t max = *std::ranges::max_element(piles);
        const uint64_t sum = std::ranges::fold_left(piles, 0ull, std::plus<>());

        // Search for the first element where predicate evaluates to false in partitioned range
        return *std::ranges::lower_bound(
            // Range:
            // 1. Speed can't be less then total bananas / hours
            // 2. The size of largest pile is the upper bound,
            //    it guarantees all piles will be eaten in sz hours
            std::ranges::iota_view{ceilDiv(sum, h), max + 1}, h,
            [](auto hours_to_finish, auto max_hours) {
                // Predicate: Speed is too low to finish in time
                return hours_to_finish > max_hours;
            },
            [piles](auto speed) {
                // Projection: calculate hours to finish all piles for the given speed
                return std::ranges::fold_left(piles, 0ull,
                                              [speed](uint64_t total_hours, auto pile) {
                                                  // Accumulate the hours of all piles
                                                  return total_hours + ceilDiv(pile, speed);
                                              });
            });
    }

    static constexpr uint64_t ceilDiv(uint64_t a, uint64_t b) noexcept { return (a + b - 1) / b; }
};
// @lc code=end
