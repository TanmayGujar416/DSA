#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }

    return head;
}

int lengthOfLoop(Node* head) {
    unordered_map<Node*, int> mp;

    Node* temp = head;
    int pos = 0;

    while (temp != nullptr) {
        if (mp.find(temp) != mp.end()) {
            return pos - mp[temp];
        }

        mp[temp] = pos;
        pos++;
        temp = temp->next;
    }

    return 0; // No loop
}

int lengthOfLoopOptimal(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            int cnt = 1;
            fast = fast->next;

            while (fast != slow) {
                cnt++;
                fast = fast->next;
            }

            return cnt;
        }
    }

    return 0; // No loop
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    Node* head = convertArr2LL(arr);

    // Create loop: 5 -> 3
    Node* third = head->next->next;
    Node* last = head;

    while (last->next != nullptr)
        last = last->next;

    last->next = third;

    cout << "Length of Loop = " << lengthOfLoopOptimal(head);

    return 0;
}