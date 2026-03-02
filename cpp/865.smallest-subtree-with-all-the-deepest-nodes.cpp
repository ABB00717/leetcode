/*
 * @lc app=leetcode id=865 lang=cpp
 *
 * [865] Smallest Subtree with all the Deepest Nodes
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    // To find the lowest common ancestor (LCA) of the deepest leaves in a binary tree,
    // we can perform a DFS to find the deepest level and use a map to track the parent of each node.
    // Then, we can reduce the nodes at the deepest level to their lowest common ancestor.
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root)
            return nullptr;  // If the tree is empty, return nullptr.

        std::unordered_map<TreeNode*, TreeNode*>
            parentMap;            // Map to store parent of each node.
        std::queue<TreeNode*> q;  // Queue for level-order traversal.
        q.push(root);
        std::vector<TreeNode*>
            lastLevel;  // Vector to store nodes of the last level.

        // Perform level-order traversal to find the deepest level nodes.
        while (!q.empty()) {
            int size = q.size();
            lastLevel.clear();  // Clear previous level for the current level.

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                lastLevel.push_back(
                    node);  // Add current node to the last level vector.

                // Add left child to the queue and update its parent in the map.
                if (node->left) {
                    q.push(node->left);
                    parentMap[node->left] = node;
                }

                // Add right child to the queue and update its parent in the map.
                if (node->right) {
                    q.push(node->right);
                    parentMap[node->right] = node;
                }
            }
        }

        // Reduce the last level nodes to their lowest common ancestor.
        while (lastLevel.size() > 1) {
            std::unordered_set<TreeNode*>
                parents;  // Set to store unique parents.
            for (auto node : lastLevel) {
                parents.insert(
                    parentMap[node]);  // Add parent of each node to the set.
            }
            lastLevel.assign(parents.begin(),
                             parents.end());  // Update last level with parents.
        }

        return lastLevel
            [0];  // The remaining node is the LCA of the deepest leaves.
    }
};

// @lc code=end
