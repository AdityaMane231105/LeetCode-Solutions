func equalPairs(grid [][]int) int {
    n := len(grid)
    rowMap := make(map[string]int)
    for i := 0; i < n; i++ {
        key := fmt.Sprint(grid[i])
        rowMap[key]++
    }
    count := 0
    for j := 0; j < n; j++ {
        col := make([]int, n)
        for i := 0; i < n; i++ {
            col[i] = grid[i][j]
        }
        key := fmt.Sprint(col)
        count += rowMap[key]
    }
    return count
}
