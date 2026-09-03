func lexicographicallySmallestArray(nums []int, limit int) []int {
    n := len(nums)

    sortedPairs := make([][2]int, n)
    for i, val := range nums {
        sortedPairs[i] = [2]int{val, i}
    }
    sort.Slice(sortedPairs, func(i, j int) bool {
        return sortedPairs[i][0] < sortedPairs[j][0]
    })

    result := make([]int, n)
    i := 0

    for i < n {
        j := i + 1
        for j < n && sortedPairs[j][0]-sortedPairs[j-1][0] <= limit {
            j++
        }

        groupIndices := make([]int, j-i)
        for k := i; k < j; k++ {
            groupIndices[k-i] = sortedPairs[k][1]
        }
        sort.Ints(groupIndices)

        for k := i; k < j; k++ {
            actualIdx := groupIndices[k-i]
            result[actualIdx] = sortedPairs[k][0]
        }

        i = j
    }

    return result
}
