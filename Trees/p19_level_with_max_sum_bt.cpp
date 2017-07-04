// This program finds the level that has max sum in a binary tree.
// Author : Naman Agrawal

#include <iostream>
#include <queue>
#include "tree.cpp"
using namespace std;

int bt_max_sum_level(TreeNode *root) {
	if (root == NULL)
		return -1;
	int max_sum_level = -1;
	int level = 0;
	int max_sum = 0;
	queue<TreeNode*> q;
	q.push(root);
	while (1) {
		int nodecount = q.size();
		if (nodecount == 0)
			break;
		int sum = 0;
		while (nodecount > 0) {
			TreeNode *front = q.front();
			q.pop();
			sum += front->val;
			if (front->left != NULL)
				q.push(front->left);
			if (front->right != NULL)
				q.push(front->right);
			nodecount--;
		}
		if (level == 0) {
			max_sum_level = 0;
			max_sum = sum;
		}
		else if (sum > max_sum) {
			max_sum = sum;
			max_sum_level = level;
		}
		level++;
	}
	return max_sum_level;
}

int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->right = new TreeNode(10);
	cout << bt_max_sum_level(root);
	return 0;
}