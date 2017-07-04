// This program finds the diameter of a binary tree
// Author : Naman Agrawal
// Hint .. Diameter does not always pass through the root node. 

#include <iostream>
#include "tree.cpp"
using namespace std;

int height_bt(TreeNode *root) {
	if (root == NULL)
		return 0;
	return max(height_bt(root->left),height_bt(root->right)) + 1;

}

int diameter_bt(TreeNode *root) {
	if (root == NULL)
		return 0;
	int left_height = height_bt(root->left);
	int right_height = height_bt(root->right);
	int left_diameter = diameter_bt(root->left);
	int right_diameter = diameter_bt(root->right);
	return max((left_height + right_height + 1), max(left_diameter, right_diameter));
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
	cout << "The diameter of the binary tree is " << diameter_bt(root) << endl;
	return 0;
}