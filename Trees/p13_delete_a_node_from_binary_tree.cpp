// This program deletes a node of the binary tree
// Author : Naman Agrawal
// Trick : use level order traversal and replace the node's data with that of the deepest node.
// Delete the deepest node then.

#include <iostream>
#include <queue>
#include "tree.cpp"
using namespace std;

TreeNode* bt_delete_node(TreeNode *root) {
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

TreeNode* bt_delete_node(TreeNode *root, int data) {
	if (root == NULL)
		return NULL;
	queue<TreeNode*> q;
	q.push(root);
	TreeNode *front = NULL;
	TreeNode *prev = NULL;
	TreeNode *target = NULL;
	while (!q.empty()) {
		prev = front;
		front = q.front();
		q.pop();
		if (front->val == data)
			target = front;
		if (front->left != NULL)
			q.push(front->left);
		if (front->right != NULL)
			q.push(front->right);
	}
	if (target != NULL) {
		target->val = front->val;
		if (prev->right != NULL)
			prev->right = NULL;
		else
			prev->left = NULL;
		delete front;
	}
	else
		cout << "Node not found..";
}

void levelorder_traverse(TreeNode *root) {
	if (root == NULL)
		return;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode *front = q.front();
		cout << front->val << " ";
		q.pop();
		if (front->left != NULL)
			q.push(front->left);
		if (front->right != NULL)
			q.push(front->right);
	}	
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
	bt_delete_node(root,1);
	cout << "After deleting the node.. " << endl;
	levelorder_traverse(root);
	return 0;
}
