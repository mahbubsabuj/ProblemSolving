/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val) {
            //since it is a bst && p->val < root->val && q->val < root->val than lca will be in left subtree
            return lowestCommonAncestor(root->left, p, q);
        } else if (p->val > root->val && q->val > root->val) {
            //than lca will be in right subtree
            return lowestCommonAncestor(root->right, p, q);
        } else {
            //we found atleast 1 value p | q . this root will be the lca
            return root;
        }
    }
};