class Solution {
private:
    // recursion solution
    void Solve(vector<vector<int>>& obstacleGrid, int i, int j, int& ans) {
        // base case
        if (i >= obstacleGrid.size() || j >= obstacleGrid[0].size()) {
            return;
        }

        if (i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1) {
            ans++;
            return;
        }

        // down side
        if (i + 1 < obstacleGrid.size() && obstacleGrid[i + 1][j] == 0) {
            Solve(obstacleGrid, i + 1, j, ans);
        }

        // right side
        if (j + 1 < obstacleGrid[0].size() && obstacleGrid[i][j + 1] == 0) {
            Solve(obstacleGrid, i, j + 1, ans);
        }
    }


    //Recursion + Dp
    int SolveDp(vector<vector<int>>& obstacleGrid, int i, int j,
                vector<vector<int>>& dp) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (i >= m || j >= n) {
            return 0;
        }

        if (obstacleGrid[i][j] == 1) {
            return 0;
        }

        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Down
        int down = SolveDp(obstacleGrid, i + 1, j, dp);

        // Right
        int right = SolveDp(obstacleGrid, i, j + 1, dp);

        return dp[i][j] = down + right;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return SolveDp(obstacleGrid, 0, 0, dp);
    }
};
