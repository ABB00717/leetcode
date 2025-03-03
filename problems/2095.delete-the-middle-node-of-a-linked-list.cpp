/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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
  ListNode *deleteMiddle(ListNode *head) {
    int n = 0;
    ListNode *node = head;

    while (node != nullptr) {
      node = node->next;
      n++;
    }

    if (n == 1) {
      return nullptr;
    }

    int mid = n / 2;
    ListNode* cur = head;
    for (int i = 0; i < mid-1; i++) {
      cur = cur->next;
    }
    cur->next = cur->next->next;

    return head;
  }
};
// @lc code=end
