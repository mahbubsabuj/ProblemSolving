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
    bool isValidBST(TreeNode* root, long long low = LLONG_MIN, long long high = LLONG_MAX) {
        if (root == NULL) return true;
        //root->val should be less than high & greater than low. 
        //left subtree should be less than root->val & greater than low & right subtree should be less than high & greater than root->val
        if ((low < root->val && root->val < high) && isValidBST(root->left, low, root->val) && isValidBST(root->right, root->val, high)) {
            return true;
        }
        return false;
    }
};