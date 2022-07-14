#include "bits/stdc++.h"

using namespace std;

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

void levelOrderTravarsal(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode* front = q.front();
		q.pop();
		cout << front->value << ' ';
		if (front->left != nullptr) {
			q.push(front->left);
		}
		if (front->right != nullptr) {
			q.push(front->right);
		}
	}
}


int main () {
	 vector<int> postorder = {4, 2, 5, 3, 1};
	 vector<int> inorder = {4, 2, 1, 5, 3};
	 TreeNode* root = Build(postorder, inorder, 0, (int) postorder.size() - 1);
	 levelOrderTravarsal(root);
}
