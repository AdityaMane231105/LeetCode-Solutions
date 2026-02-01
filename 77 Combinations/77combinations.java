class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(1, n, k, new ArrayList<>(), result);
        return result;
    }

    private void backtrack(int start, int n, int k, List<Integer> current, List<List<Integer>> result) {
        // Base case: if current combination is of size k, add it to results
        if (current.size() == k) {
            result.add(new ArrayList<>(current));
            return;
        }

        // Optimization: Pruning the loop to avoid unnecessary branches
        // Only iterate if there are enough remaining numbers to fill the k slots
        for (int i = start; i <= n - (k - current.size()) + 1; i++) {
            current.add(i); // Choose the current number
            backtrack(i + 1, n, k, current, result); // Recurse to find the next number
            current.remove(current.size() - 1); // Backtrack: remove the number for the next choice
        }
    }
}
