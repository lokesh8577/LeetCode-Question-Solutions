class Solution {
private:
    void Solve(string s, int index, string& temp, vector<string>& ans) {
        if (index == s.size()) {
            ans.push_back(temp);
            return;
        }

        if (isalpha(s[index])) {
            temp += tolower(s[index]);
            Solve(s, index + 1, temp, ans);
            temp.pop_back();

            temp += toupper(s[index]);
            Solve(s, index + 1, temp, ans);
            temp.pop_back();
        } else {
            temp += s[index];
            Solve(s, index + 1, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string temp = "";
        int index = 0;
        Solve(s, index, temp, ans);
        return ans;
    }
};