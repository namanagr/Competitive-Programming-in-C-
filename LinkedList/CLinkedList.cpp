// This program implements Circular Linked List
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

class CLinkedList {
public:
	Node *head;

	CLinkedList() {
		head = NULL;
	}

	void push(int val) {
		if (head == NULL) {
			head = new Node(val);
			head->next = head;
		}

		else {
			Node *node = new Node(val);
			node->next = head;
			Node *temp = head;
			while (temp->next != head)
				temp = temp->next;
			temp->next = node;
			head = node;
		}
	}

	void append(int val) {
		if (head == NULL) {
			head = new Node(val);
			head->next = head;
		}
		else {
			Node *temp = head;
			while (temp->next != head)
				temp = temp->next;
			temp->next = new Node(val);
			temp->next->next = head;
		}
	}

	void printll() {
		if (head == NULL)
			cout << "Empty list. Nothing to print.";
		else {
			Node *temp = head;
			cout << temp->val << " ";
			temp = temp->next;
			while (temp != head) {
				cout << temp->val << " ";
				temp = temp->next;
			}
		}
	}

	Node* pop() {
		if (head == NULL) {
			cout << "Empty list. Nothing to pop.";
			return NULL;
		}
		Node* temp = head;
		while (temp->next != head)
			temp = temp->next;
		Node* temp1 = head;
		temp->next = temp->next->next;
		head = head->next;
		return head;
	}

	Node* del() {
		if (head == NULL) {
			cout << "Empty list. Nothing to delete.";
			return NULL;
		}
		Node* temp = head;
		Node* prev = NULL;
		while (temp->next != head) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		return temp;
	}
};

int main() {
	CLinkedList list;
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