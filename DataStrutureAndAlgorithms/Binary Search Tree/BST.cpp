#include "bits/stdc++.h"

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) {
		this->val = val;
		left = right = nullptr;
	}
};

class BST {
private:
	TreeNode* root = nullptr;
	TreeNode* insertBST(TreeNode* root, int val) {
		if (root == nullptr) {
			return new TreeNode(val);
		}
		if (val > root->val) {
			root->right = insertBST(root->right, val);
		} else {
			root->left = insertBST(root->left, val);
		}
		return root;
	}
	void printInorder(TreeNode* root) {
		if (root == nullptr) return;
		printInorder(root->left);
		cout << root->val << ' ';
		printInorder(root->right);
	}
	
public:
	void insertBST(int val) {
		root = insertBST(root, val);
	};
	void printInorder() {
		printInorder(root);
	}
};


int main () {
	BST *bst = new BST();
	bst->insertBST(3);
	bst->insertBST(2);
	bst->insertBST(5);
	bst->printInorder();
}
