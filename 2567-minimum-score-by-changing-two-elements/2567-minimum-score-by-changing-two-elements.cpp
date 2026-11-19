class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return min({abs(nums[nums.size() - 3] - nums[0]),abs(nums[nums.size() - 2] - nums[1]),abs(nums[nums.size() - 1] - nums[2])});
    }
};