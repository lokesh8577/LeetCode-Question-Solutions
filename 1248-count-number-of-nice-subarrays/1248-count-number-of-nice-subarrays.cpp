class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int start = 0, ans = 0, odd = 0;

        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] % 2) odd++;

            while (odd > k) {
                if (nums[start] % 2) odd--;
                start++;
            }

            ans += end - start + 1;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};