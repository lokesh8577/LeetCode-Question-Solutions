class Solution {
private:
    void Solve(int x, vector<int>& arr) {
        string str = to_string(x);
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (char ch : str) {
            int digit = ch - '0';
            if (maxi < digit) {
                maxi = digit;
            }
            if (mini > digit) {
                mini = digit;
            }
        }
        int index = maxi - mini;
        arr[index] += x;
    }

public:
    int maxDigitRange(vector<int>& nums) {
        vector<int> Store(10, 0);
        for (auto x : nums) {
            Solve(x, Store);
        }
        for (int i = 9; i >= 0; i--) {
            if (Store[i] != 0) {
                return Store[i];
            }
        }
        return 0;
    }
};