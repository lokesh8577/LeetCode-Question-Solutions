class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mini1 = INT_MAX;
        int mini2 = INT_MAX;
        for (auto x : nums) {
            if (mini1 >= x) {
                mini1 = x;
            } else if (mini2 >= x) {
                mini2 = x;
            } else {
                return 1;
            }
        }

        return false;
    }
};