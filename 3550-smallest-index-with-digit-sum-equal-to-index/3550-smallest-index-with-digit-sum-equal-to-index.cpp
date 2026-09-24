class Solution {
    private:
    int Solve(int n){
        int sum = 0;
        while(n > 0){
            int digit = n % 10;
            sum += digit;
            n /= 10;
        }

        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int sumIndex = Solve(nums[i]);
            if(sumIndex == i){
                return i;
            }
        }

        return -1;
    }
};