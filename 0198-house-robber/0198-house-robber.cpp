class Solution {
public:
    int Solve(int n, vector<int>& nums,vector<int>&dp) {
        if (n == 0) {
            return nums[0];
        }

        if (n < 0) {
            return 0;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int include = Solve(n - 2, nums,dp) + nums[n];
        int exclude = Solve(n - 1, nums,dp);

        dp[n] = max(include, exclude);
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int>dp(n+1,-1);
        return Solve(n, nums,dp);
    }
};