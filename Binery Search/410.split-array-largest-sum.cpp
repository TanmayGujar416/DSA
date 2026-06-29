#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        if(k > nums.size()) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid = low + (high - low)/2;

            if(needMoreThanK(nums, mid, k)){
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return low;
    }
    bool needMoreThanK(vector<int>& nums, int m, int k){
        int cnt = 1;
        int currentSum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(currentSum + nums[i] <= m){
                currentSum += nums[i];
            }
            else{
                cnt++;
                currentSum = nums[i];
            }
            if(cnt > k) return true;
        }
        return false;

    }
};
// @lc code=end

