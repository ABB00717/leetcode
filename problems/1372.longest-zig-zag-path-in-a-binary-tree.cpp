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
  int maxPath = 0;
  void dfs(TreeNode* node, const bool &prevDir, int curPath) {
    if (!node)
      return;
    maxPath = std::max(maxPath, curPath);
  
    if (prevDir != RIGHT) {
      dfs(node->left, LEFT, 1);
      dfs(node->right, RIGHT, curPath+1);
    } else {
      dfs(node->left, LEFT, curPath+1);
      dfs(node->right, RIGHT, 1);
    }
  }

public:
  int longestZigZag(TreeNode *root) {
    dfs(root->left, LEFT, 1);
    dfs(root->right, RIGHT, 1);

    return maxPath;
  }
};
// @lc code=end
