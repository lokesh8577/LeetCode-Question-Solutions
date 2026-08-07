class Solution {
private:
    void dfs(int source, int desti, unordered_map<int, bool>& visited,
             unordered_map<int, list<int>>& adj, bool& ans) {
        visited[source] = true;
        if (source == desti) {
            ans = true;
            return;
        }
        for (auto i : adj[source]) {
            if (visited[i] != true) {
                dfs(i, desti, visited, adj, ans);
            }
        }
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        unordered_map<int, list<int>> adj;
        for (auto i : edges) {
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int, bool> visited;
        bool ans = false;
        dfs(source, destination, visited, adj, ans);
        return ans;
    }
};