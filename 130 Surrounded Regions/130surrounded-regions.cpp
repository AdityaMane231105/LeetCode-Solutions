class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c) {
        int m = board.size();
        int n = board[0].size();
        
        // Base case: Out of bounds or not an 'O'
        if (r < 0 || c < 0 || r >= m || n <= c || board[r][c] != 'O') {
            return;
        }
        
        // Mark as "Safe"
        board[r][c] = '#';
        
        // Explore neighbors
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        // 1. Traverse borders to find 'O's and mark connected regions
        for (int i = 0; i < m; i++) {
            dfs(board, i, 0);     // Left border
            dfs(board, i, n - 1); // Right border
        }
        for (int j = 0; j < n; j++) {
            dfs(board, 0, j);     // Top border
            dfs(board, m - 1, j); // Bottom border
        }

        // 2. Flip 'O' to 'X' (captured) and '#' back to 'O' (safe)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
