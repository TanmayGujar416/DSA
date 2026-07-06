#include <bits/stdc++.h>
using namespace std;

// //Time Complexity: O(3^n)
// // Space Complexity: O(n)
// int maxPoints(int day, int last, vector<vector<int>>& task){
//   if(day < 0){
//     return 0;
//   }
//   int maxi = 0;
//   for(int i = 0; i < 3; i++){
//     if(i != last){
//       int points = task[day][i] + maxPoints(day - 1, i, task);
//       maxi = max(maxi, points);
//     }
//   }
//   return maxi;
// }

//Time Complexity: O(n)
// Space Complexity: O(n)
int maxPoints(int day, int last, vector<vector<int>>& task, vector<vector<int>>& dp){
  dp[0][0] = max(task[0][1], task[0][2]);
  dp[0][1] = max(task[0][0], task[0][2]);
  dp[0][2] = max(task[0][1], task[0][0]);

}

int main(){
  cout << "Program started\n";
  vector<vector<int>> task = {{10,20,30},
                              {100,50,40}};

  vector<vector<int>> dp(task.size(), vector<int>(4, -1));
  cout << maxPoints(1, 3, task, dp);
  return 0;
}