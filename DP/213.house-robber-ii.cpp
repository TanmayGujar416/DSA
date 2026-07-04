#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int f(vector<int>& nums,int start, int end) {
    if(end - start == 1) return nums[start];
    int prev2 = nums[start];
    int prev = max(nums[start], nums[start + 1]);

    for(int i = start + 2; i < end; i++){
        int pick = nums[i] + prev2;
        int notpick = prev;
        int curr= max(pick, notpick);
        prev2 = prev;
        prev = curr;
    }

    return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int first = f(nums, 0, n-1);
        int last = f(nums, 1, n);
        return max(first, last);
    }
};
// @lc code=end

