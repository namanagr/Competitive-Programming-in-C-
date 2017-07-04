// This program performs pre-order traversal of a binary tree.
// Author: Naman Agrawal

#include <iostream>
#include "Tree.h"

using namespace std;

void preorder_traverse(TreeNode *root) {
	if (root == NULL)
		return;
	cout << root->val << " ";
	preorder_traverse(root->left);
	preorder_traverse(root->right);
}

int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	preorder_traverse(root);
	return 0;
}
