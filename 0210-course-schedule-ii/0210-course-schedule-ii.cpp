class Solution {
public:

    bool topoDFS(unordered_map<int, list<int>>& adj,
                 unordered_map<int, bool>& visited,
                 unordered_map<int, bool>& pathVisited,
                 int node,
                 stack<int>& st) {

        visited[node] = true;
        pathVisited[node] = true;

        for (auto neighbour : adj[node]) {

            if (!visited[neighbour]) {

                if (topoDFS(adj, visited, pathVisited,
                            neighbour, st)) {
                    return true;
                }
            }
            else if (pathVisited[neighbour]) {
                return true; // cycle
            }
        }

        pathVisited[node] = false;

        st.push(node);

        return false;
    }

    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        unordered_map<int, list<int>> adj;

        // [u, v] => v -> u
        for (auto i : prerequisites) {
            int u = i[0];
            int v = i[1];

            adj[v].push_back(u);
        }

        unordered_map<int, bool> visited;
        unordered_map<int, bool> pathVisited;

        stack<int> st;

        for (int i = 0; i < numCourses; i++) {

            if (!visited[i]) {

                if (topoDFS(adj, visited, pathVisited,
                            i, st)) {
                    return {};
                }
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};