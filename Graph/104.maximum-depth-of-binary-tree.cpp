#include<bits/stdtr1c++.h>
using namespace std;

/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while(!q.empty()){
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }

            }
            depth++;
        }
        return depth;
    }
};
// @lc code=end

