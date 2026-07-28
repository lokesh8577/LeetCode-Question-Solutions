class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int total = nums[0];
        int maxi = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            total = max(total + nums[i], nums[i]);
            maxi = max(maxi, total);
        }

        return maxi;
    }
};