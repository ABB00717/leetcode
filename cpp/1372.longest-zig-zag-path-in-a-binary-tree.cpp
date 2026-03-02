/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
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
  const bool RIGHT = true, LEFT = false;
  void dfs(TreeNode* node, bool prevDir, int curPath, int& maxPath) {
    if (!node)
      return;
    maxPath = std::max(maxPath, curPath);
  
    dfs(node->left, LEFT, prevDir == RIGHT ? curPath+1 : 1, maxPath);
    dfs(node->right, RIGHT, prevDir == LEFT ? curPath+1 : 1, maxPath);
  }

public:
  int longestZigZag(TreeNode *root) {
    int maxPath = 0;
    
    dfs(root->left, LEFT, 1, maxPath);
    dfs(root->right, RIGHT, 1, maxPath);

    return maxPath;
  }
};
// @lc code=end
