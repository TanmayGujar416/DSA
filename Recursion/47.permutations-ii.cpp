#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<int> ds;
        vector<bool> used(nums.size());
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
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
            if(i > 0 && nums[i] == nums[i-1] && !used[i - 1]) continue;
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

