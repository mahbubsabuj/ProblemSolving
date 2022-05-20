
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        vector<vector<int>> res;
        while (!q.empty()) {
            TreeNode* current = q.front().first;
            int level = q.front().second;
            q.pop();
            if (root == NULL) continue;
            if ((int) res.size() < level + 1) {
                res.push_back(vector<int>());  
            }
            res[level].push_back(current->val);
            if (current->left != NULL) {
                q.push(make_pair(current->left, level + 1));
            }
            if (current->right != NULL) {
                q.push(make_pair(current->right, level + 1));
            }
        }
        return res;
    }
};