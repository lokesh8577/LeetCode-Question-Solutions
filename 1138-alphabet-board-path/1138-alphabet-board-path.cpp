class Solution {
public:
    string alphabetBoardPath(string target) {
        string ans = "";
        int i = 0, j = 0;

        for (char ch : target) {
            int r = (ch - 'a') / 5;
            int c = (ch - 'a') % 5;

            while (i > r) {
                ans += 'U';
                i--;
            }

            while (j > c) {
                ans += 'L';
                j--;
            }

            while (i < r) {
                ans += 'D';
                i++;
            }

            while (j < c) {
                ans += 'R';
                j++;
            }

            ans += '!';
        }

        return ans;
    }
};