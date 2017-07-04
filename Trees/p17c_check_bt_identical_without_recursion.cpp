// This program checks if two given binary trees are identical using recursion
// Author : Naman Agrawal

#include <iostream>
#include <queue>
#include "tree.cpp"
using namespace std;

bool compare_bt(TreeNode *root, TreeNode *root2) {
	if (root == NULL && root2 == NULL)
		return true;
	else {
		queue<TreeNode*> q1,q2;
		q1.push(root);
		q2.push(root2);
		while (!q1.empty() && !q2.empty()) {
			TreeNode *front1 = q1.front();
			TreeNode *front2 = q2.front();
			q1.pop();
			q2.pop();
			if (front1->val != front2->val)
				return false;
			if (front1->left != NULL && front2->left != NULL) {
				q1.push(front1->left);
				q2.push(front2->left);
			}
			else if (front1->left == NULL && front2->left == NULL) {}
			else return false;

			if (front1->right != NULL && front2->right != NULL) {
				q1.push(front1->right);
				q2.push(front2->right);
			}
			else if (front1->right == NULL && front2->right == NULL) {}
			else return false;
		}
		return true;
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

	TreeNode *root2 = new TreeNode(1);
	root2->left = new TreeNode(2);
	root2->right = new TreeNode(3);
	root2->left->left = new TreeNode(4);
	 root2->left->right = new TreeNode(5);
	root2->right->left = new TreeNode(6);
	root2->left->left->right = new TreeNode(10);
	root2->right->right = new TreeNode(7);

	if (compare_bt(root, root2))
		cout << "Identical trees" << endl;
	else
		cout << "Not identical" << endl;
	return 0;
}