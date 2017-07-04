// This program finds the depth / height of a binary tree.
// Author: Naman Agrawal

#include <iostream>
#include "tree.cpp"
using namespace std;

int depth_binarytree(TreeNode *root) {
	if (root == NULL)
		return 0;
	return max(depth_binarytree(root->left), depth_binarytree(root->right)) + 1; 
}

int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	cout << "Depth / height of the binary tree is " << depth_binarytree(root);
	return 0;
}
