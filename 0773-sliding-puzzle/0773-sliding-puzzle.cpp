class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for (auto &row : board) {
            for (int x : row) {
                start += char(x + '0');
            }
        }

        string target = "123450";

        vector<vector<int>> adj = {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };

        queue<pair<string, int>> q;
        unordered_set<string> vis;

        q.push({start, 0});
        vis.insert(start);

        while (!q.empty()) {
            auto [state, steps] = q.front();
            q.pop();

            if (state == target)
                return steps;

            int zero = state.find('0');

            for (int nextPos : adj[zero]) {
                string nextState = state;
                swap(nextState[zero], nextState[nextPos]);

                if (!vis.count(nextState)) {
                    vis.insert(nextState);
                    q.push({nextState, steps + 1});
                }
            }
        }

        return -1;
    }
};