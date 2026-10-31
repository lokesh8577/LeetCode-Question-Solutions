class Solution {
private:
    void dfs(unordered_map<int, list<int>>& adj, list<int>& Store,
             vector<int>& temp, unordered_map<int, bool>& visited) {
        for (auto i : Store) {
            if (visited[i] != true) {
                visited[i] = true;
                dfs(adj, adj[i], temp, visited);
                temp.push_back(i);
            }
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        for (auto i : edges) {
            int u = i[0];
            int v = i[1];

            adj[v].push_back(u);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            unordered_map<int, bool> visited;
            vector<int> temp;
            dfs(adj, adj[i], temp, visited);
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }

        return ans;
    }
};