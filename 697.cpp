/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 *
 * Source : https://leetcode-cn.com/problems/degree-of-an-array/description/
 * Author : AFuture
 * Date   : 2021-02-20T08:02
 *
 * algorithms
 * Easy (55.26%)
 * Total Accepted:    45.7K
 * Total Submissions: 77K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 */

#include "0_pre.h"

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, pair<int, int> > m; // pair.first: cnt; pair.second: first pos;
        int cnt = 0, ans = 999999;
        for(int i = 0; i < nums.size(); i++){
            int cur =  nums[i];

            m[cur] = { m[cur].first + 1, m[cur].first ? m[cur].second : i};

            int len = i - m[cur].second + 1;
            
            if (cnt <= m[cur].first){
                ans = (cnt == m[cur].first) ? min(len, ans) : len;
                cnt = m[cur].first;
            }
            
        }
        return ans;
    }
};

void Test(vector<int> n, int e){
    Solution s;
    cout << n << " -> " << s.findShortestSubArray(n) << "  " << (e == s.findShortestSubArray(n)?"AC":"WA") << endl;
}

int main() {
    // Solution s;
    vector<int> n = {1, 2, 2, 3, 1}; int e = 2;
    Test(n, e);

    n = {1,2,2,3,1,4,2}; e = 6;
    Test(n,e);

    return 0;
}