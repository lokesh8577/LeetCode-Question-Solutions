class Solution {
public:
    string compressedString(string word) {
        int index = 0;
        string ans = "";
        while (index < word.size()) {
            int cnt = 1;
            char ch = word[index++];
            while (word[index] == ch) {
                index++;
                cnt++;
                if (cnt >= 9) {
                    break;
                }
            }

            ans += to_string(cnt) + ch;
        }

        return ans;
    }
};