class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int Sum = 0;
        for(auto x : nums){
            Sum += x;
        }
        int leftSum = 0;
        int index = -1;
        for(auto x : nums){
            Sum -= x;
            if(leftSum == Sum){
                return index+1;
            }
            leftSum += x;
            index++;
        }
        return -1;
    }
};