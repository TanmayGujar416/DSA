#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<int> dp(n, 1);
//         for(int i = 1; i < m; i++){
//             for(int j = 1; j < n; j++){
//                 dp[j] = dp[j] + dp[j-1];
//             }
//         }
//         return dp[n-1];
//     }
// };

class Solution {
public:
    int uniquePaths(int m, int n) {

        int N = m + n - 2;
        int r = min(m - 1, n - 1);

        long long ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (N - r + i);
            ans = ans / i;
        }

        return (int)ans;
    }
};
// @lc code=end

