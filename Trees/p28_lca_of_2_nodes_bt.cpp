// Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself).
//The LCA of n1 and n2 in T is the shared ancestor of n1 and n2 that is located farthest from the root.
// Author : Naman Agrawal

#include <iostream>
#include "tree.cpp"
using namespace std;

TreeNode* lca_bt(TreeNode *root, TreeNode *alpha, TreeNode *beta) {
	if (root == NULL)
		return NULL;
	if (root == alpha || root == beta)
		return root;
	TreeNode *left = lca_bt(root->left, alpha, beta);
	TreeNode *right = lca_bt(root->right, alpha, beta);
	if (left != NULL && right != NULL) // alpha and beta are on both the sides of root
		return root;
	else if (left != NULL)
		return left;
	else
		return right;
}

int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->right = new TreeNode(10);
	cout << lca_bt(root, root->left->left, root->right->right)->val;
	return 0;
	return 0;
}