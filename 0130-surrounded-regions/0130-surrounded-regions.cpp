class Solution {
private:
    void dfs(int i, int j, map<pair<int, int>, bool>& visited, bool& flag,
             int m, int n, vector<vector<char>>& board,
             vector<pair<int, int>>& component) {

        visited[{i, j}] = true;
        component.push_back({i, j});

        if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
            flag = false;
        }

        // UP
        if (i - 1 >= 0 && board[i - 1][j] == 'O' && !visited[{i - 1, j}]) {

            dfs(i - 1, j, visited, flag, m, n, board, component);
        }

        // DOWN
        if (i + 1 < m && board[i + 1][j] == 'O' && !visited[{i + 1, j}]) {

            dfs(i + 1, j, visited, flag, m, n, board, component);
        }

        // RIGHT
        if (j + 1 < n && board[i][j + 1] == 'O' && !visited[{i, j + 1}]) {

            dfs(i, j + 1, visited, flag, m, n, board, component);
        }

        // LEFT
        if (j - 1 >= 0 && board[i][j - 1] == 'O' && !visited[{i, j - 1}]) {

            dfs(i, j - 1, visited, flag, m, n, board, component);
        }
    }

public:
    void solve(vector<vector<char>>& board) {

        if (board.empty() || board[0].empty()) {
            return;
        }

        int m = board.size();
        int n = board[0].size();

        map<pair<int, int>, bool> visited;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (!visited[{i, j}] && board[i][j] == 'O') {

                    bool flag = true;
                    vector<pair<int, int>> component;

                    dfs(i, j, visited, flag, m, n, board, component);

                    if (flag) {
                        for (auto cell : component) {
                            board[cell.first][cell.second] = 'X';
                        }
                    }
                }
            }
        }
    }
};