#include <bits/stdc++.h>
using namespace std;
class Node{
	public:
	int data;
	Node* prev;
	Node* next;
	Node(int value){
		data=value;
		next=NULL;
		prev=NULL;
	}
};
class LinkedList{
	private:
	Node* head;
	public:
	LinkedList(){
		head=NULL;
	}
	void insert(int value){
		Node* newNode=new Node(value);
		if(head==NULL){
			head=newNode;
			return;
		}
		Node* curr=head;
		while(curr->next!=NULL){
			curr=curr->next;
		}
		curr->next=newNode;
		newNode->prev=curr;
	}
	void display(){
		Node* curr=head;
		while(curr!=NULL){
			cout<<curr->data<<" ";
			curr=curr->next;
		}
		cout<<"\n";
	}
	void ExtremeSwap(){
		if(head == NULL || head->next == NULL)
			return;
		Node* left = head;
		Node* right = head;
		while(right->next != NULL){
			right = right->next;
		}
		while(left != right && left->prev != right){
			swap(left->data, right->data);
			left = left->next;
			right = right->prev;
		}
	}
};
int main(){
	LinkedList list;
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.insert(6);
	list.insert(7);
	list.insert(8);
	cout<<"Original: ";
	list.display();
	list.ExtremeSwap();
	cout<<"After 1st call: ";
	list.display();
	list.ExtremeSwap();
	cout<<"After 2nd call: ";
	list.display();
	list.ExtremeSwap();
	cout<<"After 3rd call: ";
	list.display();
	list.ExtremeSwap();
	cout<<"After 4th call: ";
	list.display();
	return 0;
}
