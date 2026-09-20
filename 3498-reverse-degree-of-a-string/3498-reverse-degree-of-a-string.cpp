class Solution {
public:
    int reverseDegree(string s) {
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int index = (26 - (s[i] - 'a'));
            ans += (i + 1) * index;
        }
        return ans;
    }
};