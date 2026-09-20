class Solution {
public:
    bool Check(char ch, stack<char> st) {
        if(st.empty()){
            return false;
        }
        if (ch == ')') {
            if (st.top() == '(')
                return true;
        } else if (ch == ']') {
            if (st.top() == '[')
                return true;

        } else if (ch == '}') {
            if (st.top() == '{')
                return true;
        }

        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for (auto ch : s) {
            if (!st.empty() && ch == ')' || ch == ']' || ch == '}') {
                if (Check(ch, st)) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(ch);
            }
        }

        return st.empty();
    }
};