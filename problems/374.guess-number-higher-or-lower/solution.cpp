/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower/description/
 *
 * algorithms
 * Easy (55.21%)
 * Likes:    3950
 * Dislikes: 607
 * Total Accepted:    806.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '10\n6'
 *
 * We are playing the Guess Game. The game is as follows:
 *
 * I pick a number from 1 to n. You have to guess which number I picked.
 *
 * Every time you guess wrong, I will tell you whether the number I picked is
 * higher or lower than your guess.
 *
 * You call a pre-defined API int guess(int num), which returns three possible
 * results:
 *
 *
 * -1: Your guess is higher than the number I picked (i.e. num > pick).
 * 1: Your guess is lower than the number I picked (i.e. num < pick).
 * 0: your guess is equal to the number I picked (i.e. num == pick).
 *
 *
 * Return the number that I picked.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 10, pick = 6
 * Output: 6
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1, pick = 1
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: n = 2, pick = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2^31 - 1
 * 1 <= pick <= n
 *
 *
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    // Complexity
    // Time: O(logN)
    // Space: O(1)
    int guessNumber(int n) {
        auto guess_range = std::pair{1, n};
        while (guess_range.first < guess_range.second) {
            // the middle of guess range
            const auto my_guess = guess_range.first / 2 + guess_range.second / 2;

            const auto res = guess(my_guess);
            if (res < 0) {
                // my_guess > picked number
                guess_range.second = my_guess - 1;
            } else if (res > 0) {
                // my_guess < picked number
                guess_range.first = my_guess + 1;
            } else {
                // guessed right
                return my_guess;
            }
        }
        return guess_range.first;
    }
};
// @lc code=end
