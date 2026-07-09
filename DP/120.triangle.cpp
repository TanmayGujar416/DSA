#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> front(triangle.size()), curr(triangle.size());

        for(int j = 0; j < triangle.size(); j++){
            front[j] = triangle[triangle.size() - 1][j];
        }

        for(int i = triangle.size() - 2; i >= 0; i--){
            for(int j = i; j >=0; j--){
                int down = triangle[i][j] + front[j];
                int dignal = triangle[i][j] + front[j+1];
                curr[j] = min(down, dignal);
            }
            front = curr;
        }
        return front[0];
    }
};
// @lc code=end

// int f(int i, int j, vector<vector<int>>& triangle,  vector<vector<int>>& dp){
//         if(i == triangle.size() - 1) return triangle[i][j];
//         if(dp[i][j] != 1e9) return dp[i][j];
//         int down = triangle[i][j] + f(i+1, j, triangle, dp);
//         int dignal = triangle[i][j] + f(i+1, j+1, triangle, dp);
//         return dp[i][j] = min(down, dignal);
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//         vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),1e9));
//         return f(0, 0, triangle, dp);
//     }


// int minimumTotal(vector<vector<int>>& triangle) {
//     vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size()));

//     for(int j = 0; j < triangle.size(); j++){
//         dp[triangle.size() - 1][j] = triangle[triangle.size() - 1][j];
//     }

//     for(int i = triangle.size() - 2; i >= 0; i--){
//         for(int j = i; j >=0; j--){
//             int down = triangle[i][j] + dp[i+1][j];
//             int dignal = triangle[i][j] + dp[i+1][j+1];
//             dp[i][j] = min(down, dignal);
//         }
//     }
//     return dp[0][0];
// }