class Solution {
public:
    int Solve(int n, vector<int>& nums) {
        if (n == 0) {
            return nums[0];
        }
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for (int i = 2; i <= n; i++) {
            int include = prev2 + nums[i];
            int exclude = prev1;

            int curr = max(include, exclude);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        if(n == 2){
            return max(nums[0],nums[1]);
        }
        vector<int>first,second;
        for(int i=0;i<nums.size();i++){
            if(i != 0){
                first.push_back(nums[i]);
            }

            if(i != nums.size()-1){
                second.push_back(nums[i]);
            }
        }

        n = first.size()-1;
        return max(Solve(n,first),Solve(n,second));
    }
};