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
Node* middleOfLL(Node* head){
  Node* slow = head;
  Node* fast = head->next;

  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

Node* mergeTwoLists(Node* list1, Node* list2) {

    Node dummy(-1);
    Node* tail = &dummy;

    while(list1 && list2){

        if(list1->data <= list2->data){
            tail->next = list1;
            list1 = list1->next;
        }
        else{
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    if(list1) tail->next = list1;
    else tail->next = list2;

    return dummy.next;
}


Node* mergeSortALL(Node* head){
  if(head == NULL || head->next == NULL) return head;

  Node* middle = middleOfLL(head);

  Node* leftHead = head;
  Node* rightHead = middle->next;

  middle->next = NULL;

  leftHead = mergeSortALL(leftHead);
  rightHead= mergeSortALL(rightHead);

  return mergeTwoLists(leftHead, rightHead);
}


int main(){
  vector<int> arr = {0,2,0,2,1,1,0,5};
  Node* head = convertArr2LL(arr);
  head = mergeSortALL(head);
  print(head);
}