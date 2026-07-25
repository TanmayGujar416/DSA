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
vector<int> findNextGreaterElement2(vector<int>& arr){
  stack<int> st;
  vector<int> result(arr.size());
  for(int i = 2*arr.size() - 1; i>=0; i--){
    int index = i%(arr.size());
    while(!st.empty() && st.top() <= arr[index]){
      st.pop();
    }
    if (i < arr.size()) {
      if(st.empty()){
        result[index] = -1;
      } else{
      result[index] = st.top();
      }
    }
    st.push(arr[index]);
  }
  return result;
}

int main() {
    vector<int> arr = {2, 1, 2, 4, 3};

    vector<int> result = findNextGreaterElement2(arr);

    cout << "Array: ";
    for (int x : arr)
        cout << x << " ";

    cout << "\nNext Greater Element: ";
    for (int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}