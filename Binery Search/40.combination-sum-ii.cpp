#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        f(0, candidates, ds, ans, n, target);

        return ans;
    }

    void f(int i, vector<int>& candi, vector<int>& ds, vector<vector<int>>& ans, int n, int k){
            if(k == 0){
                ans.push_back(ds);
                return;
        }

        for(int in = i; in < n; in++) {
            if (candi[in] > k)
                break;
            if (in > i && candi[in] == candi[in - 1])
                continue;
            ds.push_back(candi[in]);
            f(in + 1, candi, ds, ans, n, k - candi[in]);
            ds.pop_back();
        }
    }
};
// @lc code=end

