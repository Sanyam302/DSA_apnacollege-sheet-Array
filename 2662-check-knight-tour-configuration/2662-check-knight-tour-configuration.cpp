class Solution {
public:
    bool isvalid(int row, int col, int prevrow, int prevcol) {
        return (abs(prevcol - col) == 2 && abs(prevrow - row) == 1) ||
               (abs(prevcol - col) == 1 && abs(prevrow - row) == 2);
    }

    bool valid(vector<vector<int>>& grid, int n, int row, int col, int num) {
        if (num == n * n - 1) return true; // Last move reached

        int newrow = -1, newcol = -1;
        // Find the cell with value num+1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == num + 1) {
                    newrow = i;
                    newcol = j;
                    break;
                }
            }
            if (newrow != -1) break;
        }
        if (newrow == -1) return false; // Could not find next move

        if (isvalid(newrow, newcol, row, col)) {
            return valid(grid, n, newrow, newcol, num + 1);
        }

        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        // Knight must start at (0, 0) and grid[0][0] == 0
        if (grid[0][0] != 0) return false;
        return valid(grid, n, 0, 0, 0);
    }
};