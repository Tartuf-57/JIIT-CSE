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
	Node* head;
	public:
	LinkedList() {
		head = nullptr;
	}
	void insertHead(int value) {
		Node* newNode = new Node(value);
		if (head==NULL){
			head=newNode;
		}
		else{
			Node* curr=head;
			while(curr->next!=NULL){
				curr=curr->next;
			}
			curr->next=newNode;
		}
	}
	void cnt() {
		Node * temp=head;
		float ans=0;
		int c=0;
		while(temp!=NULL){
			c++;
			ans+=temp->data;
			temp=temp->next;
		}
		cout<<"Total number of nodes are:"<<c<<" and the average is:"<<fixed<<setprecision(2)<<ans/c<<"\n";
	}
	void last(int x) {
		Node * temp=head;
		int c=0;
		while(temp!=NULL){
			c++;
			temp=temp->next;
		}
		temp=head;
		for (int i=0;i<c-x;i++){
			temp=temp->next;
		}
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<"\n";
	}
	void middle() {
		Node* fast=head;
		Node* slow=head;
		if(head==NULL){
			return;
		}
		while(fast!=NULL && fast->next!=NULL){
			fast=fast->next->next;
			slow=slow->next;
		}
		if(slow->data%2==0) {
			cout<<"The middle element "<<slow->data<<" is even"<<"\n";
		}
		else {
			cout<<"The middle element "<<slow->data<<" is odd"<<"\n";
		}
	}
	void insertN(int n) {
		int value;
		for (int i = 0; i < n; i++) {
			cout << "Enter data " << i + 1 << ": ";
			cin >> value;
			insertHead(value);
		}
	}
	void display(int m) {
		Node* temp = head;
		for (int i=0;i<m;i++){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<"\n";
	}
	void deleteNode(int info) {
		if (head == nullptr) {
			cout << "No such value exists\n";
			return;
		}
		if (head->data == info) {
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		Node* curr = head;
		Node* temp = head->next;
		while (temp != nullptr) {
			if (temp->data == info) {
				curr->next = temp->next;
				delete temp;
				return;
			}
			curr = temp;
			temp = temp->next;
		}
		cout << "No such value exists\n";
	}
	void interchangePairs(int a1, int a2, int b1, int b2) {
		if (head == NULL || head->next == NULL)
			return;
		Node *prev1 = NULL, *first1 = NULL;
		Node *prev2 = NULL, *first2 = NULL;
		Node *prev = NULL;
		Node *curr = head;
		while (curr && curr->next) {
			if (curr->data == a1 && curr->next->data == a2) {
				prev1 = prev;
				first1 = curr;
				break;
			}
			prev = curr;
			curr = curr->next;
		}
		prev = NULL;
		curr = head;
		while (curr && curr->next) {
			if (curr->data == b1 && curr->next->data == b2) {
				prev2 = prev;
				first2 = curr;
				break;
			}
			prev = curr;
			curr = curr->next;
		}
		if (first1 == NULL || first2 == NULL)
			return;
		if (first1 == first2)
			return;
		Node *second1 = first1->next;
		Node *after1 = second1->next;
		Node *second2 = first2->next;
		Node *after2 = second2->next;
		if (after1 == first2) {
			if (prev1)
				prev1->next = first2;
			else
				head = first2;
			second2->next = first1;
			second1->next = after2;
			first1->next = second2;
		}
		else if (after2 == first1) {
			if (prev2)
				prev2->next = first1;
			else
				head = first1;
			second1->next = first2;
			second2->next = after1;
			first2->next = second1;
		}
		else {
			if (prev1)
				prev1->next = first2;
			else
				head = first2;
			if (prev2)
				prev2->next = first1;
			else
				head = first1;
			second2->next = after1;
			second1->next = after2;
			swap(first1->next, first2->next);
		}
	}
};
int main() {
	LinkedList list;
	int n;
	cout << "Enter number of nodes: ";
	cin >> n;
	list.insertN(n);
	list.cnt();
	cout<<"Enter number of nodes to display: ";
	int m;
	cin>>m;
	list.display(m);
	list.middle();
	int x;
	cout<<"Enter the node number from last: ";
	cin>>x;
	list.last(x);
	int data;
	cout<<"Enter the data to delete";
	cin>>data;
	list.deleteNode(data);
	cout<<"The list after deletion:\n";
	list.display(4);
	list.interchangePairs(2,3,4,5);
	return 0;
}
