// This program finds the deepest node of the binary tree
// Author : Naman Agrawal
// Trick : use level order traversal and return the last encountered node. 

#include <iostream>
#include <queue>
#include "tree.cpp"
using namespace std;

TreeNode* bt_deepest_node(TreeNode *root) {
	if (root == NULL)
		return NULL;
	queue<TreeNode*> q;
	q.push(root);
	TreeNode *front;
	while (!q.empty()) {
		front = q.front();
		q.pop();
		if (front->left != NULL)
			q.push(front->left);
		if (front->right != NULL)
			q.push(front->right);
	}
	return front;
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
	cout << "The deepest node of the binary tree is " << bt_deepest_node(root)->val << endl;
	return 0;
}
