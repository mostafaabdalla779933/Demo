#include <iostream.h>
#include <conio.h>
#include <alloc.h>

class Node{

public:
		int data;
		Node *next;
		Node *perv;
};

class LinkedList{



	public:

		Node *start;
		Node *end;
		int size;

		LinkedList(){

			start = NULL;
			end = NULL;
			size = 0;
	}

		Node *searchOnNode(int key){

			


		}
		
		int deleteNode(int key){

		}


		void appendNode(Node *ele){


			if(start==NULL){
				start = end = ele;
				}


			else{
				ele->perv = end;

				end->next = ele;

				end = ele;


			}
			size++;

		}
		void insertNode(Node *ele){
			Node *temp = start;

			while(temp && (temp->data < ele-> data))

				temp = temp->next;





			if(!temp)
				appendNode(temp);


			else{


				if(temp == start){

					temp->perv = ele;
					ele->next = start;
					start = ele;


			}

				else{

					temp->perv->next = ele;

					ele->perv = temp->perv	;

					temp->perv = ele;

					ele->next = temp;






			}

			size++;


		}

	}


	



	void freeList(){

		while(start){

			deleteNode(start->data);

		}
		size = 0;


	}

	int getSize(){

		return size;

	}

	int isEmpty(){

		return start==NULL;


	}


	Node* getFirst(){

		if(isEmpty())
			return NULL;

		Node *temp = start;
		start = start->next;
		if(!start) end=NULL;

		temp->perv=temp->next=NULL;
		return temp;


	}

	Node* getLast(){

		if(isEmpty())
			return NULL;


		Node *temp = end;
		end = end->perv;

		if(!end)
			start = NULL;

		temp->perv = temp->next = NULL;
		return temp;
	}

	Node *peekFirst(){


		if(isEmpty())
			return NULL;


		Node* temp = new Node();
		*temp = *start;
		temp->perv = temp->next = NULL;

		return temp;
	}
	Node *peekLast(){


		if(isEmpty())
			return NULL;


		Node* temp = new Node();
		*temp = *end;
		temp->perv = temp->next = NULL;

		return temp;
	}


};


void main(){

	clrscr();

	int cont = 0,num;



	LinkedList list;




   //	Node *node2 = new Node();

   //	node2->data = 35;

	//list.appendNode(node);

	/*

	int size = list.getSize();


	cout<<"the size of linkedlist is: "<<size;

	*/


	while(cont==0){

	  clrscr();
		cout<<"The size is: "<<list.getSize()<<endl;
		cout<<"add"<<endl;
		cout<<"insert"<<endl;
		cout<<"delete"<<endl;
		cout<<"freeList"<<endl;
		cout<<"print"<<endl;
		//cout<<"update"<<endl;
		cout<<"exit"<<endl;

	char input = getch();

	clrscr();

	Node *node = new Node();

	  switch(input){

		case 'p':

			if(list.start==NULL){

				cout<<"The list is empty";
				getch();
				break;

			}


			cout<<"The elements in list is:"<<endl;

			for(Node *temp = list.start; temp != NULL; temp = temp->next){

				cout<<temp->data<<endl;


			}


			getch();
			break;

		case 'a':

			cout<<"Enter the value"<<endl;
			cin>>num;

			node->data = num;
			list.appendNode(node);
			break;
		case 'i':
			cout<<"Enter the value"<<endl;
			cin>>num;
			node->data = num;

			list.insertNode(node);
			break;

		case 'd':
			cout<<"Enter value you want deleted"<<endl;
			cin>>num;
			list.deleteNode(num);
			break;

		case 'f':

			list.freeList();
			break;

		case 'e':
			cont=1;
			break;
	}


	}

}


