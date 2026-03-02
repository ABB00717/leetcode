/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
class Solution {
private:
  int dfs(TreeNode* root, int greatest) {
    if (root == nullptr)
      return 0;
    
    int good = 0;
    if (root->val >= greatest) {
      greatest = root->val;
      good = 1;
    }

    return good + dfs(root->left, greatest) + dfs(root->right, greatest);
  }
public:
  int goodNodes(TreeNode *root) {
    return 1 + dfs(root->left, root->val) + dfs(root->right, root->val);
  }
};
// @lc code=end
