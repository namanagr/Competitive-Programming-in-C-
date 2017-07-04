// This program finds out all the paths from root to leaf and each path corresponds to a number. The program returns the sum of all those numbers.
// Author : Naman Agrawal

#include <iostream>
#include "tree.cpp"
using namespace std; 

int total_sum = 0;

void pathExplore(TreeNode *root, int current_sum) {
	if (root == NULL)
		return;
	current_sum = current_sum*10 + root->val;
	if (root->left == NULL && root->right == NULL)
		total_sum += current_sum;
	pathExplore(root->left, current_sum);
	pathExplore(root->right, current_sum);
}

void printAllPaths(TreeNode *root) {
	if (root == NULL)
		return;
	pathExplore(root, 0);
}

int main() {
	TreeNode *root = new TreeNode(2);
	root->left = new TreeNode(3);
	root->right = new TreeNode(4);
	printAllPaths(root);
	cout << endl << "The sum of all the numbers is " << total_sum << endl;
	return 0;
}