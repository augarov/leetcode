/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 *
 * https://leetcode.com/problems/gas-station/description/
 *
 * algorithms
 * Medium (45.78%)
 * Likes:    12387
 * Dislikes: 1244
 * Total Accepted:    976.3K
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,2,3,4,5]\n[3,4,5,1,2]'
 *
 * There are n gas stations along a circular route, where the amount of gas at
 * the i^th station is gas[i].
 * 
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to
 * travel from the i^th station to its next (i + 1)^th station. You begin the
 * journey with an empty tank at one of the gas stations.
 * 
 * Given two integer arrays gas and cost, return the starting gas station's
 * index if you can travel around the circuit once in the clockwise direction,
 * otherwise return -1. If there exists a solution, it is guaranteed to be
 * unique.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
 * Output: 3
 * Explanation:
 * Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 +
 * 4 = 4
 * Travel to station 4. Your tank = 4 - 1 + 5 = 8
 * Travel to station 0. Your tank = 8 - 2 + 1 = 7
 * Travel to station 1. Your tank = 7 - 3 + 2 = 6
 * Travel to station 2. Your tank = 6 - 4 + 3 = 5
 * Travel to station 3. The cost is 5. Your gas is just enough to travel back
 * to station 3.
 * Therefore, return 3 as the starting index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: gas = [2,3,4], cost = [3,4,3]
 * Output: -1
 * Explanation:
 * You can't start at station 0 or 1, as there is not enough gas to travel to
 * the next station.
 * Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 =
 * 4
 * Travel to station 0. Your tank = 4 - 3 + 2 = 3
 * Travel to station 1. Your tank = 3 - 3 + 3 = 3
 * You cannot travel back to station 2, as it requires 4 unit of gas but you
 * only have 3.
 * Therefore, you can't travel around the circuit once no matter where you
 * start.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == gas.length == cost.length
 * 1 <= n <= 10^5
 * 0 <= gas[i], cost[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const uint32_t sz = gas.size();

        int tgas = 0, tcost = 0;

        auto net = std::vector<std::pair<int, uint32_t>>();
        net.reserve(sz);

        // Compute net gain (gas income after leaving the i'th station)
        // Compute the total gas/cost
        for (uint32_t i = 0; i < sz; ++i) {
            tgas += gas[i];
            tcost += cost[i];

            gas[i] -= cost[i];
            if (gas[i] >= 0) {
                net.emplace_back(gas[i], i);
            }
        }

        if (tcost > tgas) {
            return -1;
        }

        // Sort by net gain
        // We expect that the solution will be among ones that give the most gas
        std::sort(net.begin(), net.end(), std::greater{});

        for (auto [_, i] : net) {
            auto tank = gas[i];
            if (tank < 0) {
                continue;
            }

            uint32_t j = i+1;
            while (j - i < sz) {
                tank += gas[j % sz];
                if (tank < 0) {
                    break;
                }
                ++j;
            }

            if (tank >= 0) {
                return i;
            }
        }

        return -1;

    }
};
// @lc code=end

