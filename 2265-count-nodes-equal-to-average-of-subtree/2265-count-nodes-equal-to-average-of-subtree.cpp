class Solution {
private:
    pair<int, int> Solve(TreeNode* root, int& ans) {
        if (root == NULL) {
            return {0, 0};
        }

        auto left = Solve(root->left, ans);
        auto right = Solve(root->right, ans);

        int val = root->val;
        int Total_nodes = 1 + left.second + right.second;
        int Total_val = val + left.first + right.first;

        if (Total_val / Total_nodes == val) {
            ans++;
        }

        return {Total_val, Total_nodes};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        auto temp = Solve(root, ans);
        return ans;
    }
};