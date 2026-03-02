#
# @lc app=leetcode id=3372 lang=python3
#
# [3372] Maximize the Number of Target Nodes After Connecting Trees I
#

# @lc code=start
from collections import deque
from typing import List

class Solution:
    def find_path(self, n: int, path: List[List[int]], start: int, k: int) -> List[int]:
        if k < 0:
            return 0
        
        queue = deque([(start, 0)])
        visited = {start}
        count = 0

        while queue:
            node, depth = queue.popleft()

            if depth > k:
                continue
            count += 1
            
            for next_node in path[node]:
                if next_node not in visited:
                    visited.add(next_node)
                    queue.append((next_node, depth + 1))

        return count
                
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]], k: int) -> List[int]:
        if k == 0:
            return [1] * (len(edges1) + 1)
        
        n = len(edges1) + 1
        m = len(edges2) + 1
        
        path1 = [[] for _ in range(n)]
        for edge in edges1:
            path1[edge[0]].append(edge[1])
            path1[edge[1]].append(edge[0])

        path2 = [[] for _ in range(m)]
        for edge in edges2:
            path2[edge[0]].append(edge[1])
            path2[edge[1]].append(edge[0])

        # find max_path(k-1) for tree2
        max_path_for_tree2 = 0
        for i in range(m):
            max_path_for_tree2 = max(max_path_for_tree2, self.find_path(m, path2, i, k-1))
        
        answer = [0] * n
        for i in range(n):
            possible_path_in_k = self.find_path(n, path1, i, k)
            answer[i] = possible_path_in_k + max_path_for_tree2

        return answer
# @lc code=end

