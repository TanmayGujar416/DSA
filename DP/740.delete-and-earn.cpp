#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        vector<int> points(m + 1);
        for(int i = 0; i < nums.size(); i++){
            points[nums[i]] += nums[i];
        }
        int n = points.size();
        if(n == 1) return points[0];
        int prev2 = points[0];
        int prev = max(points[0], points[1]);

        for(int i = 2; i < n; i++){
            int pick = points[i] + prev2;
            int notpick = prev;
            int curr= max(pick, notpick);
            prev2 = prev;
            prev = curr;
        }

        return prev;

    }
};
// @lc code=end

