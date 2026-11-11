
class Solution {
private:
    bool isPresent(vector<int>& banned, int target) {
        int start = 0;
        int end = banned.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (banned[mid] == target) {
                return true;
            }

            if (banned[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return false;
    }

public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());

        int sum = 0;
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (!isPresent(banned, i)) {
                if (sum + i <= maxSum) {
                    sum += i;
                    ans++;
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};
