class Solution {
private:
    void FindAllParent(TreeNode* root,
                       unordered_map<TreeNode*, TreeNode*>& mp) {
        // base case
        if (root == NULL)
            return;

        if (root->left != NULL) {
            mp[root->left] = root;
            FindAllParent(root->left, mp);
        }

        if (root->right != NULL) {
            mp[root->right] = root;
            FindAllParent(root->right, mp);
        }
    }

    void Solve(TreeNode* root, int k, unordered_map<TreeNode*, TreeNode*> mp,
               int count, vector<int>& ans,
               unordered_map<TreeNode*, bool>& visited) {
        if (root == NULL) {
            return;
        }

        if (count == k) {
            ans.push_back(root->val);
            return;
        }
        visited[root] = true;
        // left side
        if (root->left != NULL && !visited[root->left]) {
            Solve(root->left, k, mp, count + 1, ans, visited);
        }

        // right side
        if (root->right != NULL && !visited[root->right]) {
            Solve(root->right, k, mp, count + 1, ans, visited);
        }

        // parent
        if (mp[root] != NULL && !visited[mp[root]]) {
            Solve(mp[root], k, mp, count + 1, ans, visited);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = NULL;
        FindAllParent(root, parent);

        vector<int> ans;
        unordered_map<TreeNode*, bool> visited;
        Solve(target, k, parent, 0, ans, visited);
        return ans;
    }
};