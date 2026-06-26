//Determine the first three largest elements in an array. The array may contain duplicate elements.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findThreeLargest(vector<int>& arr) {
    vector<int> result(3);
    int max1,max2,max3;
    max1=max2=max3 =INT_MIN;
    for(int i = 0 ; i<arr.size();i++){
        if(arr[i]>=max1){
            max3 = max2;
            max2 = max1;
            max1= arr[i];
        }
        else if(arr[i]>=max2){
            max3= max2;
            max2 = arr[i];
        }
        else if(arr[i]>max3){
            max3 = arr[i];
        }
    }
    result = {max1,max2,max3};
    return result;
    }

int main() {
    vector<int> arr = {3,10,10,9};
    vector<int> result = findThreeLargest(arr);

    cout << "The three largest elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}