class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        unordered_map<int, int> ZeroRow,OneRow,ZeroCol,OneCol;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    ZeroRow[i]++;
                    ZeroCol[j]++;
                } else {
                    OneRow[i]++;
                    OneCol[j]++;
                }
            }
        }

        vector<vector<int>> diff(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                diff[i][j] = OneRow[i] + OneCol[j] - ZeroRow[i] - ZeroCol[j];
            }
        }

        return diff;
    }
};