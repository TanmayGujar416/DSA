#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i<j){
            if(isalnum(s[i]) && isalnum(s[j]) ){
                if(tolower(s[i])!=tolower(s[j])){
                    return false;
                }
                i++;
                j--;
            }
            else if(isalnum(s[i])){
                j--;
            }
            else{
                i++;
            }
        }
        return true;
    }
};
// @lc code=end

