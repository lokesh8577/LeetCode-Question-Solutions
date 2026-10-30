class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> mp;
        for (int i = 0; i < time.size(); i++) {
            if (time[i] % 60 == 0) {
                mp[0]++;
            } else
                mp[time[i] % 60]++;
        }
        int ans = 0;
        for (int i = 0; i < time.size(); i++) {
            int Find;
            if (time[i] % 60 == 0) {
                Find = 0;
            } else {
                Find = 60 - (time[i] % 60);
            }
            mp[time[i] % 60]--;
            auto it = mp.find(Find);
            if (it != mp.end()) {
                ans += mp[Find];
            }
        }
        return ans;
    }
};