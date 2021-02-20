/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * Source : https://leetcode-cn.com/problems/valid-parentheses/description/
 * Author : AFuture
 * Date   : 2021-02-20T10:35
 *
 * algorithms
 * Easy (43.72%)
 * Total Accepted:    530.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '"()"'
 *
 */

#include "0_pre.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for(int i = 0;i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{' ){
                S.push(s[i]);
            } else {
                if(S.empty() || !isPair(S.top(),s[i]))
                    return false;
                S.pop();
            }
        }
        if(S.empty()) return true;
        else return false;
    }

    bool isPair(char a, char b){
        if(a == '(' && b == ')') return true;
        else if(a == '[' && b == ']') return true;
        else if(a == '{' && b == '}') return true;

        return false;
    }   
};

#define TEST(n, e)  cout << (e == s.isValid(n) ? "AC" : "WA") << " " << n << " " << s.isValid(n) << endl

int main() {
    Solution s;
    string n = "()";
    TEST("()", true);
    TEST("()[]{}", true);
    TEST("(]", false);
    TEST("([)]", false);
    TEST("{[]}", true);
    TEST("[]}}", false);
    TEST("[", false);
    cout << "END" << endl;
    return 0;

}
