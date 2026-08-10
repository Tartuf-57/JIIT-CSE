#include <iostream>
#include <vector>
using namespace std;
struct Node {
	char data;
	Node *next;
};
class LinkedList {
	private:
	Node *head;
	public:
	LinkedList() {
		head = NULL;
	}
	void insert(char ch) {
		Node *newNode = new Node;
		newNode->data = ch;
		newNode->next = NULL;
		if (head == NULL) {
			head = newNode;
			return;
		}
		Node *temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}
	void display() {
		Node *temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	Node* getHead() {
		return head;
	}
	void removeSequence(char a, char b, char c) {
		Node *prev = NULL;
		Node *curr = head;
		while (curr && curr->next && curr->next->next) {
			if (curr->data == a &&
				curr->next->data == b &&
				curr->next->next->data == c) {
				Node *first = curr;
				Node *second = curr->next;
				Node *third = second->next;
				Node *after = third->next;
				if (prev == NULL)
					head = after;
				else
					prev->next = after;
				delete first;
				delete second;
				delete third;
				return;
			}
			prev = curr;
			curr = curr->next;
		}
	}
};
int main() {
	LinkedList list1, list2;
	cout << "Enter 10 characters for first linked list:\n";
	for (int i = 0; i < 10; i++) {
		char ch;
		cin >> ch;
		list1.insert(ch);
	}
	cout << "Enter 5 characters for second linked list:\n";
	for (int i = 0; i < 5; i++) {
		char ch;
		cin >> ch;
		list2.insert(ch);
	}
	cout << "\nFirst List : ";
	list1.display();
	cout << "Second List: ";
	list2.display();
	vector<char> v;
	Node *temp = list2.getHead();
	while (temp) {
		v.push_back(temp->data);
		temp = temp->next;
	}
	for (int i = 0; i <= 2; i++) {
		list1.removeSequence(v[i], v[i + 1], v[i + 2]);
	}
	cout << "\nFirst list after removal:\n";
	list1.display();
	return 0;
}
