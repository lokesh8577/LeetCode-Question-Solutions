class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int s=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int c=0;
                if(grid[i][j]==1){
                    if(i-1>=0 && grid[i-1][j]==1){
                        c++;
                    }
                    if(j-1>=0 && grid[i][j-1]==1){
                        c++;
                    }
                    if(j+1<=grid[i].size()-1 && grid[i][j+1]==1){
                        c++;
                    }
                    if(i+1<=grid.size()-1 && grid[i+1][j]==1){
                        c++;
                    }
                    s+=(4-c);
                }
            }
        }
        return s;
    }
};