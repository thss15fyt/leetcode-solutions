/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (42.57%)
 * Total Accepted:    543.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */

#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        stack<int> s;
        queue<int> q;
        while(x > 0) {
            int digit = x % 10;
            x /= 10;
            s.push(digit);
            q.push(digit);
        }
        int len = s.size();
        while(!s.empty() && !q.empty()) {
            int d1 = s.top();
            int d2 = q.front();
            s.pop();
            q.pop();
            if (d1 != d2) 
                return false;
            if (s.size() <= len / 2)
                return true;
        }
        
        return true;
    }
};

