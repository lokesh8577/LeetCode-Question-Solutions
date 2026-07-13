class Solution {
private:
    void DFS(vector<vector<int>>& graph, int source, int dest,
             vector<vector<int>>& ans, vector<int>& path) {
        path.push_back(source);
        if (source == dest) {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for (int& i : graph[source]) {
            DFS(graph, i, dest, ans, path);
        }
        path.pop_back();
        return;
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> temp;

        DFS(graph, 0, n - 1, ans, temp);

        return ans;
    }
};