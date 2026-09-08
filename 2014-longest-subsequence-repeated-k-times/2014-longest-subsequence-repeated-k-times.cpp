class Solution {
public:
    bool check(string &s, string &t, int k) {
        int j = 0;

        for (char c : s) {
            if (c == t[j]) {
                j++;

                if (j == t.size()) {
                    j = 0;
                    k--;

                    if (k == 0)
                        return true;
                }
            }
        }

        return false;
    }

    void Solve(string &s, string &output, string &ans,
               vector<char> &chars, int k) {

        if (output.size() > ans.size() ||
            (output.size() == ans.size() && output > ans)) {
            ans = output;
        }

        if (output.size() == 7)
            return;

        for (char c : chars) {
            output.push_back(c);

            if (check(s, output, k)) {
                Solve(s, output, ans, chars, k);
            }

            output.pop_back();
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s){
            int index = c - 'a';
            freq[index]++;
        }
        vector<char> chars;

        for (int i = 25; i >= 0; i--) {
            if (freq[i] >= k)
                chars.push_back('a' + i);
        }

        string output = "";
        string ans = "";

        Solve(s, output, ans, chars, k);

        return ans;
    }
};