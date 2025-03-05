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
#include <vector>
class Solution {
private:
  enum dir {
    ROOT,
    RIGHT,
    LEFT,
    ARRIVE,
  };

  std::vector<dir> longestCommonPrefix(const std::vector<dir> &pPath,
                                       const std::vector<dir> &qPath) {
    int len = std::min(pPath.size(), qPath.size());
    int i = 0;

    std::vector<dir> commonPath;
    while (i < len && (pPath.back() == ARRIVE || qPath.back() == ARRIVE)) {
      if (pPath[i] != qPath[i]) {
        commonPath.push_back(ARRIVE);
        return commonPath;
      }

      commonPath.push_back(pPath[i++]);
    }

    return commonPath;
  }

  TreeNode* findNode(TreeNode* node, std::vector<dir> path) {
    if (path.empty() || path.front() == ARRIVE)
      return node;

    dir curDir = path.front();
    path.erase(path.begin());
    if (curDir == LEFT) {
      return findNode(node->left, path);
    } else {
      return findNode(node->right, path);
    }

    return nullptr;
  }

  void dfs(TreeNode* node, TreeNode* targetNode, dir prevDir, std::vector<dir>& path) {
    path.push_back(prevDir);
    if (!node)
      return;
    
    if (node->val == targetNode->val) {
      path.push_back(ARRIVE);
    }
    
    if (path.back() != ARRIVE) {
      dfs(node->left, targetNode, LEFT, path);
    }
    if (path.back() != ARRIVE) {
      path.pop_back();
      dfs(node->right, targetNode, RIGHT, path);
    }
    if (path.back() != ARRIVE) {
      path.pop_back();
    }
  }

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    std::vector<dir> pPath = {}, qPath = {};
    dfs(root, p, ROOT, pPath);
    dfs(root, q, ROOT, qPath);

    std::vector<dir> commonPath = longestCommonPrefix(pPath, qPath);
    commonPath.erase(commonPath.begin());
    return findNode(root, commonPath);
  }
};
// @lc code=end
