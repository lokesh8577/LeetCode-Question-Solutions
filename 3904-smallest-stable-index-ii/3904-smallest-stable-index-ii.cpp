class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>prefix(nums.size());
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
            prefix[i] = maxi;
        }

        int mini = INT_MAX;
        vector<int>suffix(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            mini = min(mini,nums[i]);
            suffix[i] = mini;
        }

        for(int i=0;i<nums.size();i++){
            if(prefix[i] - suffix[i] <= k){
                return i;
            }

            // cout<<prefix[i] <<" "<<suffix[i]<<endl;
        }
        
        return -1;
    }
};