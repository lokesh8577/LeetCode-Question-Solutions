class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0;
        int ans = INT_MIN;
        mp[0] = -1;
        for (auto i = 0; i < nums.size(); i++) {
            sum = (nums[i] == 1) ? sum + 1 : sum - 1;
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            } else {
                ans = max(ans, i - mp[sum]);
            }
        }

        return (ans == INT_MIN) ? 0 : ans;
    }
};