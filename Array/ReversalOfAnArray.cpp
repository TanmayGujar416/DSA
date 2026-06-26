#include <iostream>
#include <vector>

using namespace std;

vector<int> reverseTheArray(vector<int> &arr){
    int start = 0;
    int end = arr.size() - 1;
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }   
    return arr;

}


int main() {
    vector<int> arr = {3,10,10,9};
    vector<int> reversedArray = reverseTheArray(arr);

    cout << "TReversed Array: ";
    for (int num : reversedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}