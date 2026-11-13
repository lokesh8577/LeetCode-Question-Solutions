class Solution {
private:
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return 1;
        }
        return 0;
    }

public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> Store(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            string temp = words[i];
            char first = temp[0];
            char last = temp[temp.size() - 1];
            if (isVowel(first) && isVowel(last)) {
                cnt++;
            }

            Store[i] = cnt;
        }

        vector<int> ans;

        // for(auto i : Store){
        //     cout<<i<<" ";
        // }
        for (auto i : queries) {
            int start = i[0];
            int end = i[1];
            int cnt;
            if (start == 0) {
                cnt = Store[end];
            } else {
                cnt = Store[end] - Store[start - 1];
            }

            ans.push_back(cnt);
        }
        return ans;
    }
};