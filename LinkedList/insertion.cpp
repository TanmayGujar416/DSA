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

Node* insertHead(Node* head, int val){
   return new Node(val, head);
}
Node* insertLast(Node* head, int val){
  if(head == NULL) return new Node(val);
  Node* temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  Node* newNode = new Node(val);
  temp->next = newNode;
  return head;
}

Node* insertAtKthPosition(Node* head, int val, int k){
  if(head == NULL){
    if(k==1){
      return new Node(val);
    }
  }
  if(k == 1){
    Node* newNode = new Node(val,head);
    return newNode;
  }
  int cnt = 0;
  Node* temp = head;

  while(temp != NULL){
    cnt++;
    if(cnt == k-1){
      Node* newNode = new Node(val);
      newNode->next = temp->next;
      temp->next = newNode;
      return head;;
    }
    temp = temp->next;
  }
  return head;
}



Node* insertBeforeValue(Node* head, int el, int val){
  if(head == NULL){
    return NULL;
  }
  if(head->data == val){
    Node* newNode = new Node(el,head);
    return newNode;
  }
  Node* temp = head;

  while(temp->next != NULL){
    if(temp->next->data == val){
      Node* newNode = new Node(el);
      newNode->next = temp->next;
      temp->next = newNode;
      return head;;
    }
    temp = temp->next;
  }
  return head;
}


int main(){
  vector<int> arr = {8,3,4,5,9};
  Node* head = convertArr2LL(arr);
  Node* newHead = insertBeforeValue(head,89,5);
  print(newHead);

}