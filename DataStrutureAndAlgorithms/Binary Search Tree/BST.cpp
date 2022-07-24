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
	TreeNode* findInorderSuccessor(TreeNode* root) {
		TreeNode* current = root;
		while (current != nullptr && current->left != nullptr) {
			current = current->left;
		}
		return current;
	} 
	TreeNode* deleteFromBST(TreeNode* root, int val) {
		if (root == nullptr) {
			//when val doesn't exist in bst
			return nullptr;
		}
		if (val > root->val) {
			root->right = deleteFromBST(root->right, val);
		} else if (val < root->val) {
			root->left = deleteFromBST(root->left, val);
		} else {
			if (root->left == nullptr) {
				TreeNode* right = root->right;
				free(root);
				return right;
			} else if (root->right == nullptr) {
				TreeNode* left = root->left;
				free(root);
				return left;
			} else {
				TreeNode* inorderSuccessor = findInorderSuccessor(root->right);
				root->val = inorderSuccessor->val;
				root->right = deleteFromBST(root->right, inorderSuccessor->val);
			}
		}
		return root;
 	}
	bool isExist(TreeNode* root, int val) {
		if (root == nullptr) return false;
		if (root->val == val) {
			return true;
		}
		if (root->val > val) {
			return isExist(root->left, val);
		} else {
			return isExist(root->right, val);
		}
	}
	
public:
	void insertBST(int val) {
		if (root == nullptr) {
			root = insertBST(root, val);
		} else {
			insertBST(root, val);
		}
	};
	void deleteFromBST(int val) {
		deleteFromBST(root, val);
	}
	void printInorder() {
		printInorder(root);
	}
	bool isExist(int val) {
		return isExist(root, val);
	}
};


int main () {
	BST *bst = new BST();
	bst->insertBST(10);
	bst->insertBST(5);
	bst->insertBST(3);
	bst->insertBST(4);
	bst->insertBST(6);
	bst->insertBST(15);
	bst->insertBST(18);
	bst->printInorder();
	cout << '\n';
	bst->deleteFromBST(3);
	bst->printInorder();
	cout << '\n';

}
