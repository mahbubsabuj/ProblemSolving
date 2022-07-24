/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    vector<int> inorder_nodes;
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder_nodes.push_back(root->val);
        inorder(root->left);
        inorder(root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        inorder_nodes.clear();
        inorder(root);
        int n = (int) inorder_nodes.size();
        for (int i = 0; i < n; ++i) {
            string current_node = to_string(inorder_nodes[i]);
            current_node.push_back(',');
            for (char c : current_node) {
                res.push_back(c);
            }
        }
        return res;
    }
    TreeNode* insert(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (val > root->val) {
            root->right = insert(root->right, val);
        } else {
            root->left = insert(root->left, val);
        }
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int now = 0;
        vector<int> nodes;
        int n = (int) data.size();
        for (int i = 0; i < n; ++i) {
            if (data[i] == ',') {
                nodes.push_back(now);
                now = 0;
            } else {
                now = now * 10 + (data[i] - '0');
            }
        }
        int m = (int) nodes.size();
        TreeNode* root = nullptr;
        for (int i = 0; i < m; ++i) {
            if (root == nullptr) {
                root = insert(root, nodes[i]);
            } else {
                insert(root, nodes[i]);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;