class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        //first method using map
        // unordered_map<int,bool>visited;
        // for(auto i : edges){
        //     int v = i[1];
        //     visited[v] = true;
        // }

        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     if(visited[i] == false){
        //         ans.push_back(i);
        //     }
        // }
        // return ans;
        

        //second method using degree
        vector<int> inDegree(n,0);
        for(int i=0;i<edges.size();i++){
            inDegree[edges[i][1]]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};