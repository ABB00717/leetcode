/*
 * @lc app=leetcode id=3108 lang=cpp
 *
 * [3108] Minimum Cost Walk in Weighted Graph
 */

// @lc code=start
#include <utility>
#include <vector>

class Solution {
   public:
    std::vector<int> minimumCost(int n, std::vector<std::vector<int>>& edges,
                                 std::vector<std::vector<int>>& queries) {
        // Initialize the parent array with -1 as initially each node 
        // belongs to its own component
        parent.resize(n, -1);
        depth.resize(n, 0);

        // All values are initially set to the nuumber with only 1s in 
        // its binary representation
        std::vector<unsigned int> componentCost(n, -1);

        // Construct the connected components
        for (auto& edge : edges) {
            Union(edge[0], edge[1]);
        }

        
        for (auto& edge : edges) {
            int root = find(edge[0]);
            componentCost[root] &= edge[2];
        }

        std::vector<int> answer;
        for (auto& query : queries) {
            int start = query[0];
            int end = query[1];

            if (find(start) != find(end)) {
                answer.push_back(-1);
            } else {
                int root = find(start);
                answer.push_back(componentCost[root]);
            }
        }

        return answer;
    }

   private:
    std::vector<int> parent;
    std::vector<int> depth;

    int find(int node) {
        if (parent[node] == -1)
            return node;

        return parent[node] = find(parent[node]);
    }

    void Union(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);

        if (root1 == root2)
            return;

        parent[root2] = root1;
    }
};

// @lc code=end
