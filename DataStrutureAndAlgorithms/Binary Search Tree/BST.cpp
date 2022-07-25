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
	};
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
 	};
	TreeNode* constructFromInorder(vector<int> &inorder, int l, int r) {
		if (l > r) return nullptr;
		int mid = l + (r - l) / 2;
		TreeNode* root = new TreeNode(inorder[mid]);
		root->left = constructFromInorder(inorder, l, mid - 1);
		root->right = constructFromInorder(inorder, mid + 1, r);
		return root;
	};

 	TreeNode* constructFromPreorder(vector<int> &preorder, int* preorder_idx, int min, int max, int n) {
		if (*preorder_idx == n) return nullptr;
		TreeNode* root = nullptr;
		int key = preorder[*preorder_idx];
		if (key > min && key < max) {
			root = new TreeNode(key);
			*preorder_idx = *preorder_idx + 1;
			if (*preorder_idx < n) {
				root->left = constructFromPreorder(preorder, preorder_idx, min, key, n);
			}
			if (*preorder_idx < n) {
				root->right = constructFromPreorder(preorder, preorder_idx, key, max, n);
			}
		}
		return root;
	};
	TreeNode* constructFromPostorder(vector<int>& postorder, int* postorder_idx, int min, int max) {
		if (*postorder_idx == -1) return nullptr;
		TreeNode* root = nullptr;
		int key = postorder[*postorder_idx];
		if (key > min && key < max) {
			root = new TreeNode(key);
			*postorder_idx = *postorder_idx - 1;
			if (*postorder_idx >= 0) {
				root->right = constructFromPostorder(postorder, postorder_idx, key, max);
			}
			if (*postorder_idx >= 0) {
				root->left = constructFromPostorder(postorder, postorder_idx, min, key);
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
	};
	void printInorder(TreeNode* root) {
		if (root == nullptr) return;
		printInorder(root->left);
		cout << root->val << ' ';
		printInorder(root->right);
	};
	void printPreorder(TreeNode* root) {
		if (root == nullptr) return;
		cout << root->val << ' ';
		printPreorder(root->left);
		printPreorder(root->right);
	};
	void printPostorder(TreeNode* root) {
		if (root == nullptr) return;
		printPostorder(root->left);
		printPostorder(root->right);
		cout << root->val << ' ';
	};
public:
	void insertBST(int val) {
		if (root == nullptr) {
			root = insertBST(root, val);
		} else {
			insertBST(root, val);
		}
	};
	void constructFromInorder(vector<int> &inorder) {
		root = constructFromInorder(inorder, 0, (int) inorder.size() - 1);
	};
	void constructFromPreorder(vector<int> &preorder) {
		int preorder_idx = 0;
		root = constructFromPreorder(preorder, &preorder_idx, INT_MIN, INT_MAX, (int) preorder.size());
	};
	void constructFromPostorder(vector<int> &postorder) {
		int postorder_idx = (int) postorder.size() - 1;
		root = constructFromPostorder(postorder, &postorder_idx, INT_MIN, INT_MAX);
	};
	void deleteFromBST(int val) {
		deleteFromBST(root, val);
	};
	void printInorder() {
		printInorder(root);
	};
	void printPreorder() {
		printPreorder(root);
	};
	void printPostorder() {
		printPostorder(root);
	};
	bool isExist(int val) {
		return isExist(root, val);
	};
};


int main () {
	BST *bst = new BST();
	//~ bst->insertBST(10);
	//~ bst->insertBST(5);
	//~ bst->insertBST(3);
	//~ bst->insertBST(4);
	//~ bst->insertBST(6);
	//~ bst->insertBST(15);
	//~ bst->insertBST(18);
	//~ bst->printInorder();
	//~ cout << '\n';
	//~ bst->deleteFromBST(3);
	//~ bst->printInorder();
	//~ cout << '\n';
	// vector<int> preorder = {10, 2, 1, 13, 11};
	// bst->constructFromPreorder(preorder);
	// bst->printPreorder();
	//~ vector<int> inorder = {1, 2, 10, 11, 13};
	//~ bst->constructFromInorder(inorder);
	//~ bst->printInorder();
	//~ cout << '\n';
	bst->printPostorder();
	vector<int> postorder = {2, 1, 13, 11, 10};
	bst->constructFromPostorder(postorder);
	bst->printPostorder();
}
