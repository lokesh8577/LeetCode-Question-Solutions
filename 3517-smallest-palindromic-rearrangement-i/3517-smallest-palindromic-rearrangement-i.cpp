class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string use = s.substr(0, n / 2);
        sort(use.begin(), use.end());
        string use_rev = use;
        reverse(use_rev.begin(), use_rev.end());
        if (n % 2 == 0) {
            use += use_rev;
        } else {
            char a = s[n / 2];
            use = use + a + use_rev;
        }
        return use;
    }
};