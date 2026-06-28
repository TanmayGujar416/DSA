#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1482 lang=cpp
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 */

// @lc code=start
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m > bloomDay.size()/k) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isPossible(bloomDay, mid, m, k)){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }

    bool isPossible(vector<int>& bloomDay, int day, int m, int k){
        int count = 0;
        int noOfB = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day) count++;
            else{
                noOfB += count/k;
                count = 0;
            }
        }
        noOfB += count/k;
        if(noOfB >= m) {
            return true;
        }
        else return false;
    }
};
// @lc code=end

