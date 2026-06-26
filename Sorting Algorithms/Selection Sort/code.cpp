#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr){
    int n = arr.size();
    for (int i = 0; i<n-1;i++){
        int pm =i;
        for (int j = i+1; j<n; j++){
            if(arr[j]<arr[pm]){
                pm = j;
            }
        }
        if(pm != i){
            swap(arr[i], arr[pm]);
        }
    }
}

void printArray(vector<int> &arr){
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr = {64, 25, 12, 22, 11};
    selectionSort(arr);
    cout<<"Sorted array: ";
    printArray(arr);
    return 0;
}