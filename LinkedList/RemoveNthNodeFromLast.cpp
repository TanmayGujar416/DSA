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
//brute-force
Node* removeNthNodeFromLast(Node* head, int n){
  if(head == NULL) return head;
  Node* temp = head;
  int len = 0;
  while(temp != NULL){
    len++;
    temp = temp->next;
  }
  if(n == len){
    Node* dNode = head;
    head = head->next;
    delete dNode;
    return head;
  }
  int result = len - n-1;
  temp = head;
  while(result != 0){
    result--;
    temp = temp->next;
  }
  Node* dNode = temp->next;
  temp->next = temp->next->next;
  delete dNode;
  return head;
}

//Optimal solution
Node* removeNthNodeFromLastOptimal(Node* head, int n){
  if(head == NULL) return head;
  Node* fast = head;
  Node* slow = head;
  for(int i = 0; i < n; i++){
    fast = fast->next;
  }
  if(fast == NULL){
    Node* dNode = head;
    head = head->next;
    delete dNode;
    return head;
  }

  while(fast->next != NULL){
    fast = fast->next;
    slow = slow->next;
  }
  Node* dNode = slow->next;
  slow->next = slow->next->next;
  delete dNode;
  return head;
}


int main(){
  vector<int> arr = {1,2,3,4,5,6};
  Node* head = convertArr2LL(arr);
  head = removeNthNodeFromLastOptimal(head, 2);
  print(head);
}
