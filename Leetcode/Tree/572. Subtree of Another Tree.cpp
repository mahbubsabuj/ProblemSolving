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
    bool f (TreeNode* root, TreeNode* subRoot, bool start = false) {
        if (root == NULL || subRoot == NULL) return root == subRoot;
        if (start) {
            if (root->val != subRoot->val) return false;
            return f(root->left, subRoot->left, start) && f(root->right, subRoot->right, start);
        } else {
            bool f1 = false, f2 = false;
            if (root->val == subRoot->val) {
                f1 = (f(root->left, subRoot->left, true) && f(root->right, subRoot->right, true));
            }
            f2 = (f(root->left, subRoot, false) || f(root->right, subRoot, false));
            return f1 || f2;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return f(root, subRoot);
    }
};