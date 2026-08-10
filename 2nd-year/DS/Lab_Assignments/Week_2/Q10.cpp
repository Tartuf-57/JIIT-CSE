#include <bits/stdc++.h>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	Node(int value){
		data = value;
		next = NULL;
	}
};
class LinkedList{
	private:
	Node* head;
	public:
	LinkedList(){
		head = NULL;
	}
	void insert(int value){
		Node* newNode = new Node(value);
		if(head == NULL){
			head = newNode;
			return;
		}
		Node* curr = head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = newNode;
	}
	void removeDuplicates(){
		if(head == NULL)
			return;
		Node* curr = head;
		while(curr->next != NULL){
			if(curr->data == curr->next->data){
				Node* temp = curr->next;
				curr->next = temp->next;
				delete temp;
			}
			else{
				curr = curr->next;
			}
		}
	}
	void display(){
		Node* curr = head;
		while(curr != NULL){
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
};
int main(){
	LinkedList list;
	list.insert(1);
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(3);
	list.insert(3);
	list.insert(5);
	list.insert(5);
	list.insert(8);
	cout << "Before: ";
	list.display();
	list.removeDuplicates();
	cout << "After: ";
	list.display();
	return 0;
}
