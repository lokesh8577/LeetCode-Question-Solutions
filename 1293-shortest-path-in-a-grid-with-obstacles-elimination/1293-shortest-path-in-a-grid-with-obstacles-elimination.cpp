//DFS Solution But it give TLE
// class Solution {
// public:
//     int ans = INT_MAX;

//     void Solve(int i, int j, int cnt, vector<vector<int>>& grid, int k,
//                vector<vector<bool>>& visited) {

//         if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
//             return;
//         }

//         if (i == grid.size() - 1 && j == grid[0].size() - 1) {
//             ans = min(ans, cnt);
//             return;
//         }

//         visited[i][j] = true;

//         // Up side
//         if (i - 1 >= 0 && !visited[i - 1][j]) {
//             if (grid[i - 1][j] == 1 && k > 0) {
//                 Solve(i - 1, j, cnt + 1, grid, k - 1, visited);
//             } else if (grid[i - 1][j] == 0) {
//                 Solve(i - 1, j, cnt + 1, grid, k, visited);
//             }
//         }

//         // Down side
//         if (i + 1 < grid.size() && !visited[i + 1][j]) {
//             if (grid[i + 1][j] == 1 && k > 0) {
//                 Solve(i + 1, j, cnt + 1, grid, k - 1, visited);
//             } else if (grid[i + 1][j] == 0) {
//                 Solve(i + 1, j, cnt + 1, grid, k, visited);
//             }
//         }

//         // Left side
//         if (j - 1 >= 0 && !visited[i][j - 1]) {
//             if (grid[i][j - 1] == 1 && k > 0) {
//                 Solve(i, j - 1, cnt + 1, grid, k - 1, visited);
//             } else if (grid[i][j - 1] == 0) {
//                 Solve(i, j - 1, cnt + 1, grid, k, visited);
//             }
//         }

//         // Right side
//         if (j + 1 < grid[0].size() && !visited[i][j + 1]) {
//             if (grid[i][j + 1] == 1 && k > 0) {
//                 Solve(i, j + 1, cnt + 1, grid, k - 1, visited);
//             } else if (grid[i][j + 1] == 0) {
//                 Solve(i, j + 1, cnt + 1, grid, k, visited);
//             }
//         }

//         visited[i][j] = false;
//     }

//     int shortestPath(vector<vector<int>>& grid, int k) {
//         int m = grid.size();
//         int n = grid[0].size();

//         ans = INT_MAX;

//         vector<vector<bool>> visited(m, vector<bool>(n, false));

//         Solve(0, 0, 0, grid, k, visited);

//         return (ans == INT_MAX) ? -1 : ans;
//     }
// };



class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();

        queue<vector<int>> q;
        q.push({0, k, 0, 0});

        vector<vector<int>> visited(row, vector<int>(col, -1));

        visited[0][0] = k;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            int steps = top[0];
            int cellK = top[1];
            int i = top[2];
            int j = top[3];

            if (i == row - 1 && j == col - 1) 
               return steps;

            int dr[] = {0, 0, 1, -1};
            int dc[] = {1, -1, 0, 0};

            for (int k = 0; k < 4; k++) {
                int r = i + dr[k];
                int c = j + dc[k];

                if (r >= 0 && c >= 0 && c < col && r < row) {
                    int newK = cellK - grid[r][c];

                    if (newK > visited[r][c]) {
                        visited[r][c] = newK;
                        q.push({steps + 1, newK, r, c});
                    }
                }
            }
        }

        return -1;
    }
};