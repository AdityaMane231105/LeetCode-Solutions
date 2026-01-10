class Solution(object):
    def totalNQueens(self, n):
        cols = [False] * n
        pos_diag = [False] * (2 * n)  # row + col
        neg_diag = [False] * (2 * n)  # row - col + n
        self.count = 0

        def backtrack(r):
            if r == n:
                self.count += 1
                return

            for c in range(n):
                # Check for conflicts
                if cols[c] or pos_diag[r + c] or neg_diag[r - c + n]:
                    continue

                # Place queen
                cols[c] = pos_diag[r + c] = neg_diag[r - c + n] = True
                
                # Move to next row
                backtrack(r + 1)

                # Backtrack: remove queen
                cols[c] = pos_diag[r + c] = neg_diag[r - c + n] = False

        backtrack(0)
        return self.count
