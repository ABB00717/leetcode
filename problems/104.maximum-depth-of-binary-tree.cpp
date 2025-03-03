/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
#include <algorithm>
class Solution {
private:
  int dfs(TreeNode* root, int level) {
    if (root == nullptr)
      return level;

    return std::max(dfs(root->left, level+1), dfs(root->right, level+1));
  }
public:
  int maxDepth(TreeNode *root) {
    return dfs(root, 0);
  }
};
// @lc code=end
