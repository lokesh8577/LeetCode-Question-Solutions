class Solution {
private:
    bool Check(int n, int t) {
        int product = 1;
        while (n > 0) {
            int digit = n % 10;
            product *= digit;
            n /= 10;
        }
        if (product % t == 0) {
            return true;
        }
        return false;
    }

public:
    int smallestNumber(int n, int t) {
        for (int i = n; i <= 100; i++) {
            if (Check(i, t)) {
                return i;
            }
        }
        return -1;
    }
};