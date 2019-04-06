/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.23%)
 * Total Accepted:    647.4K
 * Total Submissions: 2.6M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */
class Solution {
public:
    int reverse(int x) {
        if (x == -2147483648)
            return 0;
        bool isNegative = (x < 0);
        int value = x > 0 ? x : -x;
        int result = 0;
        while (value > 0) {
            if ((!isNegative && result > (2147483647 - value % 10) / 10) 
                || (isNegative && result > (2147483648 - value % 10) / 10))
                return 0;
            result = result * 10 + value % 10;
            value /= 10;
        }
        if (isNegative)
            result = -result;
        
        return result;
    }
};

