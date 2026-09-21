class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int x = __gcd(nums[i], k);
            int need = k / x;
            for (auto it : mp) {
                if (it.first % need == 0) {
                    ans += it.second;
                }
            }
            mp[x]++;
        }

        return ans;
    }
};