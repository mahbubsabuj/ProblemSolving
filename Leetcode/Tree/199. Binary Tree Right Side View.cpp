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
    vector<int> levels;
    void dfs (TreeNode* root, int level = 0) {
        if (root == NULL) return;
        if ((int) levels.size() < level + 1) {
            levels.push_back(root->val);
        } else {
            levels[level] = root->val;
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) return levels;
        dfs(root);
        return levels;
    }
};