class Solution {
private:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void Solve(string& s, int index, vector<string>& output,
               vector<vector<string>>& ans) {
        if (index == s.size()) {
            ans.push_back(output);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            string slice = s.substr(index, i - index + 1);
            if (isPalindrome(slice)) {
                output.push_back(slice);
                Solve(s, i + 1, output, ans);
                output.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        int index = 0;
        Solve(s, index, temp, ans);
        return ans;
    }
};