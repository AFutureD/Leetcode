/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 *
 * Source : https://leetcode-cn.com/problems/roman-to-integer/description/
 * Author : AFuture
 * Date   : 2021-02-19T12:26
 *
 * algorithms
 * Easy (62.42%)
 * Total Accepted:    320.5K
 * Total Submissions: 513.5K
 * Testcase Example:  '"III"'
 *
 */

#include "0_pre.h"

class Solution {
public:
    int romanToInt(string s) {
        if( s.size() <= 0) return 0;
        unordered_map<string, int> m = {{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, 
                                        {"C", 100}, {"D", 500}, {"M", 1000}};
        int ans = m[s.substr(0,1)];
        for(int i = 1; i < s.size(); i++){
            int p = m[s.substr(i - 1, 1)];
            int c = m[s.substr(i, 1)];

            ans += p >= c ? c : c - 2 * p;

        }
        return ans;
    }
};

#define TEST(n,e)  printf("%15s -> %15d    %s\n", n, s.romanToInt(n), e == s.romanToInt(n)?"AC":"WA" )


int main() {
    Solution s;
    TEST("III", 3);
    TEST("IV", 4);
    TEST("IX", 9);
    TEST("LVIII", 58);
    TEST("MCMXCIV", 1994);
    TEST("XLIX", 49);
    TEST("CMXCIX", 999);
    return 0;
}