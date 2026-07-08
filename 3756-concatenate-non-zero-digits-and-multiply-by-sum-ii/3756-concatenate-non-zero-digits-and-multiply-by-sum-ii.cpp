class Solution {
public:
    static const int MOD = 1'000'000'007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> prefX(n), prefS(n);
        vector<int> nz(n);
        vector<long long> pow10(n + 1);

        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        long long x = 0, sum = 0;
        int countNZ = 0;

        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c != '0') {
                int d = c - '0';
                x = (x * 10 + d) % MOD;
                sum = (sum + d) % MOD;
                countNZ++;
            }
            prefX[i] = x;
            prefS[i] = sum;
            nz[i] = countNZ;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int L = q[0], R = q[1];

            long long totalX = prefX[R];
            long long totalS = prefS[R];

            long long leftX = (L > 0 ? prefX[L - 1] : 0);
            long long leftS = (L > 0 ? prefS[L - 1] : 0);

            int zerosToShift = nz[R] - (L > 0 ? nz[L - 1] : 0);

            long long x_sub =
                (totalX - (leftX * pow10[zerosToShift]) % MOD + MOD) % MOD;
            long long s_sub = (totalS - leftS + MOD) % MOD;

            ans.push_back((x_sub * s_sub) % MOD);
        }

        return ans;
    }
};
