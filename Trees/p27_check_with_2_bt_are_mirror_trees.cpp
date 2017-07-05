// This program checks if two given binary trees are mirror images of each other
// Author : Naman Agrawal

#include <iostream>
#include "tree.cpp"
using namespace std; 

bool areMirror(TreeNode *root1, TreeNode *root2) {
	if (root1 == NULL && root2 == NULL)
		return true;
	else if (root1 == NULL || root2 == NULL)
		return false;
	else if (root1->val != root2->val)
		return false;
	else {
		return areMirror(root1->left, root2->right) & areMirror(root1->right, root2->left);
	}
}

int main() {
	TreeNode *root1 = new TreeNode(1);
	root1->left = new TreeNode(2);
	root1->right = new TreeNode(3);
	root1->left->left = new TreeNode(4);
	root1->left->right = new TreeNode(5);

	TreeNode *root2 = new TreeNode(1);
	root2->right = new TreeNode(2);
	root2->left = new TreeNode(3);
	root2->right->right = new TreeNode(4);
	root2->right->left = new TreeNode(5);

	if (areMirror(root1, root2))
		cout << "Given trees are mirrors of each other.";
	else 
		cout << "Given trees are not mirrors of each other.";
	return 0;
}