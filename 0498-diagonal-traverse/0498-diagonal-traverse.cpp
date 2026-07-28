class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int count = 0;
        int total = m * n;
        int i = 0, j = 0;

        vector<int> ans;

        while (count < total) {

            // Up-Right
            while (i >= 0 && j < n) {
                ans.push_back(mat[i][j]);
                count++;
                i--;
                j++;
            }

            if (j == n) {
                i += 2;
                j--;
            } else {
                i = 0;
            }

            if (count >= total)
                break;

            // Down-Left
            while (i < m && j >= 0) {
                ans.push_back(mat[i][j]);
                count++;
                i++;
                j--;
            }

            if (i == m) {
                i--;
                j += 2;
            } else {
                j = 0;
            }
        }

        return ans;
    }
};