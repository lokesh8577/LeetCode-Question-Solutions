class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> mp;
            int sq = 0;
            for (int j = i; j < nums.size(); j++) {
                mp[nums[j]]++;
                sq += mp.size() * mp.size();
            }
            ans += sq;
        }

        return ans;
    }
};