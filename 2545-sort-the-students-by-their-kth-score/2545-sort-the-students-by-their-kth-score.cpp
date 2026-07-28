class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int m = score.size();
        int n = score[0].size();
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < m; i++) {
            pq.push({score[i][k], i});
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            int index = pq.top().second;
            pq.pop();
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                temp.push_back(score[index][j]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};