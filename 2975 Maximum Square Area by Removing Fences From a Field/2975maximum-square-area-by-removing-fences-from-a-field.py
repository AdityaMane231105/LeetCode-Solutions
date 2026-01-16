class Solution(object):
    def maximizeSquareArea(self, m, n, hFences, vFences):
        """
        :type m: int
        :type n: int
        :type hFences: List[int]
        :type vFences: List[int]
        :rtype: int
        """
        # Add the boundary fences that cannot be removed
        hFences.append(1)
        hFences.append(m)
        vFences.append(1)
        vFences.append(n)
        
        # Sort to calculate distances easily
        hFences.sort()
        vFences.sort()
        
        # Helper function to get all possible distances between any two fences
        def get_distances(fences):
            dist_set = set()
            for i in range(len(fences)):
                for j in range(i + 1, len(fences)):
                    dist_set.add(fences[j] - fences[i])
            return dist_set
        
        h_dists = get_distances(hFences)
        v_dists = get_distances(vFences)
        
        # Find the maximum common distance
        max_side = -1
        for d in h_dists:
            if d in v_dists:
                max_side = max(max_side, d)
        
        if max_side == -1:
            return -1
        
        # Return area modulo 10^9 + 7
        return (max_side * max_side) % (10**9 + 7)
        