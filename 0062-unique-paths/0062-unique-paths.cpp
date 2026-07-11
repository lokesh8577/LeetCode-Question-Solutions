class Solution {
    // private:
    //     void Solve(int& position, int m, int n, int& paths) {
    //         if (position == m * n) {
    //             paths++;
    //             return;
    //         }
    //         if (position % n != 0) {
    //             position += 1;
    //             Solve(position, m, n, paths);
    //             position -= 1;
    //         }

    //         if (position + n <= m * n) {
    //             position += n;
    //             Solve(position, m, n, paths);
    //             position -= n;
    //         }
    //     }

public:
    int uniquePaths(int m, int n) {
        // int paths = 0;
        // int position = 1;
        // Solve(position, m, n, paths);
        // return paths;
        vector<int> aboveRow(n, 1);

        for (int row = 1; row < m; row++) {
            vector<int> currentRow(n, 1);
            for (int col = 1; col < n; col++) {
                currentRow[col] = currentRow[col - 1] + aboveRow[col];
            }
            aboveRow = currentRow;
        }

        return aboveRow[n - 1];
    }
};