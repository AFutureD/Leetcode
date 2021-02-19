/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * Source : https://leetcode-cn.com/problems/longest-common-prefix/description/
 * Author : AFuture
 * Date   : 2021-02-19T13:05
 *
 * algorithms
 * Easy (39.21%)
 * Total Accepted:    448.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 */

#include "0_pre.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size())
            return "";
        
        int length = strs[0].size();
        int count = strs.size();
        for (int i = 0; i < length; ++i) {
            char c = strs[0][i];
            for (int j = 1; j < count; ++j) {
                if (i == strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

int main() {
    // const char* s[] = {"abab","aba","abc"};
    Solution s;
    vector<string> v = {"flower","flow","flight"};
    cout << "LCP: " << s.longestCommonPrefix(v) << endl;
    v = {"dog","racecar","car"};
    cout << "LCP: " << s.longestCommonPrefix(v) << endl;
    return 0;
}