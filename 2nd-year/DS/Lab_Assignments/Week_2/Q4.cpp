#include <bits/stdc++.h>
using namespace std;
class Node {
	public:
	int data;
	Node* next;
	Node(int value) {
		data = value;
		next = nullptr;
	}
};
class LinkedList {
	private:
	Node* rear;
	Node* head;
	public:
	LinkedList() {
		head = nullptr;
		rear = nullptr;
	}
	void insert(int value) {
		Node* newNode = new Node(value);
		if (head==NULL){
			rear=newNode;
			head=newNode;
			rear->next=head;
		}
		else{
			Node* curr=head;
			while(curr->next!=head){
				curr=curr->next;
			}
			curr->next=newNode;
			rear=newNode;
			rear->next=head;
		}
	}
	void display() {
		if (head==NULL){
			cout<<"Nothing to display\n";
		}
		if (head->next==head){
			cout<<head->data<<"\n";
			return;
		}
		cout<<head->data<<" ";
		Node * curr=head->next;
		while (curr!=head){
			cout<<curr->data<<" ";
			curr=curr->next;
		}
		cout<<"\n";
	}
	int cnt() {
		Node * temp=head;
		int c=1;
		while(temp!=rear){
			c++;
			temp=temp->next;
		}
		return c;
	}
	void hasNegative() {
		if (head == NULL) {
			cout << "List is empty.\n";
			return;
		}
		Node* curr = head;
		do {
			if (curr->data < 0) {
				cout << "Negative value found: " << curr->data << endl;
				return;
			}
			curr = curr->next;
		} while (curr != head);
		cout << "No negative values found.\n";
	}
	void countGreaterThan15() {
		if (head == NULL) {
			cout << "List is empty.\n";
			return;
		}
		int count = 0;
		Node* curr = head;
		do {
			if (curr->data > 15)
				count++;
			curr = curr->next;
		} while (curr != head);
		cout << "Number of nodes with value greater than 15: " << count << endl;
	}
	void deleteNode(int value) {
		Node *curr = head;
		Node *prev = rear;
		while (curr->data != value) {
			prev = curr;
			curr = curr->next;
		}
		if (head == rear) {
			delete head;
			head = rear = NULL;
		}
		else if (curr == head) {
			head = head->next;
			rear->next = head;
			delete curr;
		}
		else if (curr == rear) {
			prev->next = head;
			rear = prev;
			delete curr;
		}
		else {
			prev->next = curr->next;
			delete curr;
		}
		cout << "Element deleted successfully.\n";
	}
	void updateValue(int oldValue, int newValue) {
		Node* curr = head;
		while (curr->data != oldValue)
			curr = curr->next;
		curr->data = newValue;
		cout << "Element updated successfully.\n";
	}
	void insertn(int a,int b,int c){
		if(a==b+1){
			insert(c);
			return;
		}
		if(a==1){
			Node* newNode = new Node(c);
			Node* temp=rear;
			temp->next=newNode;
			temp->next=head;
			head=temp;
			return;
		}
		Node* curr=head;
		for (int i=1;i<a-1;i++){
			curr=curr->next;
		}
		Node* newNode = new Node(c);
		Node* temp=curr->next;
		curr->next=newNode;
		curr=curr->next;
		curr->next=temp;
	}
};
int main(){
	LinkedList list;
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.display();
	cout<<"Numbers of nodes are:"<<list.cnt()<<"\n";
	list.insertn(4,list.cnt(),10);
	list.display();
	list.hasNegative();
	list.updateValue(10, 16);
	list.countGreaterThan15();
	list.deleteNode(3);
	return 0;
}
