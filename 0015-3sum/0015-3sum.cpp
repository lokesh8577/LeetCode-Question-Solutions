class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        set<vector<int>> st;

        int start = 0;
        int end = nums.size() - 1;

        while (start < end - 1) {

            int left = start + 1;
            int right = end;

            while (left < right) {

                int sum = nums[start] + nums[left] + nums[right];

                if (sum == 0) {

                    st.insert({
                        nums[start],
                        nums[left],
                        nums[right]
                    });

                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }

            start++;
        }

        vector<vector<int>> ans;

        for (auto x : st) {
            ans.push_back(x);
        }

        return ans;
    }
};