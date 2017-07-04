// This program checks if two given binary trees are identical using recursion
// Author : Naman Agrawal

#include <iostream>
#include "tree.cpp"
using namespace std;

bool compare_bt(TreeNode *root, TreeNode *root2) {
	// If both the nodes are empty, return true
	if (root == NULL && root2 == NULL)
		return true;
	// Else, if noth the nodes are not null, then compare both the nodes and then check their children.
	else if (root != NULL && root2 != NULL) {
		return (root->val == root2->val) & compare_bt(root->left, root2->left) & compare_bt(root->right, root2->right);
	}
	else return false;
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

	TreeNode *root2 = new TreeNode(1);
	root2->left = new TreeNode(2);
	root2->right = new TreeNode(3);
	root2->left->left = new TreeNode(4);
	 root2->left->right = new TreeNode(5);
	root2->right->left = new TreeNode(6);
	root2->left->left->right = new TreeNode(10);
	root2->right->right = new TreeNode(7);

	if (compare_bt(root, root2))
		cout << "Identical trees" << endl;
	else
		cout << "Not identical" << endl;
	return 0;
}