class Solution {
private:
    int Solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {

        if (i >= grid.size() || j >= grid[0].size())
            return INT_MAX;

        if (i == grid.size()-1 && j == grid[0].size()-1)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = Solve(grid, i+1, j, dp);
        int right = Solve(grid, i, j+1, dp);

        return dp[i][j] = grid[i][j] + min(down, right);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return Solve(grid, 0, 0, dp);
    }
};