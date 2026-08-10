#include <bits/stdc++.h>
using namespace std;
class Node {
	public:
	int data;
	Node* next;
	Node(int value) {
		data = value;
		next = NULL;
	}
};
class LinkedList {
	private:
	Node* head;
	public:
	LinkedList() {
		head = NULL;
	}
	void insert(int value) {
		Node* newNode = new Node(value);
		if(head == NULL) {
			head = newNode;
			return;
		}
		Node* curr = head;
		while(curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = newNode;
	}
	void rotateLeft(int k) {
		if(head == NULL || head->next == NULL)
			return;
		int n = 1;
		Node* last = head;
		while(last->next != NULL) {
			last = last->next;
			n++;
		}
		k = k % n;
		if(k == 0)
			return;
		Node* curr = head;
		for(int i = 1; i < k; i++) {
			curr = curr->next;
		}
		Node* newHead = curr->next;
		last->next = head;
		curr->next = NULL;
		head = newHead;
	}
	void display() {
		Node* curr = head;
		while(curr != NULL) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
};
int main() {
	LinkedList list;
	list.insert(10);
	list.insert(20);
	list.insert(30);
	list.insert(40);
	list.insert(50);
	list.insert(60);
	cout << "Original list: ";
	list.display();
	list.rotateLeft(2);
	cout << "After rotation: ";
	list.display();
	return 0;
}
