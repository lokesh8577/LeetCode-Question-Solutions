class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();

        long long mod = 1e9 + 7;
        long long base = 31;

        long long prefixHash = 0;
        long long suffixHash = 0;
        long long power = 1;

        int ans = 0;

        for (int i = 0; i < n - 1; i++) {

            prefixHash = (prefixHash * base + (s[i] - 'a' + 1)) % mod;

            suffixHash = ((s[n - 1 - i] - 'a' + 1) * power + suffixHash) % mod;

            if (prefixHash == suffixHash) {
                ans = i + 1;
            }

            power = (power * base) % mod;
        }

        return s.substr(0, ans);
    }
};