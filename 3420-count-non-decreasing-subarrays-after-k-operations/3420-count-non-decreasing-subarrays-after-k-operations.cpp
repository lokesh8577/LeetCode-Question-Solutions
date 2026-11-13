static constexpr int MAX = 1e5;
static int dq[MAX], front, back;
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        front = back = n;
        long long res = 0, curr = 0;
        for (int r = n - 1, l = r; l >= 0; --l) {
            const int x = nums[l];
            while (front < back && nums[dq[front]] <= x) {
                const int start = dq[front]; ++front;
                const int end = (front == back) ? r + 1 : dq[front];
                curr += 1LL * (x - nums[start]) * (end - start);
            }
            dq[--front] = l;
            while (curr > k) {
                curr -= nums[dq[back - 1]] - nums[r];
                if (dq[back - 1] == r) --back;
                --r;
            }
            res += r - l + 1;
        }
        return res;
    }
};