// Given an array of integers and a target sum, determine if there are two numbers in the array that add up to the target sum.
// Example:
// Input: arr = [1, 2, 3, 4, 5], target = 7
// Output: true (because 2 + 5 = 7)
// Input: arr = [1, 2, 3, 4, 5], target = 10
// Output: false (because no two numbers add up to 10)  
// Approach: We can sort the array and use two pointers, one starting at the beginning of the array and the other at the end. We calculate the sum of the two numbers at these pointers. If the sum is equal to the target, we have found a pair. If the sum is less than the target, we move the left pointer to the right to increase the sum. If the sum is greater than the target, we move the right pointer to the left to decrease the sum. We continue this process until we find a pair or until the pointers cross each other.
#include <bits/stdc++.h>
using namespace std;
bool hasPairWithSum(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0 ;
    int right = arr.size() - 1;
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum== target){
            return true;
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }

    }
    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 7;

    if (hasPairWithSum(arr, target)) {
        cout << "Pair found that sums to " << target << endl;
    } else {
        cout << "No pair found that sums to " << target << endl;
    }

    return 0;
}