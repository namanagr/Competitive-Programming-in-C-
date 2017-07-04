// This program implements linked list
// Author: Naman Agrawal

#include <iostream>

using namespace std;

class Node {
public:
	int val;
	Node *next;

	Node(int val) {
		this->val = val;
		next = NULL;
	}
};

class LinkedList {
public:

	Node *head;

	LinkedList() {
		head = NULL;
	}

	void push(int val) {
		if (head == NULL)
			head = new Node(val);
		else {
			Node *temp = new Node(val);
			temp->next = head;
			head = temp;
		}
	}

	void append(int val) {
		if (head == NULL)
			head = new Node(val);
		else {
			Node *temp = head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new Node(val);
		}
	}

	Node* pop() {
		if (head == NULL) {
			cout << "Empty list. Nothing to pop.";
			return NULL;
		}
		else {
			Node *temp = head;
			head = head->next;
			return temp;
		}
	}

	Node* del() {
		if (head == NULL) {
			cout << "Empty list. Nothing to delete.";
			return NULL;
		}
		else {
			Node *temp = head;
			Node *prev = NULL;
			while (temp->next != NULL) {
				prev = temp;
				temp = temp->next;
			}
			prev->next = NULL;
			return temp;
		}
	};

	void printll() {
		if (head == NULL) {
			cout << "Empty list. Nothing to print.";
		}
		else {
			Node *temp = head;
			while (temp != NULL){
				cout << temp->val << " ";
				temp = temp->next;
			}
		}
	}
};

int main() {
	LinkedList list;
	list.append(1);
	list.append(2);
	list.append(3);
	list.append(4);
	list.append(5);
	list.pop();
	list.del();
	list.printll();
	return 0;
}