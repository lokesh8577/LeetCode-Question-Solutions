class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> mp;
        vector<bool> Check(26, false);

        for (char c : s) {
            mp[c]++;
        }

        string ans;

        for (char c : s) {
            while (!Check[c - 'a'] &&
                   !ans.empty() &&
                   ans.back() > c &&
                   mp[ans.back()] > 0) {
                Check[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            mp[c]--;

            if (!Check[c - 'a']) {
                Check[c - 'a'] = true;
                ans.push_back(c);
            }
        }

        return ans;
    }
};