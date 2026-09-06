class Solution {
public:
    int Solve(string &s) {
        int temp = 0;

        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1])
                temp++;
        }

        string str = s.substr(1) + s[0];
        s = str;

        return temp;
    }

    int countRotations(string s, int k) {
        unordered_map<int, int> mp;

        for(int i = 0; i < s.size(); i++) {
            int temp = Solve(s);
            mp[temp]++;
        }

        return mp[k];
    }
};