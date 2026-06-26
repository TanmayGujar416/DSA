#include <bits/stdc++.h>
using namespace std;
 void insertionSort(vector<int> &arr){
    int n = arr.size();
    for(int i = 1;i<n;i++){
        int key = arr[i];
        int j =i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
 }

void printArray(vector<int> &arr){
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr = {12, 11, 13, 5, 6};
    insertionSort(arr);        
    cout<<"Sorted array: ";
    printArray(arr);
    return 0;
}