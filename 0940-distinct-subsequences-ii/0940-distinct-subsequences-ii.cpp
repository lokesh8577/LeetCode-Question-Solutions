class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();

        vector<long long> dp(n + 1, 0);

        dp[0] = 1;

        vector<int> last(26, -1);

        for (int i = 1; i <= n; i++) {
            int ch = s[i - 1] - 'a';

            dp[i] = 2 * dp[i - 1];

            if (last[ch] != -1) {
                dp[i] -= dp[last[ch]];
            }

            last[ch] = i - 1;

            dp[i] %= 1000000007;
        }

        return (dp[n] - 1 + 1000000007) % 1000000007;
    }
};