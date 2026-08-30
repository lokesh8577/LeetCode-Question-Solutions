class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        int idxmx = find(nums.begin(), nums.end(), mx) - nums.begin();
        int idxmn = find(nums.begin(), nums.end(), mn) - nums.begin();

        int a = max(idxmx, idxmn) + 1;
        int b = n - min(idxmx, idxmn);
        int c = idxmx + 1 + n - idxmn;
        int d = idxmn + 1 + n - idxmx;

        return min({a, b, c, d});
    }
};