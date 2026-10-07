class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;

        for (int cnt = 1; cnt < num; cnt++) {
            if (num % cnt == 0) {
                sum += cnt;
            }
        }

        return sum == num;
    }
};