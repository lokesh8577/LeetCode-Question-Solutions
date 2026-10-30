class Solution {
private:
    int Solve(int index, vector<int>& coins, int amount,
              vector<vector<int>>& dp) {

        if (amount == 0) {
            return 0;
        }

        if (amount < 0 || index >= coins.size()) {
            return INT_MAX;
        }

        if (dp[index][amount] != -1) {
            return dp[index][amount];
        }
        int take = INT_MAX;

        int result = Solve(index, coins, amount - coins[index], dp);

        if (result != INT_MAX) {
            take = 1 + result;
        }

        int skip = Solve(index + 1, coins, amount, dp);

        return dp[index][amount] = min(take, skip);
    }

public:
    int coinChange(vector<int>& coins, int amount) {

        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

        int ans = Solve(0, coins, amount, dp);

        return ans == INT_MAX ? -1 : ans;
    }
};