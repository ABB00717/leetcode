#
# @lc app=leetcode id=1857 lang=python3
#
# [1857] Largest Color Value in a Directed Graph
#

# @lc code=start
from collections import defaultdict, deque
from typing import List


class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        n = len(colors)
        adj = defaultdict(list)
        in_degree = [0] * n

        for u, v in edges:
            if u == v:
                return -1
            
            adj[u].append(v)
            in_degree[v] += 1
        
        dp = [[0] * 26 for _ in range(n)]

        queue = deque()
        for i in range(n):
            if in_degree[i] == 0:
                queue.append(i)
                dp[i][ord(colors[i]) - ord('a')] = 1

        visited = 0
        max_value = 0
        while queue:
            node = queue.popleft()
            visited += 1
            max_value = max(max_value, max(dp[node]))

            for neighbor in adj[node]:
                for i in range(26):
                    is_color = 1 if i == ord(colors[neighbor]) - ord('a') else 0
                    dp[neighbor][i] = max(dp[neighbor][i], dp[node][i] + is_color)

                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)

        return max_value if visited == n else -1

# @lc code=end

