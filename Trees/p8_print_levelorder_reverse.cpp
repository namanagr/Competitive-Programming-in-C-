// This program prints level order traversal in reverse order
// Author: Naman Agrawal

#include <iostream>
#include "Tree.h"
#include <queue>
#include <stack>


using namespace std;

void levelorder_traversal (TreeNode *root) {
	if (root == NULL)
		return;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode *temp = q.front();
		cout<<temp->val<<" ";
		if (temp->left != NULL)
			q.push(temp->left);
		if (temp->right != NULL)
			q.push(temp->right);
		q.pop();
	}
}

void levelorder_reverse(TreeNode *root) {
	if (root == NULL)
		return;
	queue<TreeNode*> q;
	stack<TreeNode*> s;
	q.push(root);
	s.push(root);
	while (!q.empty()) {
		TreeNode *front = q.front();
		if (front->left != NULL) {
			q.push(front->left);
			s.push(front->left);
		}
		if (front->right != NULL) {
			q.push(front->right);
			s.push(front->right);
		}
		q.pop();
		//s.push(front->val);
	}
	while (!s.empty()) {
		cout << s.top()->val<< " ";
		s.pop();
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
	levelorder_traversal(root);
	cout << endl;
	levelorder_reverse(root);
}