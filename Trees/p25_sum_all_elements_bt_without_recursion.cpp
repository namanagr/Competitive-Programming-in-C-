// This program computes the sum of all the elements in a binary tree without recursion
// Author : Naman Agrawal

#include <iostream>
#include <queue>
#include "tree.cpp"
using namespace std; 

int sum_bt(TreeNode *root) {
	if (root == NULL)
		return 0;
	queue<TreeNode*> q;
	int sum = 0;
	q.push(root);
	while (!q.empty()) {
		TreeNode *front = q.front();
		sum += front->val;
		q.pop();
		if (front->left != NULL)
			q.push(front->left);
		if (front->right != NULL)
			q.push(front->right);
	}
	return sum;
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
	cout << "Sum of all the elements of the binary tree is " << sum_bt(root) << endl;
	return 0;
}