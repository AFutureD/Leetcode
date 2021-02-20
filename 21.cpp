/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * Source : https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 * Author : AFuture
 * Date   : 2021-02-20T11:22
 *
 * algorithms
 * Easy (65.34%)
 * Total Accepted:    473.5K
 * Total Submissions: 724.8K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1); // 头节点
        ListNode* cur = ans;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2-> val){
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = (l1 == nullptr ? l2 : l1);
        return ans->next;
    }
};

int main() {

    return 0;
}