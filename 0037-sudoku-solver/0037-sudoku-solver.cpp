class Solution {
public:

   bool isSafe(vector<vector<char>>& board, int row, int col, char num) {
    for (int x = 0; x < 9; x++) {
        if (board[row][x] == num) return false;  // Row check
        if (board[x][col] == num) return false;  // Col check
        if (board[3*(row/3) + x/3][3*(col/3) + x%3] == num) return false; // 3x3 box
    }
    return true;
}

bool solve(vector<vector<char>>& board, int row, int col) {
    if (row == 9) return true; // Solved

    if (col == 9) return solve(board, row + 1, 0); // Next row

    if (board[row][col] != '.') return solve(board, row, col + 1); // Skip filled cells

    for (char num = '1'; num <= '9'; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solve(board, row, col + 1)) return true;
            board[row][col] = '.'; // Backtrack
        }
    }
    return false; // No valid number found
}

    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
        return;
    }
};