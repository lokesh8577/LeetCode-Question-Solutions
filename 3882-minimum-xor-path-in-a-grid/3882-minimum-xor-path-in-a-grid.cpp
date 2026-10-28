class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        auto temp = grid;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<unordered_set<int>>>check(m,vector<unordered_set<int>>(n));
        check[0][0].insert(grid[0][0]);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    continue;
                }

                if(i>0){
                    for(auto x : check[i-1][j]){
                        check[i][j].insert(x ^ grid[i][j]);
                    }
                }
                if(j>0){
                    for(auto x : check[i][j-1]){
                        check[i][j].insert(x ^ grid[i][j]);
                    }
                }
            }
        }

        int ans = INT_MAX;
        for(auto x : check[m-1][n-1]){
            ans = min(ans,x);
        }
        return ans;
    }
};