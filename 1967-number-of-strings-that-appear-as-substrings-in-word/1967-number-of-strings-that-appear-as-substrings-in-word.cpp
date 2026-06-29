class Solution {
private:
    bool Check(string s, string word) {
        if (word.find(s) != string::npos) {
            return true;
        }
        return false;
    }

public:
    int numOfStrings(vector<string>& patterns, string word) {
        int number = 0;
        for (auto S : patterns) {
            if (Check(S, word)) {
                number++;
            }
        }
        return number;
    }
};