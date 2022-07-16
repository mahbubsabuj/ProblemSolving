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
    int idx = 0;
    TreeNode* Build(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if (idx == (int) preorder.size()) return nullptr;
        if (l > r) return nullptr;
        TreeNode* root = new TreeNode(preorder[idx++]);
        int inorder_idx = -1;
        for (int i = l; i <= r; ++i) {
            if (preorder[idx - 1] == inorder[i]) {
                inorder_idx = i;
                break;
            }
        }
        root->left = Build(preorder, inorder, l, inorder_idx - 1);
        root->right = Build(preorder, inorder, inorder_idx + 1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return Build(preorder, inorder, 0, (int) inorder.size() - 1);
    }
};