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
#include <vector>
class Solution {
private:
  int dfs(TreeNode* root, int targetSum, std::vector<long long int> pathSum) {
    if (root == nullptr)
      return 0;
    
    long long int result = 0;
    if (targetSum == root->val)
      result++;

    for (long long int& sum : pathSum) {
      sum += root->val;
      if (sum == targetSum)
        result++;
    }
    pathSum.push_back(root->val);

    return result + dfs(root->left, targetSum, pathSum) + dfs(root->right, targetSum, pathSum);
  }
public:
  int pathSum(TreeNode *root, int targetSum) {
    return dfs(root, targetSum, {});
  }
};
// @lc code=end
