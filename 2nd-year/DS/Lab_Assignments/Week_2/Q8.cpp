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
		while(curr != NULL) {
			if(curr->power == power) {
				curr->coefficient += coefficient;
				delete newNode;
				return;
			}
			curr = curr->next;
		}
		curr = head;
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
	Polynomial multiply(Polynomial& p) {
		Polynomial result;
		Node* a = head;
		while(a != NULL) {
			Node* b = p.head;
			while(b != NULL) {
				int coefficient = a->coefficient * b->coefficient;
				int power = a->power + b->power;
				result.insert(coefficient, power);
				b = b->next;
			}
			a = a->next;
		}
		return result;
	}
};
int main() {
	Polynomial p1, p2, result;
	// 2x^2 + 3x + 1
	p1.insert(2, 2);
	p1.insert(3, 1);
	p1.insert(1, 0);
	// 4x + 5
	p2.insert(4, 1);
	p2.insert(5, 0);
	cout << "Polynomial 1: ";
	p1.display();
	cout << "Polynomial 2: ";
	p2.display();
	result = p1.multiply(p2);
	cout << "Product: ";
	result.display();
	return 0;
}
