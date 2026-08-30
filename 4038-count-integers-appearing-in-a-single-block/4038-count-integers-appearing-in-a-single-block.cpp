class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<int> v(101, 0);

        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] != nums[i - 1])
                v[nums[i]]++;
        }

        int count = 0;

        for (int x : v) {
            if (x == 1)
                count++;
        }

        return count;
    }
};