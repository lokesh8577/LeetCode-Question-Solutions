class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi)maxi=nums[i];
            if(nums[i]<mini)mini=nums[i];
        }
        return __gcd(maxi, mini);
    }
};