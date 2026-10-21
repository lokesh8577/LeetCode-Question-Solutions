class Solution {
private:
    bool check(string s) {
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }

public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            string temp = "";
            for (int j = i; j < s.size(); j++) {
                temp += s[j];
                if (check(temp)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};