// This program finds the number of full nodes in a binary tree using recursion
// Author : Naman Agrawal

#include <iostream>
#include "tree.cpp"
using namespace std;

int fullnodes = 0;

void bt_fullnodes(TreeNode *root) {
	if (root == NULL)
		return;
	if (root->left != NULL && root->right != NULL) {
		fullnodes++;
		bt_fullnodes(root->left);
		bt_fullnodes(root->right);
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
	bt_fullnodes(root);
	cout << "Number of the full nodes in the binary tree is " << fullnodes << endl;
	return 0;
}