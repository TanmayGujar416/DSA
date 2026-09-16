#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int data;
  TreeNode* left;
  TreeNode* right;
};

vector<int> preOrder(TreeNode* root){
  vector<int> preOrder;
  stack<TreeNode*>st;
  if(root == NULL) return preOrder;
  st.push(root);
  while(!st.empty()){
    root = st.top();
    st.pop();
    preOrder.push_back(root->data);

    if(root->left != NULL){

    }
  }
}