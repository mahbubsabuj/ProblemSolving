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
    int getHeight (TreeNode* root, int &height) {
        if (root == NULL) return 0;
        int left = getHeight(root->left, height);
        int right = getHeight(root->right, height);
        height = max(height, left + right + 1);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int height = 0;
        getHeight(root, height);
        return height - 1;
    }
};