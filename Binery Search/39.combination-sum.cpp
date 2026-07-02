#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        int sum = 0;
        f(0, candidates, ds, ans, n, target);

        return ans;
    }

    void f(int i, vector<int>& candi, vector<int>& ds, vector<vector<int>>& ans, int n, int k){
        if(i >= n){
            if(k == 0){
                ans.push_back(ds);
            }
            return;
        }

        if (candi[i] <= k) {
            ds.push_back(candi[i]);
            f(i, candi, ds, ans, n, k - candi[i]);
            ds.pop_back();
        }

        //dont take
        f(i + 1, candi, ds, ans, n, k);

    }
};
// @lc code=end

