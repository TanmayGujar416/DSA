#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<int> ds;
        vector<vector<int>> ans;
        f(0, nums, ds, ans, n);
        return ans;
    }

    void f(int i, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, int n){
        ans.push_back(ds);
        if(i >= n){
            return;
        }
        for(int in = i; in < n; in++){
            if(in > i && nums[in] == nums[in-1]) continue;

            ds.push_back(nums[in]);
            f(in + 1, nums, ds, ans, n);
            ds.pop_back();
        }
    }
};
// @lc code=end

