class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if (n <= 2)
            return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<double, int> mp;

            for (int j = i + 1; j < n; j++) {
                double slope;

                if (points[j][0] == points[i][0]) {
                    slope = DBL_MAX;
                } else {
                    slope = (double)(points[j][1] - points[i][1]) /
                            (points[j][0] - points[i][0]);
                }

                mp[slope]++;
                ans = max(ans, mp[slope] + 1);
            }
        }

        return ans;
    }
};