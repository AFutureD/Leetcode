/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * Source : https://leetcode.com/problems/palindrome-number/description/
 * Author : AFuture
 * Date   : 2021-02-18T14:28
 *
 * algorithms
 * Easy (49.70%)
 * Total Accepted:    1.2M
 * Total Submissions: 2.3M
 * Testcase Example:  '121'
 *
 */

#include "0_pre.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        int len = 1;
        while( x / len >= 10 ) len *= 10;
        // cout <<  len << endl;
        
        while( x ){
            if(x / len != x % 10)
                return false;
            
            x = (x % len) / 10; len /= 100;
        }
        return true;
    }
};

#define TEST(n)  printf("%12d is %d\n", n, s.isPalindrome(n) )

int main(){
    Solution s;
    TEST(0);
    TEST(-101);
    TEST(1001);
    TEST(1234421);
    TEST(1234321);
    TEST(2147447412);
    TEST(INT_MAX);
}