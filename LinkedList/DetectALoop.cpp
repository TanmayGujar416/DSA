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

#include <unordered_map>

bool detectCycle(Node* head) {
    unordered_map<Node*, bool> visited;

    Node* temp = head;

    while (temp != nullptr) {
        if (visited.find(temp) != visited.end()) {
            return true;    // Cycle found
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}


bool detectCycleOptimal(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          // 1 step
        fast = fast->next->next;    // 2 steps

        if (slow == fast) {
            return true;            // Cycle found
        }
    }

    return false;                   // No cycle
}
int main() {
    vector<int> arr = {1,2,3,4,5};

    Node* head = convertArr2LL(arr);

    // Create cycle: last node -> second node
    Node* last = head;
    while(last->next)
        last = last->next;

    last->next = head->next;   // 5 -> 2

    if(detectCycleOptimal(head))
        cout << "Cycle Detected";
    else
        cout << "No Cycle";

    return 0;
}