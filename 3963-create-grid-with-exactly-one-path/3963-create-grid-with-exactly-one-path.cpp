class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<string>>ans(m,vector<string>(n,"#"));
        int start = 0;
        int end = 0;
            ans[start][end] = ".";
        while(start != m-1 || end != n-1){
            //right side
            if(start < m && end + 1 < n){
                end++;
                ans[start][end] = ".";
            }
            if(start+1 < m && end < n){
                start++;
                ans[start][end] =".";
            }
        }
        vector<string>result;
        for(int i=0;i<ans.size();i++){
            string temp ="";
            for(int j =0;j<ans[0].size();j++){
                temp += ans[i][j];
            }
            result.push_back(temp);
        }
        return result;
    }
};