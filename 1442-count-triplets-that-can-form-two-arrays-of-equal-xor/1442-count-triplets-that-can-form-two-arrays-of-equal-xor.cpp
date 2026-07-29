class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, pair<int, int>> mp;
        mp[0] = {1, 0};

        int x = 0;
        int ans = 0;
        for (auto i = 0; i < arr.size(); i++) {
            x ^= arr[i];
            if (mp.find(x) != mp.end()) {
                int cnt = mp[x].first, sum = mp[x].second;
                ans += i * cnt - sum;
            }
            mp[x].first++;
            mp[x].second += i + 1;
        }
        return ans;
    }
};