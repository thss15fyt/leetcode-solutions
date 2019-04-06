/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (30.83%)
 * Total Accepted:    815.3K
 * Total Submissions: 2.6M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *num1 = l1, *num2 = l2, *p, *q, *head;
        p = q = head = NULL;
        bool flag = false;
        while(num1 != NULL && num2 != NULL) {
            int sum = num1->val + num2->val + (flag ? 1 : 0);
            flag = (sum > 9);
            p = new ListNode(sum % 10);
            if(!head) head = p;
            else q->next = p;
            q = p;
            num1 = num1->next;
            num2 = num2->next;
        }
        num1 = (num1 != NULL) ? num1 : num2;
        while(num1 != NULL) {
            int num = num1->val + (flag ? 1 : 0);
            flag = (num > 9);
            p = new ListNode(num % 10);
            if(!head) head = p;
            else q->next = p;
            q = p;
            num1 = num1->next;
        }
        if(flag) {
            p = new ListNode(1);
            q->next = p;
        }
        return head;
    }
};

