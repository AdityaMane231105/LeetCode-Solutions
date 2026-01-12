class Solution(object):
    def minTimeToVisitAllPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        total_time = 0
        
        # Iterate through points from the first to the second-to-last
        for i in range(len(points) - 1):
            # Get current point and next point
            p1 = points[i]
            p2 = points[i + 1]
            
            # The time to move between two points is the max of the 
            # absolute differences of their coordinates.
            dx = abs(p2[0] - p1[0])
            dy = abs(p2[1] - p1[1])
            
            total_time += max(dx, dy)
            
        return total_time
