class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> Store1;

        for (char ch : t) {
            Store1[ch]++;
        }

        int end = s.size() - 1;
        map<char, int> Store2;
        string ans = "";
        int right = s.size() - 1;

        for (int start = s.size() - 1; start >= 0; start--) {

            if (Store1.count(s[start])) {
                Store2[s[start]]++;
            }

            while (Store1.size() > 0) {
                bool valid = true;

                for (auto it : Store1) {
                    if (Store2[it.first] < it.second) {
                        valid = false;
                        break;
                    }
                }

                if (!valid) break;

                int len = right - start + 1;

                if (ans == "" || len < ans.size()) {
                    ans = s.substr(start, len);
                }

                if (Store1.count(s[right])) {
                    Store2[s[right]]--;
                }

                right--;
            }
        }

        return ans;
    }
};