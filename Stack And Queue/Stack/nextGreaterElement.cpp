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
vector<int> findNextGreaterElement(vector<int>& arr){
  stack<int> st;
  vector<int> result(arr.size());
  for(int i = arr.size() - 1; i>=0; i--){

    while(!st.empty() && st.top() <= arr[i]){
      st.pop();
    }

    if(st.empty()){
      result[i] = -1;
    } else{
    result[i] = st.top();
    }
    st.push(arr[i]);
  }
  return result;
}

int main() {
    vector<int> arr = {2, 1, 2, 4, 3};

    vector<int> result = findNextGreaterElement(arr);

    cout << "Array: ";
    for (int x : arr)
        cout << x << " ";

    cout << "\nNext Greater Element: ";
    for (int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}