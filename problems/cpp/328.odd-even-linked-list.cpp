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
    ListNode *evenHead = even;    
    while (even != nullptr && even->next != nullptr) {
      odd->next = odd->next->next;
      even->next = even->next->next;
      even = even->next;
      odd = odd->next;
    }

    odd->next = evenHead;
    return head;
  }
};
// @lc code=end
