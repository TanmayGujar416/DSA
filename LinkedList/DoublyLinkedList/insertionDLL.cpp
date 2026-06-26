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

Node* insertBeforHead(Node* head, int val){
  Node* newHead = new Node(val, head, nullptr);
  head->back = newHead;
  return newHead;
}

Node* insertBeforTail(Node* head, int val){
  Node* tail = head;

  while(tail->next != NULL){
    tail = tail->next;
  }
  Node* prev = tail->back;
  Node* newNode = new Node(val, tail, prev);
  prev->next = newNode;
  tail->back = newNode;
  return head;
}

Node* insertBeforeKthElement(Node* head, int val,int k){
  if(k == 1){
    return insertBeforHead(head, val);
  }

  Node* temp = head;
  int cnt = 0;
  while(temp){
    cnt++;
    if(cnt == k)  break;
    temp = temp->next;
  }
  Node* prev = temp->back;
  Node* newNode = new Node(val, temp, prev);
  prev->next = newNode;
  temp->back = newNode;
  return head;
}

void insertBeforeNode(Node* temp, int val){//temp!=head
  Node* prev = temp->back;
  Node* newNode = new Node(val, temp, prev);
  prev->next = newNode;
  temp->back = newNode;
}

int main(){
  vector<int> arr = {2,3,4,5};
  Node* head = convertArrToDLL(arr);
  insertBeforeNode(head->next->next, 89);
  print(head);
}