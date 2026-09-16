#include<bits/stdtr1c++.h>
using namespace std;

/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited){
        visited[node] = true;

        for(int neighbor = 0; neighbor < isConnected.size(); ++neighbor){
            if(isConnected[node][neighbor] == 1 && !visited[neighbor]){
                dfs(neighbor,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<bool> visited(isConnected.size(),0);
        for(int node = 0; node < isConnected.size(); ++node){
            if(!visited[node]){
                dfs(node,isConnected,visited);
                count++;            }
        }
        return count;
    }
};
// @lc code=end

