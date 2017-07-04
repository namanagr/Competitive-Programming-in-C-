// This program finds the maximum element in a binary tree

#include <iostream>
#include <climits>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int val) {
		this->val = val;
		left = NULL;
		right = NULL;
	}
};

int findMax(TreeNode *root) {
	if (root == NULL)
		return INT_MIN;
	int lmax = findMax(root->left);
	int rmax = findMax(root->right);
	int temp = max(lmax, rmax);
	return max(root->val, temp);
}

int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	int max_num = findMax(root);
	cout<<"Max element = "<<max_num;
	return 0;
}