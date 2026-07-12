#include <bits/stdc++.h>
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

class Stack{
  private :
      Node* top;
      int currSize;
  public :
     // Constructor
    Stack() {
        top = nullptr;
        currSize = 0;
    }
    ~Stack() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

    void push(int x){
      Node* newNode = new Node(x, top);
      top = newNode;
      currSize++;
    }

    int pop(){
      if (isEmpty()) {
        cout << "Stack Underflow\n";
        return -1;
      }
      Node* temp = top;
      top = top->next;
      int topData = temp->data;
      delete temp;
      currSize--;
      return topData;
    }

    int peek(){
      if (isEmpty()) {
        cout << "Stack is empty\n";
        return -1;
      }
      return top->data;
    }

    int size() {
        return currSize;
    }

    // Check whether stack is empty
    bool isEmpty() {
        return currSize == 0;
    }

    // Print stack from top to bottom
    void display(){

      Node* temp = top;
      while(temp){
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << "\n";
    }
};

int main() {

    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    cout << "Top Element : " << st.peek() << endl;

    cout << st.pop();

    st.display();

    cout << "Size : " << st.size() << endl;

    return 0;
}
