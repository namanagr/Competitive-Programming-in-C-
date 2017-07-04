// This program finds the depth / height of a binary tree without using recursion
// Author : Naman Agrawal
// Trick: used level order traversal and counted height for each level

#include <iostream>
#include "tree.cpp"
#include <queue>
using namespace std;

int depthbinarytree(TreeNode *root) {
	if (root == NULL)
		return 0;
	int height = 0;
	queue<TreeNode*> q;
	q.push(root);
	int nodecount = q.size();
	while(1) {
		int nodecount = q.size();
		if (nodecount == 0)
			return height;
		height++;
		while (nodecount > 0) {
			TreeNode *front = q.front();
			q.pop();
			if (front->left != NULL)
				q.push(front->left);
			if (front->right != NULL)
				q.push(front->right);
			nodecount--;
		}
	}
}

int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	cout << "The depth / height of the binary tree is " << depthbinarytree(root) << endl;
	return 0;
}