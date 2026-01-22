import java.util.*;

class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> results = new ArrayList<>();
        char[][] board = new char[n][n];
        
        // Initialize the board with empty spots
        for (int i = 0; i < n; i++) {
            Arrays.fill(board[i], '.');
        }
        
        // Trackers for columns and diagonals
        Set<Integer> cols = new HashSet<>();
        Set<Integer> posDiag = new HashSet<>(); // (r + c)
        Set<Integer> negDiag = new HashSet<>(); // (r - c)
        
        backtrack(0, n, board, results, cols, posDiag, negDiag);
        return results;
    }
    
    private void backtrack(int r, int n, char[][] board, List<List<String>> results, 
                           Set<Integer> cols, Set<Integer> posDiag, Set<Integer> negDiag) {
        // Base case: If all rows are filled, we found a solution
        if (r == n) {
            results.add(createBoard(board));
            return;
        }
        
        for (int c = 0; c < n; c++) {
            // Check if placing a queen is valid
            if (cols.contains(c) || posDiag.contains(r + c) || negDiag.contains(r - c)) {
                continue;
            }
            
            // "Choose"
            board[r][c] = 'Q';
            cols.add(c);
            posDiag.add(r + c);
            negDiag.add(r - c);
            
            // "Explore" next row
            backtrack(r + 1, n, board, results, cols, posDiag, negDiag);
            
            // "Un-choose" (Backtrack)
            board[r][c] = '.';
            cols.remove(c);
            posDiag.remove(r + c);
            negDiag.remove(r - c);
        }
    }
    
    private List<String> createBoard(char[][] board) {
        List<String> list = new ArrayList<>();
        for (char[] row : board) {
            list.add(new String(row));
        }
        return list;
    }
}
