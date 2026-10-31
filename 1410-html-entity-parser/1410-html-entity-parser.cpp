class Solution {
private:
    string Check(string test) {
        if (test == "&quot;") {
            return "\"";
        } else if (test == "&apos;") {
            return "'";
        } else if (test == "&amp;") {
            return "&";
        } else if (test == "&gt;") {
            return ">";
        } else if (test == "&lt;") {
            return "<";
        } else if (test == "&frasl;") {
            return "/";
        } else {
            return test;
        }
    }

public:
    string entityParser(string text) {
        string ans = "";
        int index = 0;
        while (index < text.size()) {
            if (text[index] == '&') {
                string temp = "";
                while (index < text.size()) {
                    if (temp.size() != 0 && text[index] == '&') {
                        index--;
                        break;
                    }
                    temp += text[index];

                    if (text[index] == ';') {
                        break;
                    }

                    index++;
                }
                ans += Check(temp);
            } else {
                ans += text[index];
            }

            index++;
        }

        return ans;
    }
};