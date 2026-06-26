// Given an array of integers and a target sum, determine if there are two numbers in the array that add up to the target sum.
// Example:
// Input: arr = [1, 2, 3, 4, 5], target = 7
// Output: true (because 2 + 5 = 7)
// Input: arr = [1, 2, 3, 4, 5], target = 10
// Output: false (because no two numbers add up to 10)  
// Approach: We can use a hash set to store the numbers we have seen so far. For each number in the array, we calculate its complement (target - current number) and check if it exists in the hash set. If it does, we have found a pair that sums to the target. If not, we add the current number to the hash set and continue checking.
#include <bits/stdc++.h>
using namespace std;
bool hasPairWithSum(vector<int>& arr, int target) {
    unordered_set<int> seen;
    for(int i = 0;i<arr.size();i++){
        int complement = target - arr[i];

        if(seen.find(complement) != seen.end()){
            return true;
        }
        seen.insert(arr[i]);
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