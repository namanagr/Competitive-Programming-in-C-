// This program prints all root to leaf paths
// Author : Naman Agrawal

#include <iostream>
#include "tree.cpp"
using namespace std; 

void printPath(int path[], int pathLen) {
	for (int i=0; i<pathLen; i++) {
		cout << path[i] << " ";
	}
	cout << endl;
}

void pathExplore(TreeNode *root, int path[], int pathLen) {
	if (root == NULL)
		return;
	path[pathLen] = root->val;
	pathLen++;
	if (root->left == NULL && root->right == NULL)
		printPath(path, pathLen);
	else {
		pathExplore(root->left, path, pathLen);
		pathExplore(root->right, path, pathLen);
	}
}

void printAllPaths(TreeNode *root) {
	if (root == NULL)
		return;
	int path[100];
	pathExplore(root, path, 0);
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
	printAllPaths(root);
	return 0;
}