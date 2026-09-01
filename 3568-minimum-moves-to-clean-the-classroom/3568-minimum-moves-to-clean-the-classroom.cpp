class Solution {
public:
    int minMoves(vector<string>& a, int energy) {
        int m = a.size(), n = a[0].size();
        int L = 0, sr, sc;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 'S') sr = i, sc = j;
                if (a[i][j] == 'L') id[i][j] = L++;
            }
        }

        if (L == 0) return 0;

        int masks = 1 << L;

        vector<vector<vector<vector<bool>>>> vis(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(masks)
                )
            )
        );

        queue<array<int, 4>> q;
        q.push({sr, sc, energy, 0});
        vis[sr][sc][energy][0] = true;

        int moves = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, e, mask] = q.front();
                q.pop();

                if (mask == masks - 1) return moves;
                if (e == 0) continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                        a[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nm = mask;

                    if (a[nr][nc] == 'L')
                        nm |= 1 << id[nr][nc];

                    if (a[nr][nc] == 'R')
                        ne = energy;

                    if (vis[nr][nc][ne][nm])
                        continue;

                    vis[nr][nc][ne][nm] = true;
                    q.push({nr, nc, ne, nm});
                }
            }

            moves++;
        }

        return -1;
    }
};