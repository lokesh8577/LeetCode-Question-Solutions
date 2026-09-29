class Solution {
public:
    int solve(int n, vector<int>& dp) {

        if (n == 0) {
            return 1;
        }

        int ans = 0;

        for (int i = 0; i < 5; i++) {
            ans += dp[i];
        }

        return ans;
    }

    int countVowelStrings(int n) {

        vector<int> dp(5, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < 5; j++) {
                dp[j] += dp[j - 1];
            }
        }

        int ans = 0;

        for (int x : dp) {
            ans += x;
        }

        return ans;
    }
};