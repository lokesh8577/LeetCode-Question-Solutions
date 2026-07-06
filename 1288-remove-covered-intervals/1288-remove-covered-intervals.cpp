class Solution {
private:
    void remove_value(vector<vector<int>>& intervals, int index) {
        swap(intervals[index], intervals.back());
        intervals.pop_back();
    }

public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        for (int i = 0; i < intervals.size(); i++) {
            for (int j = 0; j < intervals.size(); j++) {
                if (i == j) continue;

                int a = intervals[i][0], b = intervals[i][1];
                int c = intervals[j][0], d = intervals[j][1];

                if (c <= a && b <= d) {
                    remove_value(intervals, i);
                    i = -1; 
                    break; 
                }
            }
        }

        return intervals.size();
    }
};
