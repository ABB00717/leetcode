/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
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
#include <algorithm>
#include <climits>
#include <cstddef>
#include <stack>
class Solution {
public:
  int pairSum(ListNode *head) {
    ListNode *slow = head->next;
    ListNode *fast = head->next->next;
    while (fast != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *newHead = slow;
    ListNode *prev = nullptr;
    ListNode *next = newHead->next;
    while (newHead != nullptr) {
      next = newHead->next;
      newHead->next = prev;
      prev = newHead;
      newHead = next;
    }

    ListNode *rHead = prev;
    ListNode *lHead = head;
    int result = 0;
    while (rHead != nullptr) {
      result = std::max(result, rHead->val + lHead->val);
      rHead = rHead->next;
      lHead = lHead->next;
    }

    return result;
  }
};
// @lc code=end
