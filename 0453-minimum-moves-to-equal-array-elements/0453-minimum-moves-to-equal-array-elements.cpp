class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0, m = INT_MAX;
        for (int n : nums)
            m = min(m, n);
        for (int n : nums)
            ans += n - m;
        return ans;
    }
};