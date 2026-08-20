class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        res[0] = nums[0];

        res[n - 1] = nums[1];

        int i = 0; 
        int j = n - 1; 

        for (int k = 2; k < n; k++)
        {
            if (res[i] > res[j])
            {
                i++;
                res[i] = nums[k];
            }
            else
            {
                j--;
                res[j] = nums[k];
            }
        }
        reverse(res.begin() + j, res.end());

        return res;
    }
};