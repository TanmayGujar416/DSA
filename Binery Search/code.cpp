# include <iostream>
# include <vector>

using namespace std;

int binarySearch(vector<int> &arr,int target){
    int low = 0;
    int high = arr.size() - 1;
    int mid;
    while(low<=high){
        mid = low + (high-low)/2;
        if(target == arr[mid]){
            return mid;
        }
        if(target<arr[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    int target = 5;
    int result = binarySearch(arr,target);
    if(result != -1){
        cout<<"Element found at index: "<<result<<endl;
    }
    else{
        cout<<"Element not found in the array."<<endl;
    }
    return 0;
}