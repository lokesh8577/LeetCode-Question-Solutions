class Solution {
public:
    int minSwaps(string s) {
        int totalOpen = s.size() / 2;
        int open = 0;
        int close = 0;
        int ans = 0;
        for (auto ch : s) {
            if (ch == ']') {
                if (totalOpen == 0) {
                    return ans;
                }
                if (close >= open) {
                    ans++;
                    open++;
                    totalOpen--;
                } else {
                    close++;
                }
            } else {
                open++;
            }
        }

        return ans;
    }
};