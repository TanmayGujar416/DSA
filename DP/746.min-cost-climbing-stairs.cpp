#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1,-1);

        int prev2 = 0;
        int prev = 0;
        for(int i = 2; i<=cost.size(); i++){
            int left = prev + cost[i-1];

            int right = prev2 + cost[i - 2];

            int curr = min(left, right);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
// @lc code=end

