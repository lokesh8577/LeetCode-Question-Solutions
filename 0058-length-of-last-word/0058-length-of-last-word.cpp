class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        bool flag = false;
        for(int i=s.size()-1;i>=0;i--){
            if(flag && s[i] == ' '){
                return len;
            }

            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'){
                flag = true;
            }

            if(flag && s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'){
                len++;
            }
        }

        return len;
    }
};