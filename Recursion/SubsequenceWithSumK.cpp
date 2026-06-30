#include <bits/stdc++.h>
using namespace std;

bool printS(int i, vector<int>& arr, vector<int>& ds, int sum, int k){
  if(i == arr.size()){
    if(sum == k){
      for(int x: ds)
        cout << x << " ";
      cout << endl;
      return true;
      }
      return false;
    }
      // Take
    ds.push_back(arr[i]);
    if (printS(i + 1, arr, ds, sum + arr[i], k) == true){
      return true;
    }

    // Don't Take
    ds.pop_back();
    if (printS(i + 1, arr, ds, sum, k) == true){
      return true;
    }
    return false;
}

int main() {
    vector<int> arr = {1,2,1};
    vector<int> ds;
    int k = 4;

    printS(0, arr, ds, 0, k);
}