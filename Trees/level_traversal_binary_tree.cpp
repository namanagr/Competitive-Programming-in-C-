// This program performs Level order traversal of a binary tree

#include<iostream>
#include<queue>

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

void levelorder_traversal (TreeNode *root) {
	if (root == NULL)
		return;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode *temp = q.front();
		cout<<temp->val;
		if (temp->left != NULL)
			q.push(temp->left);
		if (temp->right != NULL)
			q.push(temp->right);
		q.pop();
	}
}

int main(){
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	levelorder_traversal(root);
	return 0;
}
