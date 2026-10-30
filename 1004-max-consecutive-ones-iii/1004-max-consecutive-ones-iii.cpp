class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int ans = 0;
        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] == 0) {
                if (k > 0) {
                    k--;
                } else {
                    while (k == 0) {
                        if (nums[start] == 0) {
                            k++;
                        }
                        start++;
                    }
                    k--;
                }
            }

            ans = max(ans, end - start + 1);
        }

        return ans;
    }
};