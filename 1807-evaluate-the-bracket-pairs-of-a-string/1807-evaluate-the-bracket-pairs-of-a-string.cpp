class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto i : knowledge) {
            mp[i[0]] = i[1];
        }

        int index = 0;
        string ans = "";
        while (index < s.size()) {
            if (s[index] == '(') {
                index++;
                string temp = "";
                while (index < s.size() && s[index] != ')') {
                    temp += s[index];
                    index++;
                }
                index++;
                auto it = mp.find(temp);
                if (it != mp.end()) {
                    ans += mp[temp];
                } else {
                    ans += "?";
                }
            } else {
                ans += s[index++];
            }
        }
        return ans;
    }
};