#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1552 lang=cpp
 *
 * [1552] Magnetic Force Between Two Balls
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int low = 1;
        int high = position[n-1] - position[0];

        while(low <= high){
            int mid =low + (high - low)/2;

            if(canWePlace(position, mid, m)){
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return high;
    }

    bool canWePlace(vector<int>& arr,int dist, int m){
        int count = 1;
        int last = arr[0];
        for(int i = 0; i < arr.size() ; i++){
            if(arr[i] - last >= dist){
                count++;
                last = arr[i];
            }
            if(count >= m) return true;
        }
        return false;
    }
};
// @lc code=end

