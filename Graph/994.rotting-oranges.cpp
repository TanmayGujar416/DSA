#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minute = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int size = q.size();
            bool isdone = false;
            for(int i = 0; i< size; i++){
                auto [r,c] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nrow = r + drow[i];
                    int ncol = c + dcol[i];

                    if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        q.push({nrow,ncol});
                        isdone = true;
                    }
                }
            }
            if(isdone)
                minute++;
        }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(grid[i][j] == 1){
                return -1;
            }
        }
    }
    return minute;
    }
};
// @lc code=end

