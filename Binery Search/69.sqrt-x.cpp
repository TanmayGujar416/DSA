/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1)
            return x;

        int low = 1;
        int high = x;
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(mid <= x / mid){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end

