#include<bits/stdtr1c++.h>
using namespace std;

struct Node {
  public:
  int data;
  Node* next;

  public:
  Node(int data1, Node* next1){
    data = data1;
    next = next1;
  }
  public:
  Node(int data1){
    data = data1;
    next = nullptr;
  }
};


void print(Node* head){

  Node* temp = head;
  while(temp){
    cout << temp->data << " ";
    temp = temp->next;
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
Node* reverseLL(Node* head){
  if(head == NULL || head->next == NULL) return head;
  Node* temp = head;
  Node* prev = NULL;
  while(temp != NULL){
    Node* front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;
  }
  return prev;
}

// Time complexity = O(3N)
//SC = O(1)
Node* Add1ToLL(Node* head){
  Node* newHead = reverseLL(head);
  Node* temp = newHead;
  int carry = 1;
  while(temp !=NULL){
    int sum = temp->data + carry;
    temp->data = sum%10;
    carry = sum/10;
    if(carry == 0) break;
    temp = temp->next;
  }
  newHead = reverseLL(newHead);
  if(carry == 1){
    Node* newNode = new Node(1, newHead);
    return newNode;
  }
  return newHead;
}


int helper(Node* temp){
  if(temp == NULL) return 1;
  int carry = helper(temp->next);

  temp->data += carry;
  if(temp->data < 10){
    return 0;
  }
  temp->data = 0;
  return 1;
}
// Time: O(N)
// Space: O(N)  // recursion stack
Node* add1ToLLRecursive(Node* head){
  int carry = helper(head);
  if(carry == 1){
     Node* newNode = new Node(1);
     newNode->next = head;
     return newNode;
  }
  return head;
}


int main(){
  vector<int> arr = {9,9,9};
  Node* head = convertArr2LL(arr);
  head = add1ToLLRecursive(head);
  print(head);
}