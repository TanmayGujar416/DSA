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


// TC: O(N log N + M log N)
// SC: O(N)

// For the optimal hashing version using unordered_set<Node*>:

// TC: O(N + M) average
// SC: O(N)
Node* intersectionPresent(Node* head1, Node*  head2){

  Node* temp = head1;
  map<Node*, int> mp;
  while(temp != NULL){
    mp[temp] = 1;
    temp = temp->next;
  }

  temp = head2;
  while(temp != NULL){
    if(mp.find(temp) != mp.end()){
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}


// Time Complexity: O(N + M)
// Space Complexity: O(1)
Node* intersectionPresentOptimal(Node* head1, Node*  head2){
  if(head1 == NULL || head2 == NULL) return NULL;
  Node* temp1 = head1;
  Node* temp2 = head2;

  while(temp1 != temp2){
    temp1 = temp1->next;
    temp2 = temp2->next;

    if(temp1 == temp2) return temp1;

    if(temp1 == NULL) temp1 = head2;
    if(temp2 == NULL) temp2 = head1;
  }
  return temp1;
}

int main() {
    vector<int> arr1 = {4, 1, 8, 4, 5};
    vector<int> arr2 = {5, 6, 1};

    Node* head1 = convertArr2LL(arr1);
    Node* head2 = convertArr2LL(arr2);

    // Find node with value 8 in list1
    Node* temp = head1;
    while(temp->data != 8) {
        temp = temp->next;
    }

    // Attach end of list2 to node 8
    Node* tail = head2;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = temp;

    Node* ans = intersectionPresentOptimal(head1, head2);

    if(ans)
        cout << "Intersection at: " << ans->data << endl;
    else
        cout << "No intersection\n";

    return 0;
}
//4 -> 1 -> 8 -> 4 -> 5
//           ^
//           |
// 5 -> 6 -> 1