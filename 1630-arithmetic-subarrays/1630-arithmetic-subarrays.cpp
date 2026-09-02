class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        for(int i=0;i<l.size();i++){
            int start = l[i];
            int end = r[i];
            vector<int> temp(nums.begin() + start, nums.begin() + end + 1);

            sort(temp.begin(), temp.end());

            int diff = temp[1] - temp[0];
            bool flag = true;

            for(int j = 2; j < temp.size(); j++) {
                if(temp[j] - temp[j-1] != diff) {
                    flag = false;
                    break;
                }
            }

            ans.push_back(flag);
    }

        return ans;
    }
};