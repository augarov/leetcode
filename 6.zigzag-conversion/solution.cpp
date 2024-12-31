/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (50.15%)
 * Likes:    8106
 * Dislikes: 15063
 * Total Accepted:    1.6M
 * Total Submissions: 3.1M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "A", numRows = 1
 * Output: "A"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consists of English letters (lower-case and upper-case), ',' and '.'.
 * 1 <= numRows <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        const int letterZigCount = numRows - 2;
        const int colSize = numRows + letterZigCount;
        const int colCount = s.size() / colSize + ((s.size() % (numRows + letterZigCount)) > 0);

        std::string result;
        result.reserve(s.size());
        
        for (int row = 0; row < numRows; ++row)
        {
            for (int col = 0; col < colCount; ++col)
            {
                auto letterColIndex = row + (numRows + letterZigCount) * col;
                if( letterColIndex < s.size() ) result.push_back( s[letterColIndex] );

                if (row != 0 && row != numRows - 1)
                {
                    auto letterZigIndex = (1 + col * 2) * (numRows + letterZigCount) - letterColIndex;
                    if( letterZigIndex < s.size() ) result.push_back( s[letterZigIndex] );
                }
            }
        }
        return result;
    }
};
// @lc code=end

