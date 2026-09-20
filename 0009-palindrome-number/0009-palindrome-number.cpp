class Solution {
public:
    bool Solve(string s, int start, int end) {
        if (start > end) {
            return true;
        }

        if (s[start] != s[end]) {
            return false;
        }

        return Solve(s, start + 1, end - 1);
    }
    bool isPalindrome(int x) {
        string s = to_string(x);
        return Solve(s, 0, s.size() - 1);
    }
};