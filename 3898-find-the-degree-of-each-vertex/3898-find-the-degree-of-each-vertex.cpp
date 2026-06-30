class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    mp[i]++;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};