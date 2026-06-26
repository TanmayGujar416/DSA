#include<bits/stdtr1c++.h>
using namespace std;

struct Node {
  public:
  int data;
  Node* next;
  Node* back;

  public:
  Node(int data1, Node* next1, Node* back1){
    data = data1;
    next = next1;
    back = back1;
  }
  public:
  Node(int data1){
    data = data1;
    next = nullptr;
    back = nullptr;
  }

};

Node* convertArrToDLL(vector<int> arr){
  Node* head = new Node(arr[0]);
  Node* prev = head;

  for(int i = 1; i<arr.size(); i++){
    Node* temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
  }
  return head;
}
void print(Node* head){
  while(head != NULL){
    cout << head->data << " ";
    head =  head->next;
  }
}


Node* deletHead(Node* head){
  if(head == NULL) return NULL;

  if(head->next == NULL){
      delete head;
      return NULL;
  }
  Node* prev = head;
  head = head->next;
  head->back = nullptr;
  prev->next = nullptr;
  delete prev;
  return head;
}
Node* deleteTail(Node* head){
  if(head == NULL) return NULL;

  if(head->next == NULL){
      delete head;
      return NULL;
  }
  Node* prev = head;
  while(prev->next->next !=NULL){
    prev = prev->next;
  }
  Node* temp = prev->next;
  prev->next = nullptr;
  temp->back = nullptr;

  delete temp;
  return head;
}
Node* deleteKthElement(Node* head, int k){
  if(head == NULL) return NULL;
  Node* temp = head;

  int cnt = 0;

  while(temp != NULL){
    cnt++;
    if(cnt == k) break;
    temp = temp->next;
  }
  if(temp == NULL) return head;

  Node* prev = temp->back;
  Node* front = temp->next;

  if(prev == NULL && front == NULL){
    delete temp;
    return NULL;
  }
  else if(prev == NULL){
    return deletHead(head);
  }
  else if(front == NULL){
    return deleteTail(head);
  }
  else{
    prev->next = front;
    front->back = prev;
    delete temp;
    return head;
  }
}
void deleteNode(Node* temp){
  Node* prev = temp->back;
  Node* front = temp->next;

  if(front == NULL){
    prev->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return;
  }
  prev->next = front;
  front->back = prev;
  temp->next = nullptr;
  temp->back = nullptr;
  delete temp;
}

int main(){
  vector<int> arr = {2,3,4,5};
  Node* head = convertArrToDLL(arr);
  deleteNode(head->next->next);
  print(head);
}