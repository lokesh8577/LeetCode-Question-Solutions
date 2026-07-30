class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == ')') {
                string temp = "";

                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }

                st.pop();
                for (char c : temp) {
                    st.push(c);
                }
            } else {
                st.push(ch);
            }
        }
        string ans(st.size(), '#');
        int index = st.size() - 1;
        while (!st.empty()) {
            ans[index--] = st.top();
            st.pop();
        }
        return ans;
    }
};