class Solution {
public:
    void Solve(int i, int j, vector<vector<int>>& grid,
               vector<vector<bool>>& visited) {
        // base case
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return;
        }

        visited[i][j] = true;
        // up side
        if (i - 1 >= 0 && grid[i - 1][j] == 1 && !visited[i - 1][j]) {
            Solve(i - 1, j, grid, visited);
        }
        // down side
        if (i + 1 < grid.size() && grid[i + 1][j] == 1 && !visited[i + 1][j]) {
            Solve(i + 1, j, grid, visited);
        }

        // right side
        if (j + 1 < grid[0].size() && grid[i][j + 1] == 1 &&
            !visited[i][j + 1]) {
            Solve(i, j + 1, grid, visited);
        }

        // left side
        if (j - 1 >= 0 && grid[i][j - 1] == 1 && !visited[i][j - 1]) {
            Solve(i, j - 1, grid, visited);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // top and bottom
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1 && !visited[0][i]) {
                Solve(0, i, grid, visited);
            }
            if (grid[m - 1][i] == 1 && !visited[m - 1][i]) {
                Solve(m - 1, i, grid, visited);
            }
        }

        // left and right
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1 && !visited[i][0]) {
                Solve(i, 0, grid, visited);
            }
            if (grid[i][n - 1] == 1 && !visited[i][n - 1]) {
                Solve(i, n - 1, grid, visited);
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // cout << visited[i][j] << " ";
                if (grid[i][j] == 1 && !visited[i][j]) {
                    ans++;
                }
            }
            // cout << endl;
        }
        return ans;
    }
};