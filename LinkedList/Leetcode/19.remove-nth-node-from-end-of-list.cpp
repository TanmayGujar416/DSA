/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;

        for(int i = 0; i < n; i++){
            fast = fast->next;
        }
        if(fast == NULL){
            ListNode* dNode = head;
            head = head->next;
            delete dNode;
            return head;
        }
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* dNode = slow->next;
        slow->next = slow->next->next;
        delete dNode;
        return head;
    }
};
// @lc code=end

