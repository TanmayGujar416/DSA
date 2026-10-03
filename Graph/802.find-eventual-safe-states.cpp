#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
class Solution {
public:

    bool dfs(int node, vector<int>& vis, vector<vector<int>>& graph)
    {
        if(graph[node].empty())
        {
            vis[node] = 2;
            return true;
        }
        vis[node] = 1;
        bool issafe = true;
        for(auto it : graph[node])
        {
            if(!vis[it]){
                issafe &= dfs(it, vis, graph);
            }
            else
            {
                issafe = false;
            }
        }
        if(issafe){
            vis[node] = 2;
            return true;
        }
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        vector<int> safe;
        int V = graph.size();
        vector<int> vis(V,0);// 0 not vis .. 1 vis .. 2 safe
        for(int i = 0; i < V; i++){
            if(vis[i] == 2)
            {
                safe.push_back(i);
            }
            else if(vis[i] == 0){
                if(dfs(i,vis,graph))
                {
                    safe.push_back(i);
                }
            }
        }
        return safe;
    }
};
// @lc code=end

