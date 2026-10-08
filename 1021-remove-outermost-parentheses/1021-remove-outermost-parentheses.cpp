class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (st.empty() && ch == '(') {
                st.push(ch);
            } else {
                if (ch == '(') {
                    st.push(ch);
                    ans += ch;
                } else {
                    if (st.size() == 1) {
                        st.pop();
                    } else {
                        ans += ch;
                        st.pop();
                    }
                }
            }
        }
        return ans;
    }
};