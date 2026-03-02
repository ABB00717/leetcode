/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>
#include <cmath>
#include <vector>
class Solution {
private:
  bool getPath(TreeNode* node, TreeNode* targetNode, std::vector<TreeNode*>& path) {
    if (!node)
      return false;

    path.push_back(node);
    if (node == targetNode)
      return true;
    if (getPath(node->left, targetNode, path) || getPath(node->right, targetNode, path))
      return true;

    path.pop_back();
    return false;
  }

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    std::vector<TreeNode*> pPath, qPath;
    getPath(root, p, pPath);
    getPath(root, q, qPath);

    int i = 0, len = std::min(pPath.size(), qPath.size());
    while (i < len && pPath[i] == qPath[i]) {
      i++;
    }
    return pPath[i-1];
  }
};
// @lc code=end
