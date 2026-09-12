class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = 0;
        for (auto& it : mp) {
            if (it.second.size() >= 3) {
                bool flag = false;
                auto temp = it.second;
                int diff = temp[1] - temp[0];
                for (int i = 2; i < temp.size(); i++) {
                    if (temp[i] - temp[i - 1] != diff) {
                        flag = true;
                        break;
                    }
                }

                if (!flag) {
                    ans++;
                }
            }
        }
        return ans;
    }
};