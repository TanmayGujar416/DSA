#include <iostream>
using namespace std;

class Queue {
private:
    static const int MAX = 100;
    int arr[MAX];
    int start;
    int end;
    int currSize;

public:
    // Constructor
    Queue() {
        start = -1;
        end = -1;
        currSize = 0;
    }

    // Insert an element
    void push(int x) {
        if (currSize == MAX) {
            cout << "Queue Overflow\n";
            return;
        }

        if (currSize == 0) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % MAX;
        }

        arr[end] = x;
        currSize++;
    }

    // Remove the front element
    void pop() {
        if (currSize == 0) {
            cout << "Queue Underflow\n";
            return;
        }

        if (currSize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % MAX;
        }

        currSize--;
    }

    // Return the front element
    int peek() {
        if (currSize == 0) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return arr[start];
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
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue: ";

        int i = start;
        while (true) {
            cout << arr[i] << " ";

            if (i == end)
                break;

            i = (i + 1) % MAX;
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