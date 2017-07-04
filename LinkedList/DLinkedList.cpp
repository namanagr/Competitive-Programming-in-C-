// This program implements Doubly linked list

#include <iostream>

using namespace std;

class DNode {
public:
	int val;
	DNode *next, *prev;

	DNode(int val) {
		this->val = val;
		next = NULL;
		prev = NULL;
	}
};

class DLinkedList {
public:
	DNode *head;

	DLinkedList() {
		head = NULL;
	}

	void push(int val) {
		if (head == NULL) {
			head = new DNode(val);
		}
		else {
			DNode *temp = new DNode(val);
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
	}

	void append(int val) {
		if (head == NULL) {
			head = new DNode(val);
		}
		else {
			DNode *temp = head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new DNode(val);
			temp->next->prev = temp;
		}
	}

	DNode* pop() {
		if (head == NULL) {
			cout << "Empty list. Nothing to pop.";
			return NULL;
		}
		else {
			DNode* temp = head;
			head = head->next;
			head->prev = NULL;
			return temp;
		}
	}

	DNode* del() {
		if (head == NULL) {
			cout << " Empty list. Nothing to delete.";
			return NULL;
		}
		else {
			DNode* temp = head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->prev->next = NULL;
			return temp;
		}
	}

	void printll() {
		if (head == NULL){
			cout << "Empty list. Nothing to print.";
		}
		else {
			DNode *temp = head;
			while (temp != NULL) {
				cout << temp->val << " ";
				temp = temp->next;
			}
		}
	}
};

int main() {
	DLinkedList list;
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

