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
Node* add2Numbers(Node* head1, Node* head2){
  Node* temp1 = head1;
  Node* temp2 = head2;
  Node* dummyNode = new Node(-1);
  Node* curr = dummyNode;

  int carry = 0;

  while(temp1 != NULL || (temp2 != NULL)){
    int sum = carry;
    if(temp1) sum = sum + temp1->data;
    if(temp2) sum = sum + temp2->data;

    Node* newNode = new Node(sum%10);
    carry = sum/10;
    curr->next = newNode;
    curr = curr->next;
    if(temp1) temp1 = temp1->next;
    if(temp2) temp2 = temp2->next;
  }

  if(carry){
    Node* newNode = new Node(carry);
    curr->next = newNode;
  }
  return dummyNode->next;
}

int main(){
  vector<int> arr1 = {3,5};
  Node* head1 = convertArr2LL(arr1);
  vector<int> arr2 = {4, 5, 9, 9};
  Node* head2 = convertArr2LL(arr2);
  Node* newHead = add2Numbers(head1, head2);
  print(newHead);

}