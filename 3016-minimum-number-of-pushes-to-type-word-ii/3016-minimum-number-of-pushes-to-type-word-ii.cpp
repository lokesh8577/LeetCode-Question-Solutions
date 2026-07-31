class Solution {
public:
    int minimumPushes(string word) {
        vector<int> temp(26, 0);
        for (auto ch : word) {
            int index = ch - 'a';
            temp[index]++;
        }

        sort(temp.begin(), temp.end());
        int ans = 0;
        // one time press
        for (int i = 25; i >= 18; i--) {
            ans += temp[i];
        }
        // 2 time press
        for (int i = 17; i >= 10; i--) {
            ans += 2 * temp[i];
        }

        // 3 time press
        for (int i = 9; i >= 2; i--) {
            ans += 3 * temp[i];
        }

        // 4 time press
        for (int i = 1; i >= 0; i--) {
            ans += 4 * temp[i];
        }

        return ans;
    }
};