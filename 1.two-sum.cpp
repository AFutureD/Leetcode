/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * Source : https://leetcode.com/problems/two-sum/description/
 * Author : AFuture
 * Date   : 2021-02-12T17:37:30.135Z
 * algorithms
 * Easy (46.39%)
 * Total Accepted:    3.8M
 * Total Submissions: 8.3M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 */

#include "0_pre.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;  // hashtable search t with o(1).
        for (int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            if (m.count(t)) return { m[t], i };
            m[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> p0 = {19,22,11};
    int p1 = 33;
    auto res = s.twoSum(p0,p1);
    cout << res << endl;
    return 0;
}
