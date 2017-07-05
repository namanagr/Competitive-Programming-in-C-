// This program converts a binary tree to its mirror image
// Author : Naman Agrawal

#include <iostream>
#include "tree.cpp"
using namespace std; 

void mirror_bt(TreeNode *root) {
	if (root != NULL) {
		mirror_bt(root->left);
		mirror_bt(root->right);
		TreeNode *temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->left->left->right = new TreeNode(10);
	root->right->right = new TreeNode(7);
	mirror_bt(root);
	return 0;
}