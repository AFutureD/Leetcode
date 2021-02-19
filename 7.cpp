/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * Source : https://leetcode.com/problems/reverse-integer/description/
 * Author : AFuture
 * Date   : 2021-02-18T13:39
 *
 * algorithms
 * Easy (25.90%)
 * Total Accepted:    1.4M
 * Total Submissions: 5.4M
 * Testcase Example:  '123'
 *
 */

#include "0_pre.h"

// #define INT_MAX     2147483647
// #define INT_MIN     (-INT_MAX - 1)

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x) {
            if(ans > INT_MAX / 10 || ans < INT_MIN / 10)
                return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};

#define TEST(n, e)  printf("%12d  =>  %-12d    %s!\n",  n, s.reverse(n),  e == s.reverse(n)?"passed":"failed")

int main() {
    Solution s;
     //basic cases
    TEST(  123,  321);
    TEST( -123, -321);
    TEST( -100,   -1);
    TEST( 1002, 2001);
    //big integer
    TEST( 1463847412,  2147483641);
    TEST(-2147447412, -2147447412);
    TEST( 2147447412,  2147447412);
    //overflow
    TEST( 1000000003, 0);
    TEST( 2147483647, 0);
    TEST(-2147483648, 0);

    return 0;
}
