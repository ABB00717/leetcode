#
# @lc app=leetcode id=743 lang=python3
#
# [743] Network Delay Time
#

# @lc code=start
import collections
import heapq


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = collections.defaultdict(list)

        for source, target, weight in times:
            graph[source].append((target, weight))

        dist = {node: float('inf') for node in range(1, n + 1)}
        dist[k] = 0

        pq = [(0, k)] # time, node

        while pq:
            time, node = heapq.heappop(pq)

            if time > dist[node]:
                continue

            for target, weight in graph[node]:
                if dist[target] <= time + weight:
                    continue

                dist[target] = time + weight
                heapq.heappush(pq, (time + weight, target))

        max_time = 0
        for node in dist:
            if dist[node] == float('inf'):
                return -1
            
            max_time = max(max_time, dist[node])
        
        return max_time
# @lc code=end

