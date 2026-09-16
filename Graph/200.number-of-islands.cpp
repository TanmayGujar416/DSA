#include<bits/stdtr1c++.h>
using namespace std;
/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:

    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // traverse all th neighbors
            for(int delrow = -1; delrow <= 1; delrow++){
                for(int delcol = -1; delcol <= 1; delcol++){
                    if(delrow == 0 || delcol == 0){
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if(nrow >= 0 && nrow<grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] == '1' && !visited[nrow][ncol]){
                        visited[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
                }
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),0));
        int cnt = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(!visited[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i, j, grid, visited);
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

