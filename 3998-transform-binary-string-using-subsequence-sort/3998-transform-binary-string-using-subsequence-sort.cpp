class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        auto temp = make_pair(s, strs);
        int z = count(s.begin(), s.end(), '0');
        vector<bool> ans;
        for (auto t : strs) {
            int fz = count(t.begin(), t.end(), '0');
            int q = count(t.begin(), t.end(), '?');

            int need = z - fz;
            if (need < 0 || need > q) {
                ans.push_back(false);
                continue;
            }

            int ps = 0, pt = 0;
            bool ok = true;

            for (int i = 0; i < s.size(); i++) {
                ps += s[i] == '0';

                if (t[i] == '0')
                    pt++;
                else if (t[i] == '?') {
                    if (need > 0) {
                        pt++;
                        need--;
                    }
                }

                if (pt < ps) {
                    ok = false;
                    break;
                }
            }
            ans.push_back(ok && need == 0);
        }
        return ans;
    }
};