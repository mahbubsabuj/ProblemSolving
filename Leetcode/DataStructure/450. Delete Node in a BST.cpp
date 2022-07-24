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
    TreeNode* getInorderSuccessor(TreeNode* root) {
        TreeNode* current = root;
        while (current != nullptr && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            if (root->left == nullptr) {
                TreeNode* right = root->right;
                return right;
            } else if (root->right == nullptr) {
                TreeNode* left = root->left;
                return left;
            } else {
                TreeNode* successor = getInorderSuccessor(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }
};