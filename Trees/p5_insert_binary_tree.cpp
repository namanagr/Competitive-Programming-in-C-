// This program inserts an element in a binary tree.
// Author: Naman Agrawal
// using level order traversal

#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;

	TreeNode(int val) {
		this->val = val;
		left = NULL;
		right = NULL;
	}
};

void preorder_traverse(TreeNode *root) {
	if (root == NULL)
		return;
	cout << root->val << " ";
	preorder_traverse(root->left);
	preorder_traverse(root->right);
}

void bt_insert(TreeNode *root, int item) {
	if (root == NULL)
		root = new TreeNode(item);
	else {
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()){
			TreeNode *front = q.front();
			if (front->left == NULL) {
				front->left = new TreeNode(item);
				break;
			}
			else {
				q.push(front->left);
			}
			if (front->right == NULL) {
				front->right = new TreeNode(item);
				break;
			}
			else {
				q.push(front->right);
			}
			q.pop();
	    } 
	}
}

int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->right = new TreeNode(10);
	bt_insert(root, 7);
	preorder_traverse(root);
	return 0;
}
