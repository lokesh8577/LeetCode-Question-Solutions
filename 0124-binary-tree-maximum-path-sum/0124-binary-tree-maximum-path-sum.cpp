class Solution {
private:
    int Solve(TreeNode* root, int& ans) {
        if (root == NULL) {
            return 0;
        }

        int left = max(0, Solve(root->left, ans));
        int right = max(0, Solve(root->right, ans));

        ans = max(ans, left + right + root->val);
        ans = max({ans, left + root->val, right + root->val, root->val});

        return max(left + root->val, max(root->val, right + root->val));
    }

public:
    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        int temp = Solve(root, ans);
        return ans;
    }
};