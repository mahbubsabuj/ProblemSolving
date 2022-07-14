#include "bits/stdc++.h"

using namespace std;

//~ 1. Pick element from end of postorder & create a node
//~ 2. Decrement postorder idx
//~ 3. Search for picked element's position in inorder
//~ 4. Call to build left subtree from inorder's from 0 to pos - 1
//~ 5. Call to build right subtree from inorder's pos + 1 to n
//~ 6. return the node

class TreeNode {
	public:
		int value;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int value) {
			this->value = value;
			left = right = nullptr;
		}
};

TreeNode* Build(vector<int> & postorder, vector<int> &inorder, int l, int r) {
	static int idx = (int) postorder.size() - 1;
	if (l > r) return nullptr;
	TreeNode* root = new TreeNode(postorder[idx--]);
	int inorder_idx = -1;
	for (int i = l; i <= r; ++i) {
		if (inorder[i] == postorder[idx + 1]) {
			inorder_idx = i;
			break;
		}
	}
	if (inorder_idx == -1) {
		//invalid postorder and inorder sequence
		assert(false);
	}
	root->right = Build(postorder, inorder, inorder_idx + 1, r);
	root->left = Build(postorder, inorder, l, inorder_idx - 1);
	
	return root;
} 

void printInorder(TreeNode* root) {
	if (root == nullptr) return;
	//left root right
	printInorder(root->left);
	cout << root->value << ' ';
	printInorder(root->right);
}

void printPreorder(TreeNode* root) {
	if (root == nullptr) return;
	//root left right
	cout << root->value << ' ';
	printInorder(root->left);
	printInorder(root->right);
}

void printPostorder(TreeNode* root) {
	if (root == nullptr) return;
	//left right root
	printInorder(root->left);
	printInorder(root->right);
	cout << root->value << ' ';
}

int main () {
	 vector<int> postorder = {4, 2, 5, 3, 1};
	 vector<int> inorder = {4, 2, 1, 5, 3};
	 TreeNode* root = Build(postorder, inorder, 0, (int) postorder.size() - 1);
	 cout << "Preorder:\n";
	 printPreorder(root);
	 cout << "\nInorder:\n";
	 printInorder(root);
	 cout << "\nPostorder:\n";
	 printPostorder(root);
	 cout << "\nLevel Order: \n";
	 levelOrderTravarsal(root);
}
