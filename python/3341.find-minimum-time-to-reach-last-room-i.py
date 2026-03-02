#
# @lc app=leetcode id=3341 lang=python3
#
# [3341] Find Minimum Time to Reach Last Room I
#

# @lc code=start
import heapq
import collections

class Solution:
    def minTimeToReach(self, moveTime: list[list[int]]) -> int:
        n = len(moveTime)
        m = len(moveTime[0])
        
        currentTime = 0
        visited = set()
        nextSteps = []
        availableMoving = collections.deque()
        heapq.heappush(nextSteps, (0, 0, 0))
        
        dr = [0, 1, 0, -1]
        dc = [1, 0, -1, 0]
        
        while nextSteps:
            time, r, c = heapq.heappop(nextSteps)
            currentTime = time
            
            if (r, c) in visited:
                continue
            
            availableMoving.append((currentTime, r, c))
            
            while availableMoving:
                time, r, c = availableMoving.popleft()
                visited.add((r, c))
                
                if r == n - 1 and c == m - 1:
                    return time
                
                for i in range(4):
                    nr, nc = r + dr[i], c + dc[i]
                    
                    if 0 <= nr < n and 0 <= nc < m:
                        if (nr, nc) in visited:
                            continue
                            
                        departureTime = max(time, moveTime[nr][nc])
                        newArrivalTime = departureTime + 1
                        heapq.heappush(nextSteps, (newArrivalTime, nr, nc))
        
        return -1
# @lc code=end

