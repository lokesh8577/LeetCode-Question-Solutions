class Solution {
private:
    int ans = 0;

    void Solve(TreeNode* root, bool goLeft, int len) {
        if (root == NULL) {
            return;
        }

        ans = max(ans, len);

        if (goLeft) {
            Solve(root->left, false, len + 1);
            Solve(root->right, true, 1);
        } else {
            Solve(root->right, true, len + 1);
            Solve(root->left, false, 1);
        }
    }

public:
    int longestZigZag(TreeNode* root) {
        Solve(root, true, 0);
        Solve(root, false, 0);
        return ans;
    }
};