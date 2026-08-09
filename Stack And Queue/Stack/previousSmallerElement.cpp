#include <bits/stdc++.h>
using namespace std;


/*
for i = n-1 to 0

    while stack not empty AND stack.top() <= arr[i]
        pop()

    if stack empty
        answer[i] = -1
    else
        answer[i] = stack.top()

    push(arr[i])


    Time Complexity: O(n)
    Space Complexity: O(n)
*/
vector<int> PSE(vector<int>& arr){
  stack<int> st;
  vector<int> result(arr.size());
  for(int i = 0; i<arr.size(); i++){

    while(!st.empty() && st.top() >= arr[i]){
      st.pop();
    }

    result[i] = st.empty() ? -1 : st.top();
    st.push(arr[i]);
  }
  return result;
}

int main() {
    vector<int> arr = {2, 1, 2, 4, 3};

    vector<int> result = PSE(arr);

    cout << "Array: ";
    for (int x : arr)
        cout << x << " ";

    cout << "\nPrevious Smaller Element: ";
    for (int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}