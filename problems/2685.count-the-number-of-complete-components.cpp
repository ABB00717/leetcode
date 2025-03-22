/*
 * @lc app=leetcode id=2685 lang=cpp
 *
 * [2685] Count the Number of Complete Components
 */

// @lc code=start
#include <unordered_map>
#include <vector>

class Solution {
   public:
    int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {
        indegree.resize(n, 0);
        parent.resize(n, -1);

        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            
            indegree[a]++;
            indegree[b]++;
            
            int roota = find(a), rootb = find(b);
            if (roota != rootb) {
                parent[roota] = rootb;
            }
        }

        std::unordered_map<int, int> component_size;
        std::unordered_map<int, int> component_degree_sum;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            component_size[root]++;
            component_degree_sum[root] += indegree[i];
        }

        int result = 0;
        for (const auto& [root, size] : component_size) {
            if (component_degree_sum[root] == size * (size - 1))
                result++;
        }
        
        return result;
    }

   private:
    std::vector<int> indegree;
    std::vector<int> parent;

    int find(int node) {
        if (parent[node] == -1) {
            return node;
        }

        return parent[node] = find(parent[node]);
    }
};

// @lc code=end
