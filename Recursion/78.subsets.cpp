#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        f(0, nums, ds, n, ans);
        return ans;
    }
    void  f(int i, vector<int>& nums, vector<int>& ds, int n, vector<vector<int>>& ans){
        if(i >= n){
            ans.push_back(ds);
            return;
        }
        //take
        ds.push_back(nums[i]);
        f(i + 1, nums, ds, n, ans);

        //dont take
        ds.pop_back();
        f(i + 1, nums, ds, n, ans);
    }

};
// @lc code=end

