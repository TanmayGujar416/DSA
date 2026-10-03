#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, int vis[], int vpath[], vector<vector<int>>& adj)
{
  vis[i] = 1;
  vpath[i] = 1;

  for(auto it : adj[i]){
      if(!vis[it]){
        if(dfs(it, vis, vpath,adj))
          return true;
      }
      else if(vpath[it] !=0){
        return true;
      }
  }
  vpath[i] = 0;
  return false;
}
bool iscycle(int V, vector<vector<int>>& adj)
{
  int vis[V] = {0};
  int vpath[V] = {0};
  for(int i = 0; i < V; i++){
    if(!vis[i]){
      if(dfs(i, vis, vpath,adj)){
        return true;
      }
    }
  }
  return false;
}

int main() {
    // Test Case 1: Graph WITH a cycle (0 -> 1 -> 2 -> 0)
    int V1 = 4;
    vector<vector<int>> adj1(V1);
    adj1[0] = {1};
    adj1[1] = {2};
    adj1[2] = {0, 3}; // Edge 2 -> 0 completes the cycle

    cout << "Test 1 (Graph with cycle): ";
    if (iscycle(V1, adj1)) {
        cout << "Cycle Detected! (Correct)" << endl;
    } else {
        cout << "No Cycle Detected! (Incorrect)" << endl;
    }

    // Test Case 2: DAG - Directed Acyclic Graph (0 -> 1, 0 -> 2, 1 -> 2)
    int V2 = 3;
    vector<vector<int>> adj2(V2);
    adj2[0] = {1, 2};
    adj2[1] = {2};

    cout << "Test 2 (Graph without cycle): ";
    if (iscycle(V2, adj2)) {
        cout << "Cycle Detected! (Incorrect)" << endl;
    } else {
        cout << "No Cycle Detected! (Correct)" << endl;
    }

    return 0;
}