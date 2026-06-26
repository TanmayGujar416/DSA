#include<bits/stdtr1c++.h>
using namespace std;

/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start

//Definition for singly-linked list.


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            if(temp->val == val){
                ListNode* cur = temp;
                temp = temp->next;      // move first
                prev->next = temp;
                delete cur;
            }
            else{
            prev = temp;
            temp = temp->next;
            }
        }
        return head;
    }
};
// @lc code=end

