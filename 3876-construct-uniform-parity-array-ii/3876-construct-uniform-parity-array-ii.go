func uniformArray(nums1 []int) bool {
    n := len(nums1)

    allOdd := true
    allEven := true
    for i := 0; i < n; i++ {
        if nums1[i]%2 == 0 {
            allOdd = false
        } else {
            allEven = false
        }
    }
    if allOdd || allEven {
        return true
    }

    minVal := nums1[0]
    for i := 1; i < n; i++ {
        if nums1[i] < minVal {
            minVal = nums1[i]
        }
    }

    return minVal%2 == 1
}
