class Solution {
public:
    int oneDigit(int n) {
        int one = 0;
        while (n > 0) {
            int digit = n % 2;
            if (digit == 1) {
                one++;
            }
            n /= 2;
        }

        return one;
    }
    int calculateScore(int a, int b) {
        int first = oneDigit(a);
        int second = oneDigit(b);

        if (first >= second) {
            return first * second;
        }

        return second / first;
    }
};