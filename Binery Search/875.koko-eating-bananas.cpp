#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high =  *max_element(piles.begin(), piles.end());
        while(low <= high){
            int mid = low + (high - low)/2;
            long long totalHour = totalHrs(piles, mid);
            if(totalHour <= h){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }

    long long totalHrs(vector<int> &piles,int h){
        long long totalHour = 0;
        for(int i = 0; i < piles.size(); i++){
            totalHour += ceil((double)piles[i]/h);
        }
        return totalHour;
    }
};
// @lc code=end

