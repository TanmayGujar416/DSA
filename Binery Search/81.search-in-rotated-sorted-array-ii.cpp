/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high -low)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[mid] == nums[low] && nums[mid] == nums[high]){
                low++;
                high--;
            }
            else if(nums[high] >= nums[mid]){
                if(nums[mid] <= target && nums[high] >= target){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            else{
                if(nums[mid] >= target && nums[low] <= target){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        return false;
    }
};
// @lc code=end

