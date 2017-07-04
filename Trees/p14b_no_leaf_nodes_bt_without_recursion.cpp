// This program finds the number of leaf nodes in a binary tree without recursion
// Author : Naman Agrawal

#include <iostream>
#include <queue>
#include "tree.cpp"
using namespace std;

int bt_leafnodes(TreeNode *root) {
	if (root == NULL)
		return 0;
	queue<TreeNode*> q;
	int leafnodes = 0;
	q.push(root);
	while (!q.empty()) {
		TreeNode *front = q.front();
		q.pop();
		if (front->left == NULL && front->right == NULL)
			leafnodes++;
		else {
			if (front->left != NULL)
				q.push(front->left);
			if (front->right != NULL)
				q.push(front->right);
		}
	}
	return leafnodes;
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
	cout << "Number of the leaf nodes in the binary tree is " << bt_leafnodes(root) << endl;
	return 0;
}