class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        unordered_map<int,int>mp;
        int start = 0;
        int end = 0;
        while(end < nums.size()){
            if(mp[nums[end]] < k){
                mp[nums[end]]++;
                end++;
                maxi = max(maxi,abs(end-start));
            }else{
                mp[nums[start]]--;
                start++;
            }
        }
        return maxi;
    }
};