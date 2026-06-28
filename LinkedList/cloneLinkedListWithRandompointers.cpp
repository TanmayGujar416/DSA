#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* random;

    Node(int x){
        data = x;
        next = NULL;
        random = NULL;
    }
};

Node* convertArr2LL(vector<int> &arr, vector<Node*> &nodes){

    if(arr.empty()) return NULL;

    Node* head = new Node(arr[0]);
    nodes.push_back(head);

    Node* mover = head;

    for(int i=1;i<arr.size();i++){
        mover->next = new Node(arr[i]);
        mover = mover->next;
        nodes.push_back(mover);
    }

    return head;
}

void setRandomPointers(vector<Node*> &nodes, vector<int> &randomIndex){

    for(int i=0;i<nodes.size();i++){

        if(randomIndex[i] == -1)
            nodes[i]->random = NULL;
        else
            nodes[i]->random = nodes[randomIndex[i]];
    }
}

void print(Node* head){

    while(head){

        cout << "Node = " << head->data << "  Random = ";

        if(head->random)
            cout << head->random->data;
        else
            cout << "NULL";

        cout << endl;

        head = head->next;
    }
}

Node* cloneLL(Node* head){
  Node* temp = head;
  map<Node*,Node*> mp;

  while(temp != NULL){
    Node* newNode = new Node(temp->data);
    mp[temp] = newNode;
    temp = temp->next;
  }
  temp = head;
  while (temp != NULL)
  {
    Node* copyNode = mp[temp];
    copyNode->next = mp[temp->next];
    copyNode->random = mp[temp->random];
    temp = temp->next;
  }
  return mp[head];
}


int main(){

    vector<int> arr = {7,13,11,10,1};

    // random pointer indices
    // -1 means NULL
    vector<int> randomIndex = {-1,0,4,2,0};

    vector<Node*> nodes;

    Node* head = convertArr2LL(arr,nodes);

    setRandomPointers(nodes,randomIndex);

    Node* newHead = cloneLL(head);
    print(newHead);

    return 0;
}