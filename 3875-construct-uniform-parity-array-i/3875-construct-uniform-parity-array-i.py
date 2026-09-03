class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        if len(nums1) == 1:
            return nums1[0] % 2 == 0 or nums1[0] % 2 == 1
        return True
