#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mini = INT_MAX;

        while (low <= high)
        {
            // Entire range is sorted
            if(nums[low] <= nums[high]){
                mini = min(mini, nums[low]);
                break;
            }
            int mid = low + ( high - low )/2;
            // Left half sorted
            if(nums[mid]>= nums[low]){
                mini = min(mini, nums[low]);
                low = mid + 1;
            }
            // Right half sorted
            else{
                mini = min(mini, nums[mid]);
                high = mid - 1;
            }
        }
        return mini;

    }
};
// @lc code=end

