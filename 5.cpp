/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * Source : https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 * Author : AFuture
 * Date   : 2021-02-24T10:51
 *
 * algorithms
 * Medium (33.11%)
 * Total Accepted:    484.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '"babad"'
 *
 */

#include "0_pre.h"

class Solution {
public:
    string longestPalindrome(string s) {
        // return longestPalindrome_DP(s);
        return manacher(s);
    }

    // DP Simple
    string longestPalindrome_DP(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                } else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }

    string manacher(string s) {
        string str = "#";
        
        if (s.size() <= 1)  return s;

        for (int i = 0; i < s.size(); ++i) {
            str += s[i];
            str += "#";
        }
        
        int maxLen = 1, start = 0;
        for (int i = 0; i < 2 * s.size() + 1; i++) {
            int l = i, r = i, curLen = 0;
            while(--l >= 0 && ++r < str.size() && str[l] == str[r]) curLen++;

            if (curLen > maxLen) {
                maxLen = curLen;
                start = (i - maxLen) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};


#define TEST(n, e)  cout << (e == s.longestPalindrome(n) ? "AC" : "WA") << " " << n << " " << s.longestPalindrome(n) << endl

int main() {
    Solution s;
    TEST("babad", "bab");
    TEST("cbbd", "bb");
    TEST("a", "a");
    TEST("ac", "a");
    return 0;
}
