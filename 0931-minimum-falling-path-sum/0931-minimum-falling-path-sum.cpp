
class Solution {
private:
    int Solve(int i, int j, vector<vector<int>>& matrix,
              vector<vector<int>>& dp) {

        int m = matrix.size();
        int n = matrix[0].size();

        if (j < 0 || j >= n) return 1e9;

        if (i == m - 1) return matrix[i][j];

        if (dp[i][j] != INT_MIN) return dp[i][j];

        int a = Solve(i + 1, j, matrix, dp);
        int b = Solve(i + 1, j - 1, matrix, dp);
        int c = Solve(i + 1, j + 1, matrix, dp);

        return dp[i][j] = matrix[i][j] + min({a, b, c});
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MIN));

        int ans = INT_MAX;

        for (int j = 0; j < n; j++) {
            ans = min(ans, Solve(0, j, matrix, dp));
        }

        return ans;
    }
};
