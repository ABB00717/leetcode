/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
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
#include <climits>
#include <vector>
class Solution {
private:
  void bfs(TreeNode* node, std::vector<long long>& levelSum, int level) {
    if (!node)
      return;

    if (levelSum.size() == level)
      levelSum.push_back(node->val);
    else
      levelSum[level] += node->val;

    bfs(node->left, levelSum, level+1);
    bfs(node->right, levelSum, level+1);
  }
public:
  int maxLevelSum(TreeNode *root) {
    std::vector<long long> levelSum;
    levelSum.reserve(10e4);

    bfs(root, levelSum, 0);

    long long maxLevel = 0;
    for (int i = 0; i < levelSum.size(); i++) {
      if (levelSum[maxLevel] < levelSum[i])
        maxLevel = i;
    }

    return maxLevel+1;
  }
};
// @lc code=end
