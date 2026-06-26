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

//Brute
Node* sort012(Node* head){
  if(head == NULL || head->next == NULL) return head;
  Node* temp = head;
  int count0 = 0;
  int count1 = 0;
  int count2 = 0;

  while (temp != NULL)
  {
    if(temp->data == 0) count0++;
    else if(temp->data == 1) count1++;
    else if(temp->data == 2) count2++;
    temp = temp->next;
  }
  temp = head;
  while(temp != NULL){
    if(count0){
      temp->data = 0;
      count0--;
    }
    else if(count1){
      temp->data = 1;
      count1--;
    }
    else if(count2){
      temp->data = 2;
      count2--;
    }
    temp = temp->next;
  }
  return head;
}

//optimal
Node* sort012Optimal(Node* head){
  if(head == NULL || head->next == NULL) return head;
  Node* temp = head;
  Node* dummyNode0 = new Node(-1);
  Node* zeroHead = dummyNode0;
  Node* dummyNode1 = new Node(-1);
  Node* oneHead = dummyNode1;
  Node* dummyNode2 = new Node(-1);
  Node* twoHead = dummyNode2;


  while(temp != NULL){
    if(temp->data == 0){
      dummyNode0->next = temp;
      dummyNode0 = dummyNode0->next;
    }
    else if(temp->data == 1) {
      dummyNode1->next = temp;
      dummyNode1 = dummyNode1->next;
    }
    else if(temp->data == 2) {
      dummyNode2->next = temp;
      dummyNode2 = dummyNode2->next;
    }
    temp = temp->next;
  }

  dummyNode0->next = (oneHead->next) ? oneHead->next : twoHead->next;
  dummyNode1->next = twoHead->next;
  dummyNode2->next = NULL;
  delete dummyNode0;
  delete dummyNode1;
  delete dummyNode2;
  return zeroHead->next;
}


int main(){
  vector<int> arr = {0,2,0,2,1,1,1,0,2};
  Node* head = convertArr2LL(arr);
  head = sort012Optimal(head);
  print(head);
}