class Solution {
private:
    int Solve(int index, int j, string &s, string &t,
              vector<vector<int>> &dp) {

        if(j == t.size()) {
            return 1;
        }

        if(index == s.size()) {
            return 0;
        }

        if(dp[index][j] != -1) {
            return dp[index][j];
        }

        // Skip
        int skip = Solve(index + 1, j, s, t, dp);

        // Take
        int take = 0;

        if(s[index] == t[j]) {
            take = Solve(index + 1, j + 1, s, t, dp);
        }

        return dp[index][j] = take + skip;
    }

public:
    int numDistinct(string s, string t) {
        unordered_map<char, bool> temp;

        for(auto ch : t) {
            temp[ch] = true;
        }

        string filterString = "";

        for(auto ch : s) {
            if(temp[ch]) {
                filterString += ch;
            }
        }

        vector<vector<int>> dp(
            filterString.size(),
            vector<int>(t.size(), -1)
        );

        return Solve(0, 0, filterString, t, dp);
    }
};