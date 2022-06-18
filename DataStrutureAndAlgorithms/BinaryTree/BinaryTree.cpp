#include "bits/stdc++.h"

using namespace std;

class TreeNode {
public:
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data) {
		this->data = data;
		left = right = nullptr;
	}
};

void printValues(TreeNode* root) {
	if (root == nullptr) return;
	cout << root->data << ' ';
	printValues(root->left);
	printValues(root->right);
}

int main () {
	 ios::sync_with_stdio(false);
	 cin.tie(nullptr);
	 cout.tie(nullptr);
	 TreeNode* root = new TreeNode(1);
	 root->left = new TreeNode(2);
	 root->right = new TreeNode(3);
	 root->left->left = new TreeNode(4);
	 printValues(root);
}
