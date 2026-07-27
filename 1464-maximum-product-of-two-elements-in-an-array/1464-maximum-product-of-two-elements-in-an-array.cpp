class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int maxi = INT_MIN;
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = 0; j < nums.size(); j++) {
        //         if (i != j) {
        //             int sum = (nums[i] - 1) * (nums[j] - 1);
        //             if (sum > maxi) {
        //                 maxi = sum;
        //             }
        //         }
        //     }
        // }
        // return maxi;

        // second method
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++) {
            if (pq.size() < 2) {
                pq.push(nums[i] - 1);
            } else {
                if (pq.top() < nums[i] - 1) {
                    pq.pop();
                    pq.push(nums[i] - 1);
                }
            }
        }

        int ans = pq.top();
        pq.pop();
        ans *= pq.top();
        return ans;
    }
};