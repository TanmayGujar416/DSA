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

Node* deleteMiddleOfLL(Node* head){
  Node* temp = head;
  int count = 0;
  while(temp !=NULL){
    count++;
    temp = temp->next;
  }
  temp = head;
  for(int i = 0;i< count/2- 1; i++){
    temp = temp->next;
  }
  Node* middle = temp->next;
  temp->next = temp->next->next;
  middle->next = NULL;
  delete middle;
  return head;
}


Node* deleteMiddleOfLLOptimal(Node* head){
  Node* slow = head;
  Node* fast = head;
  fast = fast->next->next;
  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  Node* middle = slow->next;
  slow->next = slow->next->next;
  middle->next = NULL;
  delete middle;
  return head;
}

int main(){
  vector<int> arr = {8,3,4,5,9,7};
  Node* head = convertArr2LL(arr);
  head  = deleteMiddleOfLLOptimal(head);
  print(head);
}