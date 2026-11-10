class Solution {
private:
    // Recursion + dp
    int Solve(int i, int n, vector<int>& costs, vector<int>& dp) {
        if (i == n) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int a = INT_MAX, b = INT_MAX, c = INT_MAX;

        if (i + 1 <= n) {
            a = costs[i] + 1 + Solve(i + 1, n, costs, dp);
        }

        if (i + 2 <= n) {
            b = costs[i + 1] + 4 + Solve(i + 2, n, costs, dp);
        }

        if (i + 3 <= n) {
            c = costs[i + 2] + 9 + Solve(i + 3, n, costs, dp);
        }

        dp[i] = min(a, min(b, c));
        return dp[i];
    }

    int Solve(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 0; i < n; i++) {

            if (i + 1 <= n) {
                dp[i + 1] = min(dp[i + 1], dp[i] + costs[i] + 1);
            }

            if (i + 2 <= n) {
                dp[i + 2] = min(dp[i + 2], dp[i] + costs[i + 1] + 4);
            }

            if (i + 3 <= n) {
                dp[i + 3] = min(dp[i + 3], dp[i] + costs[i + 2] + 9);
            }
        }

        return dp[n];
    }

public:
    int climbStairs(int n, vector<int>& costs) {
        // vector<int>dp(n+1,-1);
        return Solve(n, costs);
    }
};