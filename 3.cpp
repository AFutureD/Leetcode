/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * Source : https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 * Author : AFuture
 * Date   : 2021-02-22T10:57
 *
 * algorithms
 * Medium (36.42%)
 * Total Accepted:    836.9K
 * Total Submissions: 2.3M
 * Testcase Example:  '"abcabcbb"'
 *
 */

#include "0_pre.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, maxStr = 0, m[128];
        for(int i = 0; i < 128; i++) m[i] = -1;
        while( r < s.size() ){
            if(m[(int)s[r]] != -1){
                int tmp = l; l = m[s[r]] + 1;
                for(int i = tmp; i < l; i++) m[(int)s[i]] = -1 ;
            } else {
                m[(int)s[r]] = r ;
                maxStr = max(maxStr, r - l + 1);
                r++;
            }
        }
        return maxStr;
        
    }
};

#define TEST(n, e)  cout << (e == s.lengthOfLongestSubstring(n) ? "AC" : "WA") << " " << n << " " << s.lengthOfLongestSubstring(n) << endl

int main() {
    Solution s;
    TEST("abcabcbb", 3);
    TEST("bbbbb", 1);
    TEST("pwwkew", 3);
    TEST("abba", 2);
    return 0;
}
