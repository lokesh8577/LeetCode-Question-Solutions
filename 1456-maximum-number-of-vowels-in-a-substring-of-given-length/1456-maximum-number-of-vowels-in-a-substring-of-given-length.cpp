class Solution {
    bool isVowel(char ch) { // function for checking is the char is vowel or not
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return 1;
        }
        return 0;
    }

public:
    int maxVowels(string s, int k) {
        int maxVowel = 0;
        queue<char> Window;
        int VowelsinWindow = 0;
        for (int i = 0; i < k; i++) { // taking first window of k size
            if (isVowel(s[i])) {
                VowelsinWindow++;
            }
            maxVowel = max(maxVowel, VowelsinWindow);
            Window.push(s[i]);
        }

        for (int i = k; i < s.size(); i++) { // checking all window
            char ch = Window.front();
            if (isVowel(ch)) {
                VowelsinWindow--;
            }
            Window.pop();
            if (isVowel(s[i])) {
                VowelsinWindow++;
            }
            Window.push(s[i]);
            maxVowel = max(maxVowel, VowelsinWindow);
        }
        return maxVowel; // return max vowel in k size window
    }
};