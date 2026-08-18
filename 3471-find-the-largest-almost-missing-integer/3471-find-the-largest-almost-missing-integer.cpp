class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> freq(51,0);
        for(int x:nums){
            freq[x]++;
        }
        int ans=-1;
        int n=nums.size();
        if(k>=2&&k<n){
            if(freq[nums[0]]==1) ans=nums[0];
            if(freq[nums[n-1]]==1) ans=max(ans,nums[n-1]);
            if(ans==-1) return -1;
        }else{
            for(int i=0;i<51;i++){
                if(freq[i]<=k && freq[i]>=1) ans=max(ans,i);
            }
        }
        return ans;
    }
};