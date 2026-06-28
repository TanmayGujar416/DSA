#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 1: Compare with arr[high] (Recommended)
    int findKRotation1(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }

    // Method 2: Check previous and next element
    int findKRotation2(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        int n = arr.size();

        while (low <= high) {

            // Array is already sorted
            if (arr[low] <= arr[high])
                return low;

            int mid = low + (high - low) / 2;

            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;

            // Mid is minimum
            if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
                return mid;

            // Left half sorted
            if (arr[low] <= arr[mid])
                low = mid + 1;

            // Right half sorted
            else
                high = mid - 1;
        }

        return -1;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution obj;

    cout << "Method 1 Rotation Count: "
         << obj.findKRotation1(arr) << endl;

    cout << "Method 2 Rotation Count: "
         << obj.findKRotation2(arr) << endl;

    return 0;
}