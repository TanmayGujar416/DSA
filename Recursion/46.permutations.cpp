#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<bool> used(nums.size());
        vector<vector<int>> ans;
        f(ds, nums, used, ans);
        return ans;
    }

    void f(vector<int>& ds, vector<int>& nums,vector<bool>& used,vector<vector<int>>& ans)
    {
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;
            ds.push_back(nums[i]);
            used[i] = true;
            f(ds, nums, used, ans);
            ds.pop_back();
            used[i] = false;
        }
    }
};
// @lc code=end

