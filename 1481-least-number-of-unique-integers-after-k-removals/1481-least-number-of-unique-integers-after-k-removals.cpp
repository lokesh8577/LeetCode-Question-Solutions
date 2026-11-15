class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> mp;
        for (auto i : arr) {
            mp[i]++;
        }

        vector<pair<int, int>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(),
             [](auto& a, auto& b) { return a.second < b.second; });

        bool flag = true;
        int index = 0;
        while (flag) {
            if (index < v.size() && v[index].second <= k) {
                // cout<<v[index].first<<" ";
                mp.erase(v[index].first);
                k -= v[index].second;
                index++;
            } else {
                flag = false;
            }
        }
        return mp.size();
    }
};