#
# @lc app=leetcode id=3373 lang=python3
#
# [3373] Maximize the Number of Target Nodes After Connecting Trees II
#

# @lc code=start
from typing import List
from collections import deque

class Solution:
    def bfs_traverse(self, graph: List[List[int]], start: int, callback=None):
        queue = deque([(start, 0)])
        visited = {start}
        
        while queue:
            node, depth = queue.popleft()
            
            if callback:
                callback(node, depth)
            
            for next_node in graph[node]:
                if next_node not in visited:
                    visited.add(next_node)
                    queue.append((next_node, depth + 1))

    def find_path(self, n: int, path: List[List[int]], start: int, even: bool) -> int:
        count = 0
        
        def count_nodes(node, depth):
            nonlocal count
            if depth % 2 == 0 and even:
                count += 1
            elif depth % 2 == 1 and not even:
                count += 1
        
        self.bfs_traverse(path, start, count_nodes)
        return count
    
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]]) -> List[int]:
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
        
        # find max_odd_path for tree2
        max_odd_path = 0
        for i in [edges2[0][0], edges2[0][1]]:
            max_odd_path = max(max_odd_path, self.find_path(m, path2, i, False))
        
        ans = [0] * (len(edges1) + 1)
        first_path = self.find_path(n, path1, edges1[0][0], True)
        second_path = self.find_path(n, path1, edges1[0][1], True)
        
        def assign_answer(node, depth):
            if depth % 2 == 0:
                ans[node] = first_path + max_odd_path
            elif depth % 2 == 1:
                ans[node] = second_path + max_odd_path
        
        self.bfs_traverse(path1, edges1[0][0], assign_answer)
        
        return ans
# @lc code=end

