// This program finds the number of full nodes in a binary tree without recursion
// Author : Naman Agrawal

#include <iostream>
#include "tree.cpp"
using namespace std;

int halfnodes = 0;

void bt_halfnodes(TreeNode *root) {
	if (root == NULL)
		return;
	if (root->left != NULL && root->right != NULL) {
		bt_halfnodes(root->left);
		bt_halfnodes(root->right);
	}
	else if (root->left != NULL && root->right == NULL) {
		halfnodes++;
		bt_halfnodes(root->left);
	}	
	else if (root->left == NULL && root->right != NULL) {
		halfnodes++;
		bt_halfnodes(root->right);
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
	bt_halfnodes(root);
	cout << "Number of the half nodes in the binary tree is " << halfnodes << endl;
	return 0;
}