#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1283 lang=cpp
 *
 * [1283] Find the Smallest Divisor Given a Threshold
 */

// @lc code=start
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin() , nums.end());

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isPossible(nums, mid, threshold)){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }

    bool isPossible(vector<int>& nums,int mid,int threshold){
        long long sum = 0;
        for(int i = 0; i < nums.size() ;i++){
            sum+= ceil((double) nums[i]/mid);
        }
        if(sum <= threshold) return true;
        else return false;
    }
};
// @lc code=end

