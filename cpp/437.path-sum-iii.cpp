/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <unordered_map>
#include <vector>
class Solution {
private:
  int dfs(TreeNode* root, long long currSum, int targetSum, std::unordered_map<long long, int>& freq) {
    if (root == nullptr)
      return 0;
    
    int res = 0;
    currSum += root->val;

    if (currSum == targetSum) {
      res++;
    }

    if (freq.find(currSum - targetSum) != freq.end()) {
      res += freq[currSum - targetSum];
    }

    freq[currSum]++;
    res += dfs(root->left, currSum, targetSum, freq);
    res += dfs(root->right, currSum, targetSum, freq);

    freq[currSum]--;
    if (freq[currSum] == 0) {
      freq.erase(currSum);
    }

    return res;
  }
public:
  int pathSum(TreeNode *root, int targetSum) {
    std::unordered_map<long long, int> freq;
    
    return dfs(root, 0, targetSum, freq);
  }
};
// @lc code=end
