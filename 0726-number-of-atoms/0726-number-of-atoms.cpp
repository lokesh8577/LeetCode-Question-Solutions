class Solution {
private:
    bool isUpper(char ch) { return ch >= 'A' && ch <= 'Z'; }

    bool isLower(char ch) { return ch >= 'a' && ch <= 'z'; }

    bool isDigit(char ch) { return ch >= '0' && ch <= '9'; }

public:
    string countOfAtoms(string formula) {
        stack<pair<string, int>> st;
        int index = 0;
        while (index < formula.size()) {
            if (formula[index] == '(') {
                st.push({"(", 0});
                index++;
            } else if (formula[index] == ')') {
                index++;
                int number = 0;
                while (index < formula.size() && isDigit(formula[index])) {
                    number = number * 10 + (formula[index] - '0');
                    index++;
                }
                if (number == 0)
                    number = 1;

                stack<pair<string, int>> temp;
                while (!st.empty() && st.top().first != "(") {
                    auto p = st.top();
                    st.pop();

                    p.second *= number;

                    temp.push(p);
                }
                st.pop();

                while (!temp.empty()) {
                    st.push(temp.top());
                    temp.pop();
                }
            }

            else {
                string atom = "";
                atom += formula[index];
                index++;

                while (index < formula.size() && isLower(formula[index])) {
                    atom += formula[index];
                    index++;
                }

                int number = 0;
                while (index < formula.size() && isDigit(formula[index])) {
                    number = number * 10 + (formula[index] - '0');
                    index++;
                }

                if (number == 0)
                    number = 1;

                st.push({atom, number});
            }
        }

        map<string, int> mp;
        while (!st.empty()) {
            auto p = st.top();
            st.pop();

            mp[p.first] += p.second;
        }

        string ans = "";
        for (auto& it : mp) {
            ans += it.first;
            if (it.second > 1) {
                ans += to_string(it.second);
            }
        }
        return ans;
    }
};