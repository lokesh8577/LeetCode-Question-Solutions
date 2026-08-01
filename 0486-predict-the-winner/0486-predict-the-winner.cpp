class Solution {
public:
    bool dfs(int i,int j,int p1,int p2,bool turn ,vector<int>&nums)
    {
        if(i>j) return p1>=p2;
        if(turn){
            return dfs(i+1,j,p1+nums[i],p2,false,nums) || dfs(i,j-1,p1+nums[j],p2,false,nums);
        }
        else{
            return dfs(i+1,j,p1,p2+nums[i],true,nums) and dfs(i,j-1,p1,p2+nums[j],true,nums);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        return dfs(0,nums.size()-1,0,0,true,nums);
    }
};