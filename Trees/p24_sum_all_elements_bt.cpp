// This program computes the sum of all the elements in a binary tree using recursion
// Author : Naman Agrawal

#include <iostream>
#include "tree.cpp"
using namespace std; 

int sum_bt(TreeNode *root) {
	if (root == NULL)
		return 0;
	return sum_bt(root->left) + sum_bt(root->right) + root->val;
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
	cout << "Sum of all the elements of the binary tree is " << sum_bt(root) << endl;
	return 0;
}