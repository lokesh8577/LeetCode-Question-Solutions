class Solution {
public:
    vector<int> function(vector<vector<int>>& result, int k) {
        int n = result.size();

        unordered_map<int,int> indegree;
        unordered_map<int,vector<int>> graph;

        vector<int> ans;

        for (int i = 0; i < n; i++){
            graph[result[i][0]].push_back(result[i][1]);
            indegree[result[i][1]] += 1;
        }

        queue<int> q;

        for (int i = 1; i <= k; i++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        while (!q.empty()){
            auto node = q.front();
            q.pop();

            ans.push_back(node);

            for (int neighbor: graph[node]){
                indegree[neighbor] -= 1;

                if (indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }

        if (ans.size() != k){
            return {};
        }

        return ans;
    }

    int kunction(vector<int>& p, int target){
        for (int i = 0; i < p.size(); i++){
            if (p[i] == target){
                return i;
            }
        }

        return -1;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> r = function(rowConditions,k);
        vector<int> c = function(colConditions,k);

        if (r.size() == 0 || c.size() == 0){
            return {};
        }

        vector<vector<int>> res(k,vector<int>(k,0));

        for (int i = 1; i < k+1; i++){
            int row = kunction(r,i);
            int col = kunction(c,i);
            if (row != -1 && col != -1){
                res[row][col] = i;
            }
        }

        return res;
    }
};