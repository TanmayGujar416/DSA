#include <bits/stdc++.h>
using namespace std;
// TC = O(2*n)
// SC = O(n)
int fibonacci(int n){
  if(n <= 1) return n;
  return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
  int n;
  cout << "Enter N :" ;
  cin >> n;
  cout << fibonacci(n);

  return 0;
}