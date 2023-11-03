#include <iostream>
using namespace std;

class ListNode{
public:
		int data;
		ListNode *next, *prev;

		ListNode(){
			this->data=0;
						next=NULL;
						prev=NULL;
		}

		ListNode(int data){
			this->data=data;
			next=NULL;
			prev=NULL;
		}
	};

class DoublyLinkedList{
public:
	ListNode *head;
	ListNode *tail;

	DoublyLinkedList(){
		head= NULL;
		tail= NULL;
	}

	void append(int data){
		if (!head){
			head= new ListNode(data);
			tail=head;
		}
		else{
			ListNode *nptr=new ListNode(data);
			tail->next=nptr;
			nptr->prev=tail;
			tail=nptr;
		}
	}
	~DoublyLinkedList(){
		while (!head) delete head;
	}

};

class BinaryNumber{
public:
	int len;
	DoublyLinkedList num;
	BinaryNumber(){
		len=0;
	}

	void enterNumber(){
		int n;
		cout<<"Enter no of bits you want to enter: ";
		cin >> n;
		cout<<"Please enter space separated bits from MSB to LSB"<<endl;

		for(int i=0;i<n;i++){
			int data;
			cin>>data;
			num.append(data);
		}
	}

	void displayNumber(){
		cout<<"The binary number is: "<<endl;
		auto nptr=num.head;
		while (nptr){
			cout<<nptr->data<<" ";
			nptr=nptr->next;
		}
		cout <<endl;
	}
};

int main(){
	BinaryNumber num1;
	num1.enterNumber();
	num1.displayNumber();
	return 0;
}
