// User function Template for C++

class Solution {
public:
    void route(vector<vector<int>> &matrix, int xs, int ys, int xd, int yd, 
               int &ans, int &temp, int row, int col) {
        
        // Destination reached
        if (xs == xd && ys == yd) {
            ans = max(ans, temp);
            return;
        }

        // Mark current cell visited
        matrix[xs][ys] = 0;

        // Right
        if (ys + 1 < col && matrix[xs][ys + 1] == 1) {
            temp++;
            route(matrix, xs, ys + 1, xd, yd, ans, temp, row, col);
            temp--;
        }

        // Left
        if (ys - 1 >= 0 && matrix[xs][ys - 1] == 1) {
            temp++;
            route(matrix, xs, ys - 1, xd, yd, ans, temp, row, col);
            temp--;
        }

        // Down
        if (xs + 1 < row && matrix[xs + 1][ys] == 1) {
            temp++;
            route(matrix, xs + 1, ys, xd, yd, ans, temp, row, col);
            temp--;
        }

        // Up
        if (xs - 1 >= 0 && matrix[xs - 1][ys] == 1) {
            temp++;
            route(matrix, xs - 1, ys, xd, yd, ans, temp, row, col);
            temp--;
        }

        // Unmark current cell (backtrack)
        matrix[xs][ys] = 1;
    }

    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd) {
        int ans = -1;
        int row = matrix.size();
        int col = matrix[0].size();
        int temp = 0;

        if (matrix[xs][ys] == 0 || matrix[xd][yd] == 0) return -1; // no path possible

        route(matrix, xs, ys, xd, yd, ans, temp, row, col);
        return ans;
    }
};
