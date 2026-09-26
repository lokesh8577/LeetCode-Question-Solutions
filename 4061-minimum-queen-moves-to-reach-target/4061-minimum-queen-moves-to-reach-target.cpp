class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        if(source[0] == target[0] && source[1] == target[1]){
            return 0;
        }

        else if(source[0] == target[0] || source[1] == target[1] ||abs(target[0] - source[0]) == abs(target[1] - source[1])){
            return 1;
        }


        return 2;
    }
};