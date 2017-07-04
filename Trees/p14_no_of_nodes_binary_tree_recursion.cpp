// This program finds the number of leaf nodes in a binary tree with recursion
// Author : Naman Agrawal

#include <iostream>
#include <queue>
#include "tree.cpp"
using namespace std;

int leafnodes = 0;

void bt_leafnodes(TreeNode *root) {
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL)
		leafnodes++;
	else {
		bt_leafnodes(root->left);
		bt_leafnodes(root->right);
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
	bt_leafnodes(root);
	cout << "Number of the leaf nodes in the binary tree is " << leafnodes << endl;
	return 0;
}