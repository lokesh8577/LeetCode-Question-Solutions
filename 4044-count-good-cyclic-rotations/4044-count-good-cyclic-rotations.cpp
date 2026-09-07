class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        long long left = 0;
        long long right = 0;
        for (int i = 0; i < n / 2; i++) {
            left += nums[i];
            right += nums[n / 2 + i];
        }

        int index = 0;
        int ans = 0;
        while (index < n ) {
            if (left > right) {
                ans++;
            }
            // cout<<left<<" "<<right<<endl;
            left -= nums[index];
            left += nums[(index + (n / 2)) % n];
            right -= nums[(index + (n / 2)) % n];
            right += nums[index];

            index++;
        }
        return ans;
    }
};