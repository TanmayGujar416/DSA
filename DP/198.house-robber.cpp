#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    int prev2 = nums[0];
    int prev = max(nums[0], nums[1]);

    for(int i = 2; i < n; i++){
        int pick = nums[i] + prev2;
        int notpick = prev;
        int curr= max(pick, notpick);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}
};
// @lc code=end