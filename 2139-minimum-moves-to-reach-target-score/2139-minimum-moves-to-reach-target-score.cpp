class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
        while (target > 1) {
            if (target % 2 == 0) {
                if (maxDoubles > 0) {
                    target /= 2;
                    maxDoubles--;
                } else {
                    moves += target - 1;
                    return moves;
                }
            } else {
                target--;
            }
            moves++;
        }
        return moves;
    }
};