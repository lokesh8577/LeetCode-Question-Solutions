class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        const long long MOD = 1e9 + 7;
        long long ans = 0;
        for (auto num : nums) {
            int width = num % 10;
            string s = to_string(num / 10);

            long long x = 0;
            long long y = 0;

            for (int i = 0; i < width; i++) {
                x = x * 10 + (s[i] - '0');
            }

            for (int i = width; i < s.size(); i++) {
                y = y * 10 + (s[i] - '0');
            }

            long long power = 1;
            while (y > 0) {
                if (y & 1) {
                    power = (power * x) % MOD;
                }

                x = (x * x) % MOD;
                y >>= 1;
            }

            ans = (ans + power) % MOD;
        }

        return ans;
    }
};