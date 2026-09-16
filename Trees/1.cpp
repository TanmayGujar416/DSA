#include <bits/stdc++.h>
using namespace std;
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
};

Node* newNode(int value){
  Node* newNode = new Node();

  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;
}