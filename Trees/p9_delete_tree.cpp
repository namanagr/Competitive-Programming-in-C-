// This program deletes a binary tree

#include <iostream>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;

	TreeNode(int val) {
		this->val = val;
		left = NULL;
		right = NULL;
	}
};

void deletetree(TreeNode *root) {
	if (root == NULL)
		return;
	deletetree(root->left);
	deletetree(root->right);
	delete root;
}

int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	deletetree(root);
	return 0;
}