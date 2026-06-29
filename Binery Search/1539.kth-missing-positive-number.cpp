#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 */

// @lc code=start
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;

        while(low <= high){
            int mid = low + (high - low)/2;
            int missing = arr[mid] - (mid + 1);

            if(missing >= k) high = mid - 1;
            else low = mid + 1;
        }
        return (k + high + 1);
    }
};
// @lc code=end

