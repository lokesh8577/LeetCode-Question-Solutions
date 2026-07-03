class Solution {
private:
    bool Check(vector<vector<int>> visited) {
        for (auto i : visited) {
            for (auto j : i) {
                if (j == 0) {
                    return false;
                }
            }
        }
        return true;
    }
    void Solve(vector<vector<int>>& grid, int x, int y, int endX, int endY,
               int& ans, vector<vector<int>>& visited) {
        if (x == endX && y == endY) {
            visited[x][y] = 1;

            if (Check(visited)) {
                ans++;
            }

            visited[x][y] = 0;
            return;
        }
        // up side
        if (x - 1 >= 0 && visited[x - 1][y] != 1 && visited[x - 1][y] != -1) {
            visited[x][y] = 1;
            Solve(grid, x - 1, y, endX, endY, ans, visited);
            visited[x][y] = 0;
        }
        // down side
        if (x + 1 < grid.size() && visited[x + 1][y] != 1 &&
            visited[x + 1][y] != -1) {
            visited[x][y] = 1;
            Solve(grid, x + 1, y, endX, endY, ans, visited);
            visited[x][y] = 0;
        }

        // left side
        if (y - 1 >= 0 && visited[x][y - 1] != 1 && visited[x][y - 1] != -1) {
            visited[x][y] = 1;
            Solve(grid, x, y - 1, endX, endY, ans, visited);
            visited[x][y] = 0;
        }
        // right side
        if (y + 1 < grid[0].size() && visited[x][y + 1] != 1 &&
            visited[x][y + 1] != -1) {
            visited[x][y] = 1;
            Solve(grid, x, y + 1, endX, endY, ans, visited);
            visited[x][y] = 0;
        }
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX = 0, startY = 0, endX = 0, endY = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
                if (grid[i][j] == 2) {
                    endX = i;
                    endY = j;
                }
                if (grid[i][j] == -1) {
                    visited[i][j] = -1;
                }
            }
        }
        int ans = 0;
        Solve(grid, startX, startY, endX, endY, ans, visited);
        return ans;
    }
};