#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
public:
    bool bfs(int i, vector<vector<int>>& graph, vector<int>& vis)
    {
        vis[i] = 1;
        queue<pair<int,int>> q;
        q.push({i,1});

        while(!q.empty())
        {
            auto[node,color] = q.front();
            q.pop();
            for(auto neighbor : graph[node])
            {
                if(vis[neighbor] == 0)
                {
                    if(color == 1)
                    {
                        vis[neighbor] = 2;
                        q.push({neighbor,2});
                    }
                    else{
                        vis[neighbor] = 1;
                        q.push({neighbor,1});
                    }
                }
                else if(color == vis[neighbor])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(int node,  vector<vector<int>>& graph, vector<int>& vis, int color){
        if(color == 1) vis[node] = 2;
        else  vis[node] = 1;
        for(auto neighbor : graph[node]){
            if(vis[neighbor] == 0){
                if(!dfs(neighbor, graph, vis, vis[node])){
                    return false;
                }
            }
            else if(vis[neighbor] == vis[node]){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph)
    {
        vector<int> vis(graph.size(),0);

        for(int i = 0; i < graph.size(); i++)
        {
            if(vis[i] == 0)
            {
                if(!dfs(i,graph,vis,0))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

