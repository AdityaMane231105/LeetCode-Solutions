#include <stdbool.h>
#include <string.h>

bool backtrack(char** board, int r, int c, int rows, int cols, char* word, int index) {
    // Base Case: All characters in the word are found
    if (word[index] == '\0') return true;

    // Boundary and match checks
    if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[index]) {
        return false;
    }

    // Mark current cell as visited
    char temp = board[r][c];
    board[r][c] = '#';

    // Explore 4 directions
    bool found = backtrack(board, r + 1, c, rows, cols, word, index + 1) ||
                 backtrack(board, r - 1, c, rows, cols, word, index + 1) ||
                 backtrack(board, r, c + 1, rows, cols, word, index + 1) ||
                 backtrack(board, r, c - 1, rows, cols, word, index + 1);

    // Backtrack: Restore the original character
    board[r][c] = temp;

    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int rows = boardSize;
    int cols = boardColSize[0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Start DFS if the first character matches
            if (board[i][j] == word[0]) {
                if (backtrack(board, i, j, rows, cols, word, 0)) return true;
            }
        }
    }
    return false;
}
