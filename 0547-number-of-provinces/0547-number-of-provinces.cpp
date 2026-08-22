class Solution {
private:
    void dfs(int node, unordered_map<int, list<int>>& adj,
             unordered_map<int, bool>& visited) {
        visited[node] = true;

        for (auto neighbour : adj[node]) {
            if (!visited[neighbour])
                dfs(neighbour, adj, visited);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j] == 1) {
                    adj[i + 1].push_back(j + 1);
                }
            }
        }

        unordered_map<int, bool> visited;
        int compo = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                compo++;
                dfs(i, adj, visited);
            }
        }
        return compo;
    }
};