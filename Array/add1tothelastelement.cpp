// Add 1 to the last element of an array
//example: [1,2,3] -> [1,2,4]
//example: [1,2,9] -> [1,3,0]
//example: [9,9,9] -> [1,0,0,0]
#include <iostream>
#include <vector>

using namespace std;

vector<int> addOneToLastElement(vector<int> &arr){
    for(int i=arr.size()-1 ;i>=0;i--){
        if(arr[i]!=9){
            arr[i] = arr[i] + 1;
            return arr;
        }
        arr[i]=0;
        
    }
    vector<int> result(arr.size()+1);
    result[0]=1;
    return result;
}

int main(){
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {1,2,3,9};
    vector<int> arr3 = {9,9,9,9,9};

    vector<int> resultArray1 = addOneToLastElement(arr3);

    cout << "Array1: ";
    for (int num : resultArray1) {
        cout << num << " ";
    }
    cout << endl;
}