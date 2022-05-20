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
    void Inorder(vector<int> &res, TreeNode* root) {
        if (root == NULL) return;
        Inorder(res, root->left);
        res.push_back(root->val);
        Inorder(res, root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        Inorder(res, root);
        return res[k - 1];
    }
};

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?