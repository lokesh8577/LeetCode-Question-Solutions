class Solution {
private:
    int Solve(int i, int n, vector<int>& costs,vector<int>&dp) {
        if (i == n) {
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int a = INT_MAX, b = INT_MAX, c = INT_MAX;

        if (i + 1 <= n) {
            a = costs[i] + 1 + Solve(i + 1, n, costs,dp);
        }

        if (i + 2 <= n) {
            b = costs[i + 1] + 4 + Solve(i + 2, n, costs,dp);
        }

        if (i + 3 <= n) {
            c = costs[i + 2] + 9 + Solve(i + 3, n, costs,dp);
        }

        dp[i] = min(a, min(b, c));
        return dp[i];
    }

public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        return Solve(0, n, costs,dp);
    }
};