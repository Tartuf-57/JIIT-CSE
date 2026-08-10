#include <bits/stdc++.h>
using namespace std;
class Node {
	public:
	int coefficient;
	int power;
	Node* next;
	Node(int c, int p) {
		coefficient = c;
		power = p;
		next = NULL;
	}
};
class Polynomial {
	private:
	Node* head;
	public:
	Polynomial() {
		head = NULL;
	}
	void insert(int coefficient, int power) {
		Node* newNode = new Node(coefficient, power);
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
	void display() {
		Node* curr = head;
		while(curr != NULL) {
			cout << curr->coefficient << "x^" << curr->power;
			if(curr->next != NULL)
				cout << " + ";
			curr = curr->next;
		}
		cout << endl;
	}
	Polynomial add(Polynomial& p) {
		Polynomial result;
		Node* a = head;
		Node* b = p.head;
		while(a != NULL && b != NULL) {
			if(a->power == b->power) {
				result.insert(a->coefficient + b->coefficient, a->power);
				a = a->next;
				b = b->next;
			}
			else if(a->power > b->power) {
				result.insert(a->coefficient, a->power);
				a = a->next;
			}
			else {
				result.insert(b->coefficient, b->power);
				b = b->next;
			}
		}
		while(a != NULL) {
			result.insert(a->coefficient, a->power);
			a = a->next;
		}
		while(b != NULL) {
			result.insert(b->coefficient, b->power);
			b = b->next;
		}
		return result;
	}
};
int main() {
	Polynomial p1, p2, result;
	// 5x^3 + 4x^2 + 2
	p1.insert(5, 3);
	p1.insert(4, 2);
	p1.insert(2, 0);
	// 3x^3 + 2x^2 + 7x + 1
	p2.insert(3, 3);
	p2.insert(2, 2);
	p2.insert(7, 1);
	p2.insert(1, 0);
	cout << "Polynomial 1: ";
	p1.display();
	cout << "Polynomial 2: ";
	p2.display();
	result = p1.add(p2);
	cout << "Sum: ";
	result.display();
	return 0;
}
