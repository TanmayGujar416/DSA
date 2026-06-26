/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
  ListNode* reverseLL(ListNode* head){
  if(head == NULL || head->next == NULL) return head;
  ListNode* temp = head;
  ListNode* prev = NULL;
  while(temp != NULL){
    ListNode* front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;
  }
  return prev;
}

bool isPalindrome(ListNode* head){
  if(head == NULL || head->next == NULL) return true;
  ListNode* slow = head;
  ListNode* fast = head;
  while(fast->next != NULL && fast->next->next !=NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  ListNode* newHead = reverseLL(slow->next);
  ListNode* first = head;
  ListNode* second = newHead;
  bool isplaindrome = true;
  while(second != NULL){
    if(first->val != second->val){
      isplaindrome = false;
      break;
    }

    first = first->next;
    second = second->next;
  }
  newHead = reverseLL(newHead);
  return isplaindrome;
}
};
// @lc code=end

