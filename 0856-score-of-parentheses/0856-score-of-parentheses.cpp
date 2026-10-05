class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<char>st;
        for(char ch : s){
            if(ch == '('){
                st.push(score);
                score = 0;
            }
            else{
                score += st.top() + max(score,1);
                st.pop();
            }
        }
        return score;
    }
};