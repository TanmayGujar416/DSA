#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
class Solution {
public:
    int find(int node, vector<int>& parent){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = find(parent[node], parent);
    }
    bool union_set(int u, int v,  vector<int>& parent,  vector<int>& rank){
        int ul_u = find(u,parent);
        int ul_v = find(v,parent);
        if(ul_u == ul_v){
            return true;
        }
        if(rank[ul_u] > rank[ul_v]){
            parent[ul_v] = ul_u;
            rank[ul_u]++;
        }
        else{
            parent[ul_u] = ul_v;
            rank[ul_v]++;
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1);
        vector<int> rank(edges.size()+1, 0);
        for(int i = 1; i < edges.size(); i++){
            parent[i] = i;
        }
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(union_set(u,v, parent, rank)){
                return {u,v};
            }
        }
        return {};
    }
};
// @lc code=end

