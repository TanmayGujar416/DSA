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



Node* deleteHead(Node* head){
  if(head == nullptr) return head;
  Node* temp = head;
  head = head->next;
  delete(temp);
  return head;
}



Node* deleteLast(Node* head){
  if(head ==  NULL || head->next == nullptr) return NULL;
  Node* temp = head;
  while(temp ->next->next!= NULL){
    temp = temp->next;
  }
  free(temp->next);
  temp->next = nullptr;
  return head;
}

Node* deleteKthElement(Node* head,int k){
  if(head == NULL) return head;
  if(k == 1){
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
  }

  int cnt = 0;

  Node* temp = head;
  Node* prev = NULL;

  while (temp!=NULL)
  {
    cnt++;
    if(cnt == k){
      prev->next = prev->next->next;
      free(temp);
      return head;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;

}

Node* removeElementByData(Node* head,int value){
  if(head == NULL) return head;
  if(head->data==value){
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
  }

  Node* temp = head;
  Node* prev = NULL;

  while (temp!=NULL)
  {
    if(temp->data == value){
      prev->next = prev->next->next;
      free(temp);
      return head;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;

}


int main(){
  vector<int> arr = {8,3,4,5,9};
  Node* head = convertArr2LL(arr);
  Node* newHead = removeElementByData(head,3);
  print(newHead);
}