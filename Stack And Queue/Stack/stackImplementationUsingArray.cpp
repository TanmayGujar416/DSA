#include <bits/stdc++.h>
using namespace std;

class Stack{
  private :
      int arr[100];      // Array to store stack elements
      int top;           // Index of the top element
  public :
     // Constructor
    Stack() {
        top = -1;      // Stack is initially empty
    }

    void push(int x){
      if(top == 99){
        cout << "Stack overflow\n";
        return;
      }
      top++;
      arr[top] = x;
    }

    void pop(){
      if(top == -1){
        cout << "Stack Underflow\n";
      }
      top--;
    }

    int peek(){
      if(top == -1){
        cout<< "Stack is Empty";
        return -1;
      }
      return arr[top];
    }

    int size() {
        return top + 1;
    }

    // Check whether stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Print stack from top to bottom
    void display() {

        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Stack : ";

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {

    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    cout << "Top Element : " << st.peek() << endl;

    st.pop();

    st.display();

    cout << "Size : " << st.size() << endl;

    return 0;
}
