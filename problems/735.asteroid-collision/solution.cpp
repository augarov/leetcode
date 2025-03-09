/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 *
 * https://leetcode.com/problems/asteroid-collision/description/
 *
 * algorithms
 * Medium (44.94%)
 * Likes:    8358
 * Dislikes: 1169
 * Total Accepted:    668.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '[5,10,-5]'
 *
 * We are given an array asteroids of integers representing asteroids in a row.
 * The indices of the asteriod in the array represent their relative position
 * in space.
 *
 * For each asteroid, the absolute value represents its size, and the sign
 * represents its direction (positive meaning right, negative meaning left).
 * Each asteroid moves at the same speed.
 *
 * Find out the state of the asteroids after all collisions. If two asteroids
 * meet, the smaller one will explode. If both are the same size, both will
 * explode. Two asteroids moving in the same direction will never meet.
 *
 *
 * Example 1:
 *
 *
 * Input: asteroids = [5,10,-5]
 * Output: [5,10]
 * Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never
 * collide.
 *
 *
 * Example 2:
 *
 *
 * Input: asteroids = [8,-8]
 * Output: []
 * Explanation: The 8 and -8 collide exploding each other.
 *
 *
 * Example 3:
 *
 *
 * Input: asteroids = [10,2,-5]
 * Output: [10]
 * Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide
 * resulting in 10.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= asteroids.length <= 10^4
 * -1000 <= asteroids[i] <= 1000
 * asteroids[i] != 0
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Complexity
    // Time: O(n)
    // Space: O(1)
    vector<int> asteroidCollision(vector<int>& asteroids) {
        size_t top = 0;
        for (auto a : asteroids) {
            if (a > 0) {
                // Push asteroids moving right on the top of the stack
                asteroids[top++] = a;
            } else {
                // Asteroids moving left destroy all the smaller ones in their way
                while (top > 0 && asteroids[top - 1] > 0 && asteroids[top - 1] < -a) {
                    --top;
                }
                if (top == 0 || asteroids[top - 1] < 0) {
                    // Stack is empty or previous asteroid is moving left
                    // Push the new one on top
                    asteroids[top++] = a;
                } else if (asteroids[top - 1] == -a) {
                    // Asteroids destroy each other
                    --top;
                }
            }
        }
        asteroids.resize(top);
        return asteroids;
    }
};
// @lc code=end
