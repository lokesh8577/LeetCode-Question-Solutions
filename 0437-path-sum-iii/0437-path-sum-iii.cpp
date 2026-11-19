
class Solution {
private:
    void Traverse(TreeNode* root, int targetSum, int& ans) {
        if (root == NULL) {
            return;
        }

        Check(root, 0, targetSum, ans);

        Traverse(root->left, targetSum, ans);
        Traverse(root->right, targetSum, ans);
    }

    void Check(TreeNode* root, long long sum, int targetSum, int& ans) {
        if (root == NULL) {
            return;
        }

        sum += root->val;

        if (sum == targetSum) {
            ans++;
        }

        Check(root->left, sum, targetSum, ans);
        Check(root->right, sum, targetSum, ans);
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        Traverse(root, targetSum, ans);
        return ans;
    }
};
