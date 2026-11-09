class Solution {
private:
    void Solve(int index, int target, vector<int>& candidates,
               vector<vector<int>>& ans, vector<int> output) {
        if (index == candidates.size()) {
            if (target == 0) {
                ans.push_back(output);
            }
            return;
        }
        if (target < 0) {
            return;
        }

        // take
        output.push_back(candidates[index]);
        Solve(index, target - candidates[index], candidates, ans, output);
        output.pop_back();

        // skip
        Solve(index + 1, target, candidates, ans, output);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        Solve(0, target, candidates, ans, output);
        return ans;
    }
};