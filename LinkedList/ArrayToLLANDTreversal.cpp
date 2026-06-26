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
//length
int lengthOfLL(Node* head){
  int cnt = 0;
  Node* temp = head;
  while(temp){
    cnt++;
    temp = temp->next;
  }
  return cnt;
}


int main(){
  vector<int> arr = {8,3,4,5};
  Node* head = convertArr2LL(arr);
  cout << head->data;
  //traversal
  Node* temp = head;
  while(temp){
    cout << temp->data << " ";
    temp = temp->next;
  }

  cout << lengthOfLL(head);
}