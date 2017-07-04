// This program checks if two given binary trees have identical structure using recursion
// Author : Naman Agrawal

#include <iostream>
#include "tree.cpp"
using namespace std;

bool compare_bt(TreeNode *root, TreeNode *root2) {
	if (root == NULL && root2 == NULL)
		return true;
	else if (root != NULL && root2 != NULL) {
		return compare_bt(root->left, root2->left) & compare_bt(root->right, root2->right);
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
	root2->left->left->right = new TreeNode(100);
	root2->right->right = new TreeNode(7);

	if (compare_bt(root, root2))
		cout << "Trees have identical structure" << endl;
	else
		cout << "Trees do not have identical structure." << endl;
	return 0;
}