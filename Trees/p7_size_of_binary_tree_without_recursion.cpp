// This program finds the size of a binary tree without recursion
// Author: Naman Agrawal

#include <iostream>
#include <queue>
#include "Tree.h"

using namespace std;

int bt_size(TreeNode *root) {
	if (root == NULL)
		return 0;
	int count = 0;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		count++;
		TreeNode *temp = q.front();
		if (temp->left != NULL)
			q.push(temp->left);
		if (temp->right != NULL)
			q.push(temp->right);
		q.pop();
	}
	return count;

}

int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->right = new TreeNode(10);
	cout << bt_size(root);
}