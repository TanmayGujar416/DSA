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


Node* oddEvenBrute(Node* head){
  if(head == NULL || head->next == NULL){
    return head;
  }
  vector<int> arr = {};
  Node* temp = head;

  while(temp !=   NULL && temp->next != NULL){
    arr.push_back(temp->data);
    temp = temp->next->next;
  }
  if(temp != NULL){
    arr.push_back(temp->data);
  }
  Node* temp2 = head->next;

  while(temp2 !=   NULL && temp2->next != NULL){
    arr.push_back(temp2->data);
    temp2 = temp2->next->next;
  }
  if(temp2 != NULL){
    arr.push_back(temp2->data);
  }
  int i = 0;
  Node* temp3 = head;
  while(temp3 != NULL){
    temp3->data = arr[i];
    i++;
    temp3 = temp3->next;
  }
  return head;

}




Node* oddEvenOptimal(Node* head){

  Node* odd = head;
  Node* even = head->next;
  Node* evenHead = head->next;
  while(even != NULL && even->next != NULL){
    odd->next = odd->next->next;
    even->next = even->next->next;
    odd = odd->next;
    even = even->next;
  }
  odd->next = evenHead;
  return head;

}

int main(){
  vector<int> arr = {3,5,2,7,9,4};
  Node* head = convertArr2LL(arr);
  head = oddEvenOptimal(head);
  print(head);
}