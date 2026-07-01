class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mp;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            mp[u]++;
            mp[v]++;
        }

        int maxi = INT_MIN;
        int ans;
        for(auto &it : mp){
            if(it.second > maxi){
                maxi = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};