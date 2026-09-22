#include <bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int>& vis, vector<vector<int>>& adj){
  vis[src] = 1;
  queue<pair<int, int>> q;
  q.push({src, -1});

  while(!q.empty()){
    auto[node, parent] = q.front();
    q.pop();
    for(auto neighbor : adj[node]){
      if(!vis[neighbor]){
        vis[neighbor] = 1;
        q.push({neighbor,node});
      }
      else if(neighbor!= parent){
        return true;
      }
    }
    return false;
  }
}

bool dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj){
  vis[node] = 1;
  for(auto neighbor: adj[node])
  {
    if(!vis[neighbor])
    {
      if(dfs(neighbor, node, vis, adj)) return true;
    }
    else if(neighbor!= parent){
      return true;
    }
  }
  return false;
}
bool iscycle(int V, vector<vector<int>>& adj){
  vector<int> vis(V, 0);

  for(int i = 0; i < V; i++){
    if(!vis[i]){
      if(dfs(i, -1, vis, adj)){
        return true;
      }
    }
  }
  return false;
}
