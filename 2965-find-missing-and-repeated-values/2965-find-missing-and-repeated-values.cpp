class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> Hash(grid.size() * grid[0].size() + 1, 0);
        for (auto i : grid) {
            for (auto j : i) {
                Hash[j]++;
            }
        }
        int first;
        int second;
        for (int i = 1; i < Hash.size(); i++) {
            if (Hash[i] == 0) {
                second = i;
            }
            if (Hash[i] == 2) {
                first = i;
            }
        }
        return {first, second};
    }
};