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
			head->prev=NULL;
			head->next=NULL;
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
		if(head==NULL){
			return;
		}
		Node* curr=head;
		while(curr!=NULL){
			cout<<curr->data<<" ";
			curr=curr->next;
		}
		cout<<"\n";
	}
	void divisible(int m){
		if(head==NULL){
			return;
		}
		Node* curr=head;
		while(curr!=NULL){
			if((curr->data)%m==0){
				cout<<curr->data<<" is divisible by "<<m<<"\n";
			}
			curr=curr->next;
		}
	}
	void deleteGreater(int x){
		Node* curr = head;
		while(curr != NULL){
			if(curr->data > x){
				Node* temp = curr;
				if(curr == head){
					head = curr->next;
					if(head != NULL)
						head->prev = NULL;
				}
				else{
					curr->prev->next = curr->next;
					if(curr->next != NULL)
						curr->next->prev = curr->prev;
				}
				curr = curr->next;
				delete temp;
			}
			else{
				curr = curr->next;
			}
		}
	}
	int countBetweenDuplicates(){
		Node* first = head;
		while(first != NULL){
			Node* curr = first->next;
			int count = 0;
			while(curr != NULL){
				if(curr->data == first->data){
					cout << "Number of elements between "
						 << first->data << " = "<< count << "\n";
					return count;
				}
				count++;
				curr = curr->next;
			}
			first = first->next;
		}
		cout << "No duplicate values found\n";
		return 0;
	}
};
int main() {
	LinkedList list;
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.display();
	list.divisible(3);
	list.deleteGreater(3);
	list.display();
	list.countBetweenDuplicates();
	return 0;
}
