class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int val = 1;
            bool flag = true;
            for (int j = i; j < nums.size(); j++) {
                val = val * nums[j];
                if (val < k) {
                    ans++;
                } else {
                    flag = false;
                }

                if (!flag) {
                    break;
                }
            }
        }
        return ans;
    }
};