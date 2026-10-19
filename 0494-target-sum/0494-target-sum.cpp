class Solution {
private:
    int Solve(vector<int>& nums, int target, int index,
              vector<unordered_map<int, int>>& dp) {

        if (index == 0) {
            if (target == nums[0] && target == -nums[0])
                return 2;

            if (target == nums[0] || target == -nums[0])
                return 1;

            return 0;
        }

        if (dp[index].count(target))
            return dp[index][target];

        int plus = Solve(nums, target - nums[index], index - 1, dp);
        int minus = Solve(nums, target + nums[index], index - 1, dp);

        return dp[index][target] = plus + minus;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<unordered_map<int, int>> dp(n);

        return Solve(nums, target, n - 1, dp);
    }
};