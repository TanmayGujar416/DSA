#include <iostream>
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

class Queue {
private:
    Node* start;
    Node* end;
    int currSize;

public:
    // Constructor
    Queue() {
        start = nullptr;
        end = nullptr;
        currSize = 0;
    }
    ~Queue() {
    while (start != nullptr) {
        Node* temp = start;
        start = start->next;
        delete temp;
    }
    end = nullptr;
}

    // Insert an element
    void push(int x) {
      Node* newNode = new Node(x);
      if(start == nullptr){
        start = newNode;
        end = newNode;
      }
      else{
        end->next = newNode;
        end = newNode;
      }
      currSize++;
    }

    // Remove the front element
    void pop() {
        if (currSize == 0) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = start;
        start = start->next;
        delete temp;
        currSize--;
        if (currSize == 0) {
          end = nullptr;
        }
    }

    // Return the front element
    int peek() {
        if (currSize == 0) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return start->data;
    }

    // Return the current size
    int size() {
        return currSize;
    }

    // Check if queue is empty
    bool isEmpty() {
        return currSize == 0;
    }

    // Display queue elements
    void display(){

      Node* temp = start;
      while(temp){
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << endl;
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    q.display();

    cout << "Front Element: " << q.peek() << endl;
    cout << "Size: " << q.size() << endl;

    q.pop();
    q.display();

    q.push(40);
    q.push(50);

    q.display();

    cout << "Front Element: " << q.peek() << endl;
    cout << "Size: " << q.size() << endl;

    return 0;
}