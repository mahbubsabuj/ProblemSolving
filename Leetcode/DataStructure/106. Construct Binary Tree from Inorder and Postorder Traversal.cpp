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
    TreeNode* Build(vector<int>& postorder, vector<int>& inorder, int l, int r) {
        if (l > r) return nullptr;
        TreeNode* root = new TreeNode(postorder[idx--]);
        int inorder_idx = -1;
        for (int i = l; i <= r; ++i) {
            if (postorder[idx + 1] == inorder[i]) {
                inorder_idx = i;
                break;
            }
        }
        assert(inorder_idx != -1);
        root->right = Build(postorder, inorder, inorder_idx + 1, r);
        root->left = Build(postorder, inorder, l, inorder_idx - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        idx = inorder.size() - 1;
        return Build(postorder, inorder, 0, idx);
    }
};