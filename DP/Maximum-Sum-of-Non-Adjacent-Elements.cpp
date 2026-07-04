#include <bits/stdc++.h>
using namespace std;

// int f(int i, vector<int>& arr) {

//     if(i < 0) return 0;

//     // Pick
//     int pick = arr[i] + f(i-2, arr);
//     // Not Pick
//     int notpick = 0 + f(i-1, arr);
//     // Return answer
//     return max(pick, notpick);
// }

// int maximumNonAdjacentSum(vector<int>& arr) {

//     int n = arr.size();

//     return f(n - 1, arr);
// }

// int f(int i, vector<int>& arr, vector<int>&dp) {

//     if(i < 0) return 0;
//     if(dp[i] != -1) return dp[i];
//     // Pick
//     int pick = arr[i] + f(i-2, arr, dp);
//     // Not Pick
//     int notpick = 0 + f(i-1, arr, dp);
//     // Return answer
//     return dp[i] = max(pick, notpick);
// }

// int maximumNonAdjacentSum(vector<int>& arr) {

//     int n = arr.size();
//     vector<int> dp(arr.size(), -1);

//     return f(n - 1, arr, dp);
// }

// int maximumNonAdjacentSum(vector<int>& arr) {
//     int n = arr.size();
//     if(n == 0) return 0;
//     vector<int> dp(n);

//     for(int i = 0; i < n; i++){
//
//         int pick;
//         if(i >= 2) pick = arr[i] + dp[i-2];
//         else pick = arr[i];
//         // Not
//         int notpick;
//         if(i>=1) notpick = 0 + dp[i-1];
//         else notpick = 0;
//         // Return answer
//         dp[i] = max(pick, notpick);
//     }

//     return dp[n-1];
// }

int maximumNonAdjacentSum(vector<int>& arr) {
    int n = arr.size();
    if(n == 0) return 0;
    if(n == 1) return arr[0];
    int prev2 = arr[0];
    int prev = max(arr[0] ,arr[1]);

    for(int i = 2; i < n; i++){

        int pick = arr[i] + prev2;
        int notpick = prev;
        int curr = max(pick, notpick);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main() {

    vector<int> arr = {2, 1, 4, 9};

    cout << maximumNonAdjacentSum(arr);

    return 0;
}