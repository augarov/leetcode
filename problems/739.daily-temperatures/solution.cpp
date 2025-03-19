/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (67.02%)
 * Likes:    13713
 * Dislikes: 345
 * Total Accepted:    1.2M
 * Total Submissions: 1.9M
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * Given an array of integers temperatures represents the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to
 * wait after the i^th day to get a warmer temperature. If there is no future
 * day for which this is possible, keep answer[i] == 0 instead.
 *
 *
 * Example 1:
 * Input: temperatures = [73,74,75,71,69,72,76,73]
 * Output: [1,1,4,2,1,1,0,0]
 * Example 2:
 * Input: temperatures = [30,40,50,60]
 * Output: [1,1,1,0]
 * Example 3:
 * Input: temperatures = [30,60,90]
 * Output: [1,1,0]
 *
 *
 * Constraints:
 *
 *
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Complexity
    // Time: O(N)
    // Space: O(N)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const auto sz = temperatures.size();
        if (sz == 0) {
            return {};
        }

        std::vector<int> answer(sz, 0);

        // Store the days on the stack
        std::vector<size_t> s;
        s.push_back(0);
        for (size_t i = 1; i < sz; ++i) {
            auto top = s[s.size() - 1];
            while (temperatures[top] < temperatures[i]) {
                // The warmer day is found,
                // pop the stack and write the answer for this day

                answer[top] = i - top;
                s.pop_back();

                if (s.empty()) {
                    break;
                }
                top = s[s.size() - 1];
            }

            // Push the current day on stack
            s.push_back(i);
        }

        // The days without warmer counterpart are left on the stack
        // But we don't care, because answer was initialized with zeros

        return answer;
    }
};
// @lc code=end
