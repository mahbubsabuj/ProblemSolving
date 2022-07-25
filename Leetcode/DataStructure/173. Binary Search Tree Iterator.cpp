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
class BSTIterator {
public:
    vector<int> inorder_nodes;
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->right);
        inorder_nodes.push_back(root->val);
        inorder(root->left);
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        int node = inorder_nodes.back();
        inorder_nodes.pop_back();
        return node;
    }
    
    bool hasNext() {
        return !inorder_nodes.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */