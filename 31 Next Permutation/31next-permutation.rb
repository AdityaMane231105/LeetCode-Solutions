# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.
def next_permutation(nums)
  n = nums.length

  # Step 1: find pivot
  i = n - 2
  i -= 1 while i >= 0 && nums[i] >= nums[i + 1]

  if i >= 0
    # Step 2: find successor
    j = n - 1
    j -= 1 while nums[j] <= nums[i]
    nums[i], nums[j] = nums[j], nums[i]
  end

  # Step 3: reverse suffix
  left = i + 1
  right = n - 1
  while left < right
    nums[left], nums[right] = nums[right], nums[left]
    left += 1
    right -= 1
  end
end