/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> vals;
    void dfs (TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        vals.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        sort (vals.begin(), vals.end());
        int res = INT_MAX;
        for (int i = 1; i < (int) vals.size(); ++i) {
            res = min(res, vals[i] - vals[i - 1]);
        }
        return res;
    }
};