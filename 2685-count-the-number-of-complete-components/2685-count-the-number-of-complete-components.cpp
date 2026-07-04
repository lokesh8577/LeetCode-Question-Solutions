class Solution {
private:
    void DFS(int node,
             unordered_map<int,list<int>>& adj,
             unordered_map<int,bool>& visited,
             int &nodes,
             int &edgeCount) {
        
        visited[node] = true;
        nodes++;
        edgeCount += adj[node].size();

        for(auto i : adj[node]){
            if(!visited[i]){
                DFS(i, adj, visited, nodes, edgeCount);
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>> adj;

        for(auto i : edges){
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int,bool> visited;
        int ans = 0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                int nodes = 0;
                int edgeCount = 0;

                DFS(i, adj, visited, nodes, edgeCount);

                edgeCount /= 2;

                int completeEdges = nodes * (nodes - 1) / 2;

                if(edgeCount == completeEdges){
                    ans++;
                }
            }
        }

        return ans;
    }
};