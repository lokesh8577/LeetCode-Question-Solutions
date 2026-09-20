class Solution {
public:
    int reverse(int x) {
        long long n = x;
        long long reverseInt = 0;

        while (n != 0) {
            int digit = n % 10;
            reverseInt = reverseInt * 10 + digit;
            n /= 10;
        }

        if (reverseInt > INT_MAX || reverseInt < INT_MIN) {
            return 0;
        }

        return (int)reverseInt;
    }
};