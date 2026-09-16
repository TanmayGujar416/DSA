#include<bits/stdtr1c++.h>
using namespace std;

int V;
vector<vector<int>> mat;

void Graph(int vertices){
  V = vertices;
  mat.resize(V,vector<int>(V,0));
}

void addEdge(int src, int des) {
    mat[src][des] = 1;
    mat[des][src] = 1;
}

int main() {
    Graph(4);
    addEdge(0, 1);

    cout << "Edge between 0 and 1: " << mat[0][1] << endl;
    return 0;
}