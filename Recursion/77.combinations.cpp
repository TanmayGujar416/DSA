#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> ds;
        vector<vector<int>> ans;
        f(1, n, k, ds, ans);
        return ans;
    }

    void f(int i, int n, int k, vector<int>& ds, vector<vector<int>>& ans){
        if(k == 0){
            ans.push_back(ds);
            return;
        }

        for(int in = i; in <= n - k + 1; in++){
            ds.push_back(in);
            f(in + 1, n, k - 1, ds, ans);
            ds.pop_back();
        }

    }
};
// @lc code=end

