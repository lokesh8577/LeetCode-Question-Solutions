class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int index;
        if (n % 2 == 0) {
            index = (n + 1) / 2;
        } else {
            index = n / 2;
        }

        int val = nums[index];
        int ans = 0;
        for (int i = 0; i < index; i++) {
            ans += val - nums[i];
        }

        for (int i = index + 1; i < n; i++) {
            ans += nums[i] - val;
        }

        return ans;
    }
};