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
#include <stack>
class Solution {
public:
  int pairSum(ListNode *head) {
    int n = 0;
    ListNode *cur = head;
    while (cur != nullptr) {
      n++;
      cur = cur->next;
    }

    std::stack<int> numStack;
    cur = head;
    for (int i = 0; i < n/2; i++) {
      numStack.push(cur->val);
      cur = cur->next;
    }

    int result = 0;
    while (cur != nullptr) {
      result = std::max(result, numStack.top() + cur->val);
      numStack.pop();
      cur = cur->next;
    }

    return result;
  }
};
// @lc code=end
