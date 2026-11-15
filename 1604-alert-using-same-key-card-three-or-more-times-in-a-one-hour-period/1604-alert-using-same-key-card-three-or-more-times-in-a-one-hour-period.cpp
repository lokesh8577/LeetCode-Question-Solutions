class Solution {
private:
    int getDiff(string a, string b) {
        int h1 = stoi(a.substr(0, 2));
        int m1 = stoi(a.substr(3, 2));

        int h2 = stoi(b.substr(0, 2));
        int m2 = stoi(b.substr(3, 2));

        return (h1 * 60 + m1) - (h2 * 60 + m2);
    }

    bool Check(vector<string>& time) {
        sort(time.begin(), time.end());

        for (int i = 2; i < time.size(); i++) {
            int diff = getDiff(time[i], time[i - 2]);

            if (diff <= 60) {
                return true;
            }
        }

        return false;
    }

public:
    vector<string> alertNames(vector<string>& keyName,
                              vector<string>& keyTime) {
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < keyName.size(); i++) {
            mp[keyName[i]].push_back(keyTime[i]);
        }

        vector<string> ans;

        for (auto& i : mp) {
            if (Check(i.second)) {
                ans.push_back(i.first);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};