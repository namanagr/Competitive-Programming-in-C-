// This program finds the find element in a binary tree without recursion. 

#include <iostream>
#include <climits>
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

void findMax_iterative(TreeNode *root) {
	if (root == NULL)
		return;
	queue<TreeNode*> q;
	int max_num = INT_MIN;
	q.push(root);
	while (!q.empty()) {
		TreeNode *temp = q.front();
		if (temp->val > max_num)
			max_num = temp->val;
		if (temp->left != NULL)
			q.push(temp->left);
		if (temp->right != NULL)
			q.push(temp->right);
		q.pop();
	}
	cout << "Maximum element is " << max_num << endl;
}

int main() {
	TreeNode *root = new TreeNode(1);
	root-> left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	findMax_iterative(root);
	return 0;
}