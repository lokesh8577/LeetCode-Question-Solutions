class Solution {
    private:
    int Convert(int val1,int val2){
        string number = to_string(val1) + to_string(val2);
        // cout<<number<<endl;
        int num = 0;
        for(auto i : number){
            int digit = i - '0';
            num = num * 10 + digit;
            // cout<<num<<" ";
        }
        // cout<<endl;

        return num;
    }
public:
    int minMergedInteger(vector<int>& nums) {
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i+=2){
            int val1 = nums[i];
            int val2 = nums[i+1];
            ans = min(ans,Convert(val1,val2));
        }

        return ans;
    }
};