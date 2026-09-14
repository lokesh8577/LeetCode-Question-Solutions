class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();

        unordered_map<int, list<int>> Revadj;
        vector<int> degree(v, 0);

        for (int i = 0; i < v; i++) {
            for (auto j : graph[i]) {
                Revadj[j].push_back(i);
                degree[i]++;
            }
        }

        queue<int> q;
        vector<int> SafeNode;
        for (int i = 0; i < v; i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            SafeNode.push_back(node);
            for (auto i : Revadj[node]) {
                degree[i]--;
                if (degree[i] == 0) {
                    q.push(i);
                }
            }
        }

        sort(SafeNode.begin(), SafeNode.end());
        return SafeNode;
    }
};