#include <iostream>
#include <string>
using namespace std;
struct Node {
	string data;
	Node* next;
};
class LinkedList {
	private:
	Node* head;
	public:
	LinkedList() {
		head = NULL;
	}
	void insert(string value) {
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = NULL;
		if (head == NULL) {
			head = newNode;
			return;
		}
		Node* curr = head;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = newNode;
	}
	void printList() {
		if (head == NULL) {
			cout << "List is empty.\n";
			return;
		}
		Node* curr = head;
		while (curr != NULL) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
	void printStartingWith(char ch) {
		Node* curr = head;
		bool found = false;
		while (curr != NULL) {
			if (!curr->data.empty() && curr->data[0] == ch) {
				cout << curr->data << endl;
				found = true;
			}
			curr = curr->next;
		}
		if (!found)
			cout << "No string starts with '" << ch << "'." << endl;
	}
	void searchString(string key) {
		Node* curr = head;
		while (curr != NULL) {
			if (curr->data == key) {
				cout << "\"" << key << "\" exists in the linked list.\n";
				return;
			}
			curr = curr->next;
		}
		cout << "\"" << key << "\" does not exist in the linked list.\n";
	}
	void longestString() {
		if (head == NULL) {
			cout << "List is empty.\n";
			return;
		}
		Node* curr = head;
		string longest = curr->data;
		while (curr != NULL) {
			if (curr->data.length() > longest.length())
				longest = curr->data;
			curr = curr->next;
		}
		cout << "Longest string: " << longest
			 << " (Length = " << longest.length() << ")" << endl;
	}
	void containsXYZ() {
		Node* curr = head;
		bool found = false;
		while (curr != NULL) {
			if (curr->data.find("xyz") != string::npos) {
				cout << "\"" << curr->data
					 << "\" contains \"xyz\".\n";
				found = true;
			}
			curr = curr->next;
		}
		if (!found)
			cout << "No string contains \"xyz\".\n";
	}
	void swapPositions(int p1, int p2) {
		if (p1 == p2) {
			cout << "Both positions are the same.\n";
			return;
		}
		Node *node1 = NULL, *node2 = NULL;
		Node* curr = head;
		int pos = 1;
		while (curr != NULL) {
			if (pos == p1)
				node1 = curr;
			if (pos == p2)
				node2 = curr;
			curr = curr->next;
			pos++;
		}
		if (node1 == NULL || node2 == NULL) {
			cout << "Error: One or both positions do not exist.\n";
			return;
		}
		swap(node1->data, node2->data);
		cout << "Strings interchanged successfully.\n";
	}
};
int main() {
	LinkedList list;
	list.insert("apple");
	list.insert("banana");
	list.insert("xyzabc");
	list.insert("orange");
	list.insert("grapexyz");
	list.insert("mango");
	list.insert("apricot");
	cout << "Original Linked List:\n";
	list.printList();
	cout << "\n(a) Print all nodes:\n";
	list.printList();
	cout << "\n(b) Strings starting with 'a':\n";
	list.printStartingWith('a');
	cout << "\n(c) Search for \"orange\":\n";
	list.searchString("orange");
	cout << "\nSearch for \"kiwi\":\n";
	list.searchString("kiwi");
	cout << "\n(d) Longest string:\n";
	list.longestString();
	cout << "\n(e) Strings containing \"xyz\":\n";
	list.containsXYZ();
	cout << "\n(f) Swap positions 2 and 6:\n";
	list.swapPositions(2, 6);
	cout << "Updated Linked List:\n";
	list.printList();
	cout << "\nAttempting to swap positions 7 and 10:\n";
	list.swapPositions(7, 10);
	return 0;
}
