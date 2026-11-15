class Solution {
public:
    int countConsistent(vector<int>& nums) {
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int andVal = nums[i];
            int mini = nums[i];

            for (int j = i; j < nums.size(); j++) {
                andVal &= nums[j];
                mini = min(mini, nums[j]);

                if (andVal == mini) {
                    ans++;
                }
            }
        }
        return ans;
    }
};