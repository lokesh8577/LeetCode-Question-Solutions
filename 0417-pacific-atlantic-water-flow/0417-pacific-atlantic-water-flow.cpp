class Solution {
public:
    int ROWS, COLS;
    
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& ocean, int prevHeight){
        if(r<0 || c<0 || r>=ROWS || c>=COLS || heights[r][c]<prevHeight || ocean[r][c])
            return;
        ocean[r][c] = true;
        dfs(heights, r+1, c, ocean, heights[r][c]);
        dfs(heights, r-1, c, ocean, heights[r][c]);
        dfs(heights, r, c+1, ocean, heights[r][c]);
        dfs(heights, r, c-1, ocean, heights[r][c]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool> (COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool> (COLS, false));
        
        for(int c = 0; c < COLS; c++){
            dfs(heights, 0, c, pac, heights[0][c]);
            dfs(heights, ROWS-1, c, atl, heights[ROWS-1][c]);
        }

        for(int r = 0; r < ROWS; r++){
            dfs(heights, r, 0, pac, heights[r][0]);
            dfs(heights, r, COLS-1, atl, heights[r][COLS-1]);
        }
        vector<vector<int>> ans;
        for(int r=0; r<ROWS; r++){
            for(int c=0; c<COLS; c++){
                if(atl[r][c] && pac[r][c])
                    ans.push_back({r, c});
            }
        }
        return ans;
    }
};