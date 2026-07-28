class Solution {
private:
    void Solve(vector<vector<int>>& grid, int i, int j, int& temp) {
        grid[i][j] = 0;

        // up side
        if (i - 1 >= 0 && grid[i - 1][j] > 0) {
            temp += grid[i - 1][j];
            Solve(grid, i - 1, j, temp);
        }

        // down side
        if (i + 1 < grid.size() && grid[i + 1][j] > 0) {
            temp += grid[i + 1][j];
            Solve(grid, i + 1, j, temp);
        }

        // right side
        if (j + 1 < grid[0].size() && grid[i][j + 1] > 0) {
            temp += grid[i][j + 1];
            Solve(grid, i, j + 1, temp);
        }

        // down side
        if (j - 1 >= 0 && grid[i][j - 1] > 0) {
            temp += grid[i][j - 1];
            Solve(grid, i, j - 1, temp);
        }
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0) {
                    int temp = grid[i][j];
                    Solve(grid, i, j, temp);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};