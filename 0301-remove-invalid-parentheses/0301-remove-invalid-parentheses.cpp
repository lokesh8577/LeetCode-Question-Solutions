// class Solution {
//     bool isValid(string& s) {
//         int cnt = 0;
//         for (char ch : s) {
//             if (ch == '(')
//                 cnt++;
//             else if (ch == ')') {
//                 if (cnt == 0)
//                     return false;
//                 cnt--;
//             }
//         }
//         return cnt == 0;
//     }

//     void Solve(string s, int index, int count,
//                unordered_map<int, unordered_set<string>>& mp) {

//         if (index == s.size()) {
//             if (isValid(s))
//                 mp[count].insert(s);
//             return;
//         }

//         if (s[index] != '(' && s[index] != ')') {
//             Solve(s, index + 1, count, mp);
//             return;
//         }

//         Solve(s, index + 1, count, mp);

//         string t = s;
//         t.erase(index, 1);
//         Solve(t, index, count + 1, mp);
//     }

// public:
//     vector<string> removeInvalidParentheses(string s) {

//         unordered_map<int, unordered_set<string>> mp;

//         Solve(s, 0, 0, mp);

//         int mini = INT_MAX;

//         for (auto& x : mp)
//             mini = min(mini, x.first);

//         vector<string> ans;

//         if (mini == INT_MAX)
//             return {""};

//         for (auto& str : mp[mini])
//             ans.push_back(str);

//         return ans;
//     }
// };

class Solution {
    unordered_set<string> ans;

    void dfs(string &s, int index, int leftRemove, int rightRemove, int open, string &path) {
        if (index == s.size()) {
            if (leftRemove == 0 && rightRemove == 0 && open == 0)
                ans.insert(path);
            return;
        }

        char ch = s[index];

        if (ch == '(') {
            if (leftRemove > 0)
                dfs(s, index + 1, leftRemove - 1, rightRemove, open, path);

            path.push_back(ch);
            dfs(s, index + 1, leftRemove, rightRemove, open + 1, path);
            path.pop_back();
        }
        else if (ch == ')') {
            if (rightRemove > 0)
                dfs(s, index + 1, leftRemove, rightRemove - 1, open, path);

            if (open > 0) {
                path.push_back(ch);
                dfs(s, index + 1, leftRemove, rightRemove, open - 1, path);
                path.pop_back();
            }
        }
        else {
            path.push_back(ch);
            dfs(s, index + 1, leftRemove, rightRemove, open, path);
            path.pop_back();
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int leftRemove = 0, rightRemove = 0;

        for (char ch : s) {
            if (ch == '(')
                leftRemove++;
            else if (ch == ')') {
                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        string path;
        dfs(s, 0, leftRemove, rightRemove, 0, path);

        return vector<string>(ans.begin(), ans.end());
    }
};