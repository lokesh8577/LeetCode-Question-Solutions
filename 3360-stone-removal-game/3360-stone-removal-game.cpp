class Solution {
public:
    bool canAliceWin(int n) {
        bool winner = false;
        int number = 10;
        while (n > 0) {
            if (n - number < 0) {
                break;
            }

            n = n - number;
            number--;
            winner = !winner;
        }

        return winner;
    }
};