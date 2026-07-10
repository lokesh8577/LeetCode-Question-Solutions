class Solution {
private:
    void Solve(vector<int>& nums, int index,
               vector<int>& output,
               set<vector<int>>& ans) {

        if(index == nums.size()) {
            if(output.size() > 1) {
                ans.insert(output);
            }
            return;
        }

        if(output.empty() || nums[index] >= output.back()) {
            output.push_back(nums[index]);
            Solve(nums, index + 1, output, ans);
            output.pop_back();
        }

        Solve(nums, index + 1, output, ans);
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> output;

        Solve(nums, 0, output, st);

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};