/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 *
 * https://leetcode.com/problems/dota2-senate/description/
 *
 * algorithms
 * Medium (48.55%)
 * Likes:    2572
 * Dislikes: 1962
 * Total Accepted:    215.1K
 * Total Submissions: 443.1K
 * Testcase Example:  '"RD"'
 *
 * In the world of Dota2, there are two parties: the Radiant and the Dire.
 *
 * The Dota2 senate consists of senators coming from two parties. Now the
 * Senate wants to decide on a change in the Dota2 game. The voting for this
 * change is a round-based procedure. In each round, each senator can exercise
 * one of the two rights:
 *
 *
 * Ban one senator's right: A senator can make another senator lose all his
 * rights in this and all the following rounds.
 * Announce the victory: If this senator found the senators who still have
 * rights to vote are all from the same party, he can announce the victory and
 * decide on the change in the game.
 *
 *
 * Given a string senate representing each senator's party belonging. The
 * character 'R' and 'D' represent the Radiant party and the Dire party. Then
 * if there are n senators, the size of the given string will be n.
 *
 * The round-based procedure starts from the first senator to the last senator
 * in the given order. This procedure will last until the end of voting. All
 * the senators who have lost their rights will be skipped during the
 * procedure.
 *
 * Suppose every senator is smart enough and will play the best strategy for
 * his own party. Predict which party will finally announce the victory and
 * change the Dota2 game. The output should be "Radiant" or "Dire".
 *
 *
 * Example 1:
 *
 *
 * Input: senate = "RD"
 * Output: "Radiant"
 * Explanation:
 * The first senator comes from Radiant and he can just ban the next senator's
 * right in round 1.
 * And the second senator can't exercise any rights anymore since his right has
 * been banned.
 * And in round 2, the first senator can just announce the victory since he is
 * the only guy in the senate who can vote.
 *
 *
 * Example 2:
 *
 *
 * Input: senate = "RDD"
 * Output: "Dire"
 * Explanation:
 * The first senator comes from Radiant and he can just ban the next senator's
 * right in round 1.
 * And the second senator can't exercise any rights anymore since his right has
 * been banned.
 * And the third senator comes from Dire and he can ban the first senator's
 * right in round 1.
 * And in round 2, the third senator can just announce the victory since he is
 * the only guy in the senate who can vote.
 *
 *
 *
 * Constraints:
 *
 *
 * n == senate.length
 * 1 <= n <= 10^4
 * senate[i] is either 'R' or 'D'.
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Complexity
    // Time: O(N)
    // Space: O(N)
    string predictPartyVictory(string senate) {
        // Two queues to keep track of remaining senate members
        std::queue<uint32_t> radiant, dire;

        const auto round_sz = senate.size();
        for (size_t i = 0; i < round_sz; ++i) {
            // Fill queues with respective order the each senator
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        // Simulate voting rounds
        while (!radiant.empty() && !dire.empty()) {
            // Fetch the senators orders, determine who goes first, and ban the other
            const auto radiant_order = radiant.front();
            const auto dire_order = dire.front();

            radiant.pop();
            dire.pop();

            if (radiant_order < dire_order) {
                // Radiant goes first, bans dire, and advances to the next round
                radiant.push(radiant_order + round_sz);
            } else {
                // Dire goes first, bans radiant, and advances to the next round
                dire.push(dire_order + round_sz);
            }
        }

        return radiant.size() > dire.size() ? "Radiant" : "Dire";
    }
};
// @lc code=end
