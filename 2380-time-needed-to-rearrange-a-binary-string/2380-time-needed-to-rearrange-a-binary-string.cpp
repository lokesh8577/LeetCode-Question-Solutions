
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int time = 0;

        while (true) {
            bool check = false;

            for (int i = 1; i < s.size(); i++) {
                if (s[i - 1] == '0' && s[i] == '1') {
                    s[i - 1] = '1';
                    s[i] = '0';
                    check = true;
                    i++;
                }
            }

            if (!check) {
                return time;
            }

            time++;
        }

        return time;
    }
};
