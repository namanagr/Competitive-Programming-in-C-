// This program finds the size of a binary tree using recursion
// Author: Naman Agrawal

#include <iostream>
#include "Tree.h"

using namespace std;

int bt_size(TreeNode *root) {
	if (root == NULL)
		return 0;
	return bt_size(root->left) + bt_size(root->right) + 1;
}

int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->right = new TreeNode(10);
	cout << bt_size(root);
}