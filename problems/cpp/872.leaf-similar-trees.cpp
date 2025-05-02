/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
#include <cstddef>
#include <vector>
class Solution {
private:
  std::vector<int> dfs(TreeNode *root) {
    if (root == nullptr)
      return {};
    
    if (root->left == nullptr && root->right == nullptr)
      return {root->val};
    
    std::vector<int> result, l = dfs(root->left), r = dfs(root->right);
    result.insert(result.end(), l.begin(), l.end());
    result.insert(result.end(), r.begin(), r.end());

    return result;
  }

public:
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    return dfs(root1) == dfs(root2);
  }
};
// @lc code=end
