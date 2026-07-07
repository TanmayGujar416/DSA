#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> curr(n);
        vector<int> prev(n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
               if(i == 0 && j == 0){
                    curr[0] = grid[i][j];
                    continue;
                }
                int up = 1e9;
                int left = 1e9;

                if(i > 0)
                    up = grid[i][j] + prev[j];

                if(j > 0)
                    left = grid[i][j] + curr[j-1];

                curr[j] = min(up, left);
            }
            prev = curr;
        }
        return curr[n-1];

    }
};
// @lc code=end

