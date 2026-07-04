class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x : nums){
            mp[x]++;
        }
        for(int x : nums){
            if(mp[x] == 1 && x % 2 == 0){
                return x;
            }
        }
        return -1;
    }
};