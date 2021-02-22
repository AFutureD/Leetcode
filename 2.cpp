/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * Source : https://leetcode-cn.com/problems/add-two-numbers/description/
 * Author : AFuture
 * Date   : 2021-02-22T10:43
 *
 * algorithms
 * Medium (39.53%)
 * Total Accepted:    715.1K
 * Total Submissions: 1.8M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 */

#include "0_pre.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = NULL;
        ListNode** pNode = &ans;
        int sum = 0;
        while (l1 != nullptr || l2 != nullptr || sum > 0)
        {
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            *pNode = new ListNode(sum%10);
            sum /= 10;
            pNode = &((*pNode)->next);
        }
        return ans;
    }
};

int main() {

    return 0;
}
