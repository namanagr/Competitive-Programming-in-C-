// This program searches an element in a binary search tree without recursion

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

bool binary_search(TreeNode *root, int item) {
	if (root == NULL)
		return false;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode *temp = q.front();
		if (temp->val == item)
			return true;
		if (temp->left != NULL)
			q.push(temp->left);
		if (temp->right != NULL)
			q.push(temp->right);
		q.pop();
	}
	return false;
}

int main() {
	TreeNode *root = new TreeNode(1);
	root-> left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	cout<<binary_search(root, 4);
	return 0;
}