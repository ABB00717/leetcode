#
# @lc app=leetcode id=787 lang=python3
#
# [787] Cheapest Flights Within K Stops
#

# @lc code=start
import collections
import heapq
from multiprocessing import heap


class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        graph = collections.defaultdict(list)

        for source, target, price in flights:
            graph[source].append((target, price))

        pq = [(0, src, 0)] # price, node, stops
        visited = {} # (node, stops)

        cheapest_price = float('inf')
        while pq:
            price, node, stops = heapq.heappop(pq)

            if node == dst:
                cheapest_price = min(cheapest_price, price)
                continue

            if stops > k:
                continue

            if (node, stops) in visited and visited[(node, stops)] <= price:
                continue

            visited[(node, stops)] = price

            for target, weight in graph[node]:
                new_price = price + weight

                if (target, stops + 1) not in visited or new_price < visited[(target, stops + 1)]:
                    heapq.heappush(pq, (new_price, target, stops + 1))

        return cheapest_price if cheapest_price != float('inf') else -1        
# @lc code=end
