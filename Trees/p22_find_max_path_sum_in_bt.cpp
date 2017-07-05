// This program finds the max path dum in a given binary tree.
// The path may start or end at any node of the binary tree. 
// Author : Naman Agrawal

#include <iostream>
#include "tree.cpp"
using namespace std; 

int maxPathSum (TreeNode *root, int &res) {
	if (root == NULL)
		return 0;
	int l = maxPathSum(root->left, res);
	int r = maxPathSum(root->right, res);
	int max_single = max(max(l, r) + root->val, root->val);
	int max_top = max(max_single, l+r+root->val);
	res = max(res, max_top);
	return max_single;
}

int main() {

	/*
	TreeNode *root = new TreeNode(10);
    root->left        = new TreeNode(2);
    root->right       = new TreeNode(10);
    root->left->left  = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left   = new TreeNode(3);
    root->right->right->right  = new TreeNode(4);
    */

	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->left->left->right = new TreeNode(10);
	root->right->right = new TreeNode(7);

    int res = INT_MIN;
    maxPathSum(root, res);
	cout << "Max path sum is " << res;
	return 0;
}