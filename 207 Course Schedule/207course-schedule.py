from collections import deque

class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        # Step 1: Create adjacency list and in-degree array
        adj = [[] for _ in range(numCourses)]
        in_degree = [0] * numCourses
        
        for dest, src in prerequisites:
            adj[src].append(dest)
            in_degree[dest] += 1
            
        # Step 2: Initialize queue with courses having 0 in-degree
        queue = deque([i for i in range(numCourses) if in_degree[i] == 0])
        
        # Step 3: Process the queue
        visited_count = 0
        while queue:
            node = queue.popleft()
            visited_count += 1
            
            for neighbor in adj[node]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)
                    
        # Step 4: If visited vertices equal total courses, no cycle exists
        return visited_count == numCourses
