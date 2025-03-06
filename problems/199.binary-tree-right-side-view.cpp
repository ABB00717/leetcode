/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
  void bfs(TreeNode* node, std::vector<TreeNode*>& rightSideNodes, int level) {
    if (node == nullptr)
      return;

    rightSideNodes[level] = node;
    bfs(node->left, rightSideNodes, level+1);
    bfs(node->right, rightSideNodes, level+1);
  }
public:
  vector<int> rightSideView(TreeNode *root) {
    std::vector<TreeNode*> rightSideNodes(100, nullptr);

    bfs(root, rightSideNodes, 0);
    
    std::vector<int> result;
    for (int i = 0; rightSideNodes[i] != nullptr; i++) {
      result.push_back(rightSideNodes[i]->val);
    }
    return result;
  }
};
// @lc code=end
