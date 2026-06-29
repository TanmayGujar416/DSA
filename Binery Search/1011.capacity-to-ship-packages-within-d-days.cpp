#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isPossible(weights, mid, days)){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }

    bool isPossible(vector<int>& weights, int capacity, int days){
        int sum = 0;
        int noDays = 1;
        for(int i = 0; i < weights.size(); i++){
            if(sum + weights[i] <= capacity){
                sum += weights[i];
            }
            else{
                noDays++;
                sum = weights[i];
            }
        }
        if(noDays <= days) return true;
        else return false;
    }
};
// @lc code=end

