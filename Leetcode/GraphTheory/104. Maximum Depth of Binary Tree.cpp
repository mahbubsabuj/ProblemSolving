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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        int res = 0;
        while (!q.empty()) {
            pair<TreeNode*, int> u = q.front();
            q.pop();
            res = max(res, u.second);
            if (u.first->left != NULL) q.push(make_pair(u.first->left, u.second + 1));
            if (u.first->right != NULL) q.push(make_pair(u.first->right, u.second + 1));
        }
        return res;
    }
};