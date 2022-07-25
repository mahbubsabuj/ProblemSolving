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
    TreeNode* construct(vector<int>& preorder, int *preorder_idx, int l, int r) {
        if (*preorder_idx == preorder.size()) return nullptr;
        TreeNode* root = nullptr;
        int val = preorder[*preorder_idx];
        if (val > l && val < r) {
            root = new TreeNode(val);
            *preorder_idx = *preorder_idx + 1;
            if (*preorder_idx < (int) preorder.size()) {
                root->left = construct(preorder, preorder_idx, l, val);
            }
            if (*preorder_idx < (int) preorder.size()) {
                root->right = construct(preorder, preorder_idx, val, r);
            }
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preorder_idx = 0;
        return construct(preorder, &preorder_idx, INT_MIN, INT_MAX);
    }
};