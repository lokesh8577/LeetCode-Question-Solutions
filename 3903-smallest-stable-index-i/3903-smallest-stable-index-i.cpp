class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int index = -1;
        for (int i = 0; i < nums.size(); i++) {
            int maxi = INT_MIN;
            int mini = INT_MAX;
            for(int j=0;j<=i;j++){
                maxi = max(maxi,nums[j]);
            }
            for(int j=i;j<nums.size();j++){
                mini = min(mini,nums[j]);
            }

            int value = maxi - mini;
            if(value <= k){
                index = i;
                break;
            }
        }
        return index;
    }
};