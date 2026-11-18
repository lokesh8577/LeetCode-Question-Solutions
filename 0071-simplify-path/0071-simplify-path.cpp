class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int index = 0;

        while (index < path.size()) {

            while (index < path.size() && path[index] == '/') {
                index++;
            }

            string temp = "";

            while (index < path.size() && path[index] != '/') {
                temp += path[index];
                index++;
            }
            if (temp == "" || temp == ".") {
                continue;
            }

            if (temp == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(temp);
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};
