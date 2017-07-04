// This program searches an element in a binary tree

#include <iostream>
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
	if (root->val == item)
		return true;
	else {
		bool temp = binary_search(root->left, item);
		if (temp == true)
			return true;
		else
			return binary_search(root->right, item);
	}
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