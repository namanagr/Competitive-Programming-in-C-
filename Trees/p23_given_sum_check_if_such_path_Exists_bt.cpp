// This program finds out all the paths that sum up and match a given sum.
// Also, print all those encountered paths.
// Author : Naman Agrawal

#include <iostream>
#include "tree.cpp"
using namespace std; 

 bool pathExplorer(TreeNode *root, int provided_sum, int currentSum) {
	if (root == NULL)
		return currentSum == provided_sum;
	currentSum += root->val;
	bool l = pathExplorer(root->left, provided_sum, currentSum);
	bool r = pathExplorer(root->right, provided_sum, currentSum);
	return l | r;
}

bool hasSum(TreeNode *root, int provided_sum) {
	return pathExplorer(root, provided_sum, 0);
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
	if (hasSum(root, 8))
		cout << "Exists.." << endl;
	else
		cout << "Does not exist.." << endl;
	return 0;
}