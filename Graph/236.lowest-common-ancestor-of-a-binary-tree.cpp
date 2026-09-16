#include<bits/stdtr1c++.h>
using namespace std;
// function findLCA(NODE, P, Q) {

//     // 1. THE BASE CASE (Did we find them or hit a dead end?)
//     IF NODE is NULL:
//         RETURN NULL
//     IF NODE == P or NODE == Q:
//         RETURN NODE

//     // 2. THE SEARCH (You got this part exactly right!)
//     LEFT = findLCA(NODE->LEFT, P, Q)
//     RIGHT = findLCA(NODE->RIGHT, P, Q)

//     // 3. THE INTERSECTION (You also got this exactly right!)
//     IF LEFT found someone AND RIGHT found someone:
//         RETURN NODE

//     // 4. THE "PASS IT UP" (Fixing your Else block)
//     // We don't search again. We just pass up whoever found something.
//     IF LEFT found someone:
//         RETURN LEFT
//     ELSE:
//         RETURN RIGHT
// }
/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left != NULL && right != NULL){
            return root;
        }
        if(left != NULL){
            return left;
        }
        else{
            return right;
        }

    }
};
// @lc code=end

