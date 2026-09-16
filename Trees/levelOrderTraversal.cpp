#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int data;
  TreeNode* left;
  TreeNode* right;
};

vector<vector<int>> levelOrder(TreeNode* root){
  vector<vector<int>> ans;
  if(root == NULL) return ans;
  queue <TreeNode*> q;
  q.push(root);
  while(!q.empty()){
    int size = q.size();
    vector<int> level;
    for(int i = 0; i < size; i++){
      TreeNode* Node = q.front();
      q.pop();
      if(Node->left != NULL) q.push(Node->left);
      if(Node->right != NULL) q.push(Node->right);
      level.push_back(Node->data);
    }
    ans.push_back(level);
  }
  return ans;
}