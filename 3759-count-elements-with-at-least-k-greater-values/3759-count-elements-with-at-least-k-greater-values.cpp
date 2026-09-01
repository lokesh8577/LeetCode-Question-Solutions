class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int i = 0;
        int ans = 0;
        while (i < nums.size()) {
            int j = i;
            while (j < nums.size() && nums[i] == nums[j])
                j++;
            if ((nums.size() - j) >= k) {
                ans += (j - i);
            }
            i = j;
        }

        return ans;
    }
};