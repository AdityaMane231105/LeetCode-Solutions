class Solution(object):
    def uniqueOccurrences(self, arr):
        # Step 1: Count occurrences of each number
        counts = {}
        for num in arr:
            counts[num] = counts.get(num, 0) + 1
        # Step 2: Check if frequencies are unique
        occurrences = counts.values()
        return len(occurrences) == len(set(occurrences))
