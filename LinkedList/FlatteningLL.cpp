#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printBottom(Node* head){

  Node* temp = head;
  while(temp){
    cout << temp->data << " ";
    temp = temp->bottom;
  }
}

Node* convertArr2LL(vector<int> arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;

  for(int i = 1; i < arr.size(); i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}

Node* merge(Node* a, Node* b) {
  Node* dummyNode = new Node(-1);
  Node* result = dummyNode;
  while(a != NULL && b!=NULL){
    if(a->data <b->data){
      result->bottom = a;
      result = a;
      a = a->bottom;
    }
    else{
      result->bottom = b;
      result = b;
      b = b->bottom;
    }
    result->next = NULL;
  }
  if(a) result->bottom = a;
  if(b) result->bottom = b;
  return dummyNode->bottom;
}

Node* flatten(Node* root) {
    if (root == NULL || root->next == NULL)
        return root;

    Node* meargedHead = flatten(root->next);

    return merge(root, meargedHead);
}

int main() {

    Node* head = new Node(5);

    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    Node* flat = flatten(head);

    printBottom(flat);
}