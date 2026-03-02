#include <algorithm>
#include <queue>
#include <vector>
class Solution {
public:
  std::vector<int> eventualSafeNodes(std::vector<std::vector<int>> &graph) {
    int n = graph.size();
    std::vector<std::vector<int>> reversedGraph(n, std::vector<int>());
    std::vector<int> indegree(n, 0);

    for (int i = 0; i < n; i++) {
      for (int j : graph[i]) {
        reversedGraph[j].push_back(i);
        indegree[i]++;
      }
    }

    std::queue<int> q;
    for (int i = 0; i < n; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }

    std::vector<int> result;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      result.push_back(node);

      for (int neighbor : reversedGraph[node]) {
        if (--indegree[neighbor] == 0) {
          q.push(neighbor);
        }
      }
    }

    std::sort(result.begin(), result.end());
    return result;
  }
};