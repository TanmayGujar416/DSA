#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> result(nums.size());

        for(int i = 2*nums.size() - 1; i >= 0; i--){
            int index = i%(nums.size());
            while(!st.empty() && st.top() <= nums[index]){
                st.pop();
            }
            if( i < nums.size()){
                result[index] = st.empty() ? -1:st.top();
            }
            st.push(nums[index]);
        }
        return result;
    }
};
// @lc code=end

