class Solution {
private:
    bool dfs(int node,
             unordered_map<int, list<int>>& adj,
             unordered_map<int, bool>& visited,
             unordered_map<int, bool>& pathVisited) {

        visited[node] = true;
        pathVisited[node] = true;

        for (auto neighbour : adj[node]) {

            if (!visited[neighbour]) {
                if (dfs(neighbour, adj, visited, pathVisited)) {
                    return true;
                }
            }
            else if (pathVisited[neighbour]) {
                return true;
            }
        }

        pathVisited[node] = false;

        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, list<int>> adj;

        for (auto p : prerequisites) {
            int u = p[0];
            int v = p[1];

            adj[v].push_back(u);
        }

        unordered_map<int, bool> visited;
        unordered_map<int, bool> pathVisited;

        for (int i = 0; i < numCourses; i++) {

            if (!visited[i]) {
                if (dfs(i, adj, visited, pathVisited)) {
                    return false;
                }
            }
        }

        return true;
    }
};