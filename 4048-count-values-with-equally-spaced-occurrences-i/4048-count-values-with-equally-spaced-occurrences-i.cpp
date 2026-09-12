class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = 0;
        for (auto& it : mp) {
            if (it.second.size() == 3) {
                auto temp = it.second;
                if (temp[1] - temp[0] == temp[2] - temp[1]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};