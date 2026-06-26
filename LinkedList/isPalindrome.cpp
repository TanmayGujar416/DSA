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

Node* reverseLL(Node* head){
  if(head == NULL || head->next == NULL) return head;
  Node* temp = head;
  Node* prev = NULL;
  while(temp != NULL){
    Node* front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;
  }
  return prev;
}

bool isPalindrome(Node* head){
  if(head == NULL || head->next == NULL) return true;
  Node* slow = head;
  Node* fast = head;
  while(fast->next != NULL && fast->next->next !=NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  Node* newHead = reverseLL(slow->next);
  Node* first = head;
  Node* second = newHead;
  bool isplaindrome = true;
  while(second != NULL){
    if(first->data != second->data){
      isplaindrome = false;
      break;
    }

    first = first->next;
    second = second->next;
  }
  newHead = reverseLL(newHead);
  return isplaindrome;
}


int main(){
  vector<int> arr = {1,2,3,3,2,1};
  Node* head = convertArr2LL(arr);
  cout << isPalindrome(head);
  cout << boolalpha << isPalindrome(head);
  // print(head);
}