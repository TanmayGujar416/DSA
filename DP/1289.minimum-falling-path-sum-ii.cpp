#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1289 lang=cpp
 *
 * [1289] Minimum Falling Path Sum II
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<int> prev = grid[0];
        vector<int> curr(n);

        for (int i = 1; i < n; i++) {

            // Find smallest and second smallest values in prev
            int min1 = INT_MAX;
            int min2 = INT_MAX;
            int minIndex = -1;

            for (int j = 0; j < n; j++) {

                if (prev[j] < min1) {
                    min2 = min1;
                    min1 = prev[j];
                    minIndex = j;
                }
                else if (prev[j] < min2) {
                    min2 = prev[j];
                }
            }

            // Compute current row
            for (int j = 0; j < n; j++) {

                if (j == minIndex)
                    curr[j] = grid[i][j] + min2;
                else
                    curr[j] = grid[i][j] + min1;
            }

            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};
// @lc code=end

// Time: O(n³)
// Space: O(n²)
// int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
// if(j < 0 || j >= grid.size()) return 1e9;
// if(i == 0) return grid[0][j];
// if(dp[i][j] != -1) return dp[i][j];
// int mini = 1e9;
// for(int k = 0; k < grid.size(); k++){
//     if(j == k) continue;
//     mini = min(mini, grid[i][j] + f(i-1, k, grid, dp));
// }
// return dp[i][j] = mini;

// }

// int minFallingPathSum(vector<vector<int>>& grid) {
//     int n = grid.size();
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     int mini = INT_MAX;
//     for(int i = 0; i < n; i++){
//         mini = min(mini, f(n-1, i, grid,dp));
//     }
//     return mini;
//     }


// time : O(n⋅(n−1)n)
// space : O(n)
// int f(int i, int j, vector<vector<int>>& grid){
//     if(j < 0 || j >= grid.size()) return 1e9;
//     if(i == 0) return grid[0][j];
//     int mini = 1e9;
//     for(int k = 0; k < grid.size(); k++){
//         if(j == k) continue;
//         mini = min(mini, grid[i][j] + f(i-1, k, grid));
//     }
//     return mini;

//     }

//     int minFallingPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int mini = INT_MAX;
//         for(int i = 0; i < n; i++){
//             mini = min(mini, f(n-1, i, grid));
//         }
//         return mini;
//         }


// time: O(n^3)
// space: O(n^2)
//  int minFallingPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         vector<vector<int>> dp(n, vector<int>(n));

//         for(int j = 0; j < n; j++) dp[0][j]  = grid[0][j];

//         for(int i = 1; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 int mini = 1e9;
//                 for(int k = 0; k < grid.size(); k++){
//                     if(j == k) continue;
//                     mini = min(mini, grid[i][j] + dp[i-1][k]);
//                 }
//                 dp[i][j] = mini;
//             }
//         }
//         int mini = INT_MAX;
//         for(int i = 0; i < n; i++){
//             mini = min(mini, dp[n-1][i]);
//         }
//         return mini;
//         }


// time :O(n³)
// space : O(n)
// int minFallingPathSum(vector<vector<int>>& grid) {
//     int n = grid.size();
//     vector<int> prev(n);
//     vector<int> curr(n);
//     for(int j = 0; j < n; j++) prev[j]  = grid[0][j];

//     for(int i = 1; i < n; i++){
//         for(int j = 0; j < n; j++){
//             int mini = 1e9;
//             for(int k = 0; k < n; k++){
//                 if(j == k) continue;
//                 mini = min(mini, grid[i][j] + prev[k]);
//             }
//             curr[j] = mini;
//         }
//         prev = curr;
//     }
//     int mini = INT_MAX;
//     for(int i = 0; i < n; i++){
//         mini = min(mini, prev[i]);
//     }
//     return mini;
//     }