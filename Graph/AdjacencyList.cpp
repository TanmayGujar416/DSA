#include<bits/stdtr1c++.h>
using namespace std;


int V;
vector<vector<int>> adj;

void Graph(int vertices){
  V = vertices;
  adj.resize(V);
}

void addEdge(int src, int des) {
  adj[src].push_back(des);
  adj[des].push_back(src);
}

void display() {
  for (int i = 0; i < V; i++) {
    cout << "Vertex " << i << " is connected to: ";
    for (int neighbor : adj[i]) {
      cout << neighbor << " ";
    }
    cout << endl;
}
}

void bfs(int startvertex){
  vector<bool> visited(V, false);
  queue<int> q;
  visited[startvertex] = true;
  q.push(startvertex);
  while(!q.empty()){
  int current = q.front();
  cout << current << " ";
  q.pop();
  for(int i = 0; i < adj[current].size(); ++i){
    if(visited[adj[current][i]] == false){
      visited[adj[current][i]] = true;
      q.push(adj[current][i]);
    }
  }
  }
  cout << "\n";
}
void dfs(int node, vector<bool> &visited, vector<int> &result){
  visited[node] = true;
  result.push_back(node);

  for(int neighbor : adj[node]){
    if(!visited[neighbor]){
      dfs(neighbor, visited, result);
    }
  }
}
vector<int> traverseDfs(int startvertex){
  vector<bool> visited(V, false);
  vector<int> result;
  dfs(startvertex, visited, result);
  return result;
}



int main() {
    Graph(4);
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 2);
    addEdge(3, 2);
    display();
    cout << "------------------\n";
    bfs(0);
    cout << "DFS Traversal: ";
    vector<int> dfsResult = traverseDfs(0);

    // Loop through the vector to print it
    for (int node : dfsResult) {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}