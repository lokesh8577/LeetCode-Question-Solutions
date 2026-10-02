class Solution {
private:
    void Solve(vector<string>& ans, string& output, int n, int i, int j) {
        if (i == n && j == n) {
            ans.push_back(output);
            return;
        }
        if (i < n) {
            output.push_back('(');
            Solve(ans, output, n, i + 1, j);
            output.pop_back();
        }

        if (j < i) {
            output.push_back(')');
            Solve(ans, output, n, i, j + 1);
            output.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output;
        Solve(ans, output, n, 0, 0);
        return ans;
    }
};