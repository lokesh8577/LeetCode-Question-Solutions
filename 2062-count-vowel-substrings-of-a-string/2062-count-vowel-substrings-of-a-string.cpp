class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int mask = 0;

            for (int j = i; j < n; j++) {
                char ch = word[j];

                if (ch != 'a' && ch != 'e' && ch != 'i' &&
                    ch != 'o' && ch != 'u') {
                    break;
                }

                if (ch == 'a') mask |= 1;
                if (ch == 'e') mask |= 2;
                if (ch == 'i') mask |= 4;
                if (ch == 'o') mask |= 8;
                if (ch == 'u') mask |= 16;

                if (mask == 31) {
                    ans++;
                }
            }
        }

        return ans;
    }
};