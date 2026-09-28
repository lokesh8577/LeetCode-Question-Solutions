class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0;
        stack<int> st;
        int count = 0;
        for (char ch : s) {
            if (ch == '(') {
                st.push(ch);
                count++;
                max_depth = max(count, max_depth);
                
            } else if (ch == ')') {
                count--;
                st.pop();
            }
        }
        return max_depth;
    }
};