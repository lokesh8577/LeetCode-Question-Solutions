class Solution {
public:
    vector<vector<int>>
    filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                            int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end(),
             [](vector<int>& v1, vector<int>& v2) { return v1[0] < v2[0]; });

        vector<vector<int>> newlist;

        for (vector<int>& v : occupiedIntervals) {
            if (newlist.empty() || newlist.back()[1] < v[0] - 1) {
                newlist.push_back(v);
            } else {
                int end = max(v[1], newlist.back()[1]);
                newlist.back()[1] = max(v[1], end);
            }
        }
        vector<vector<int>> ans;
        for (vector<int>& v : newlist) {
            if (v[1] < freeStart) {
                ans.push_back(v);
                continue;
            }

            if (v[0] > freeEnd) {
                ans.push_back(v);
                continue;
            }

            if(v[0] < freeStart){
                ans.push_back({v[0],freeStart-1});
            }
            if(v[1] > freeEnd){
                ans.push_back({freeEnd+1,v[1]});
            }
        }

        return ans;
    }
};