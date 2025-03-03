/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
  ListNode *oddEvenList(ListNode *head) {
    if (head == nullptr)
      return nullptr;
    
    ListNode *odd = head, *even = head->next;
    if (even == nullptr || even->next == nullptr)
      return head; 
    
    while (even != nullptr && even->next != nullptr) {
      ListNode* evenNext = even->next;
      even->next = evenNext->next;
      even = even->next;
      evenNext->next = odd->next;
      odd->next = evenNext;
      odd = odd->next;
    }

    return head;
  }
};
// @lc code=end
