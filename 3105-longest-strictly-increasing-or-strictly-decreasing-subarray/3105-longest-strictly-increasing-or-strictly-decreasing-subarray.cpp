class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incMax = 1;
        // strictly increasing
        for (int i = 0; i < nums.size(); i++) {
            int cnt = 1;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j-1] < nums[j]) {
                    cnt++;
                } else {
                    break;
                }
                incMax = max(incMax, cnt);
            }
        }

        // strictly decreasing
        int decMax = 1;
        for (int i = 0; i < nums.size(); i++) {
            int cnt = 1;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j-1] > nums[j]) {
                    cnt++;
                } else {
                    break;
                }
                decMax = max(decMax, cnt);
            }
        }

        return max(decMax, incMax);
    }
};