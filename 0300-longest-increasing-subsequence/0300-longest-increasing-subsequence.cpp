
class Solution {
private:
    int Solve(vector<int>& nums, int index, int prev,
              vector<vector<int>>& dp) {
        if (index == nums.size()) {
            return 0;
        }

        if (dp[index][prev + 1] != -1) {
            return dp[index][prev + 1];
        }

        int take = 0;

        if (prev == -1 || nums[index] > nums[prev]) {
            take = 1 + Solve(nums, index + 1, index, dp);
        }

        int skip = Solve(nums, index + 1, prev, dp);

        return dp[index][prev + 1] = max(take, skip);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return Solve(nums, 0, -1, dp);
    }
};
