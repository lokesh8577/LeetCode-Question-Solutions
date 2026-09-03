class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int AND = 0, l = 0, ans = 0;

        for (int r = 0; r < n; ++r) {
            while ((AND & nums[r]) != 0) {
                AND ^= nums[l];
                ++l;
            }
            AND |= nums[r];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};