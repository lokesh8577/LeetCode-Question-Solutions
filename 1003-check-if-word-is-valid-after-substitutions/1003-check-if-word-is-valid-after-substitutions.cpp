class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char first = ' ';
        char second = ' ';
        for (auto ch : s) {
            if (ch == 'c' && first == 'a' && second == 'b') {
                st.pop();
                st.pop();
                if (st.empty()) {
                    first = ' ';
                    second = ' ';
                } else if (st.size() == 1) {
                    first = st.top();
                    second = ' ';
                } else {
                    second = st.top();
                    st.pop();
                    first = st.top();
                    st.push(second);
                }
            } else {
                st.push(ch);
                if (first == ' ' || second == ' ') {
                    if (first == ' ') {
                        first = ch;
                    } else if (second == ' ') {
                        second = ch;
                    }
                } else {
                    char temp = second;
                    second = ch;
                    first = temp;
                }
            }
        }

        return st.empty();
    }
};