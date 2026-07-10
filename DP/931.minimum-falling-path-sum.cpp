#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n);
        vector<int> curr(n);
        for(int j = 0; j < n; j++) prev[j] = matrix[0][j];

        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                int ld = 1e9;
                int rd = 1e9;
                int st = matrix[i][j] + prev[j];
                if(j>0) ld = matrix[i][j] + prev[j-1];
                if(j < n-1) rd = matrix[i][j] + prev[j+1];
                curr[j] = min(st, min(ld,rd));
            }
            prev = curr;
        }

        int mini = INT_MAX;
        for(int j = 0; j < n; j++){
            mini = min(mini, prev[j]);
        }
        return mini;
    }
};
// @lc code=end

// Time:    O(3^n)
// Space:   O(n) recursion stack.
// int f(int i, int j, vector<vector<int>>& matrix){
//     if(j < 0 || j >= matrix.size()) return 1e9;
//     if(i == 0) return matrix[0][j];
//     int st = matrix[i][j] + f(i-1, j, matrix);
//     int ld = matrix[i][j] + f(i-1, j-1, matrix);
//     int rd = matrix[i][j] + f(i-1, j+1, matrix);
//     return min(st, min(ld,rd));

// }

// int minFallingPathSum(vector<vector<int>>& matrix) {
//     int n = matrix.size();
//     int mini = INT_MAX;
//     for(int i = 0; i < n; i++){
//         mini = min(mini, f(n-1, i, matrix));
//     }
//     return mini;
// }

// time : O(n^2)
// space : O(n^2) + O(n)
// int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
//         if(j < 0 || j >= matrix.size()) return 1e9;
//         if(i == 0) return matrix[0][j];
//         if(dp[i][j] != -1) return dp[i][j];
//         int st = matrix[i][j] + f(i-1, j, matrix, dp);
//         int ld = matrix[i][j] + f(i-1, j-1, matrix, dp);
//         int rd = matrix[i][j] + f(i-1, j+1, matrix, dp);
//         return dp[i][j] = min(st, min(ld,rd));

//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         int mini = INT_MAX;
//         for(int i = 0; i < n; i++){
//             mini = min(mini, f(n-1, i, matrix, dp));
//         }
//         return mini;
//     }


// int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int>> dp(n, vector<int>(n));
//         for(int j = 0; j < n; j++) dp[0][j] = matrix[0][j];

//         for(int i = 1; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 int ld = 1e9;
//                 int rd = 1e9;
//                 int st = matrix[i][j] + dp[i-1][j];
//                 if(j>0) ld = matrix[i][j] + dp[i-1][j-1];
//                 if(j < n-1) rd = matrix[i][j] + dp[i-1][j+1];
//                 dp[i][j] = min(st, min(ld,rd));
//             }
//         }


//         int mini = INT_MAX;
//         for(int i = 0; i < n; i++){
//             mini = min(mini, dp[n-1][i]);
//         }
//         return mini;
//     }