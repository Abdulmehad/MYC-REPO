#include<iostream>
#include <string>
using namespace std;
template<class T>
class Node{
public:
		T data;
		Node<T>* nextPtr;

Node(T a){
	data=a;
	nextPtr=NULL;
}	

T getData(){
	return data;
}

Node<T>* getNextPtr(){
	return nextPtr;
}
void setData(T a){
	data=a;
}
void setNextPtr(Node* n){
	nextPtr=n;
}
};
class ticket{
	public:
	int ticketid;
	string description;
	int priority;
	ticket(){
		
	}
	ticket(int ticket,string descript,int priorit){
		description=descript;
		ticketid=ticket;
		priority=priorit;
	}

	
void printdetails(){
    cout << "TICKET ID    || DESCRIPTION || PRIORITY" << endl;
    cout << ticketid << " || " << description << " || " << priority << endl;
}


	
};
class ticketqueue{
	public:
	Node<ticket>*front;
	Node<ticket>*rear;
	
	ticketqueue(){
	front=rear=NULL;
	}
void enqueue(ticket a) {
    Node<ticket>* n = new Node<ticket>(a);

    if (isempty()) {
        front = rear = n;
    } else if (a.priority < front->getData().priority) { // add at first
        n->setNextPtr(front);
        front = n;
    } else if (a.priority > rear->getData().priority) { // add at last
        rear->setNextPtr(n);
        rear = n;
    } else { // add at k position
        Node<ticket>* current = front;
        Node<ticket>* prev = NULL;

        while (current != NULL && current->getData().priority <= a.priority) {
            prev = current;
            current = current->getNextPtr();
        }

        if (prev != NULL) {
            prev->setNextPtr(n);
        } else {
            front = n;
        }

        n->setNextPtr(current);
    }
}
	void dequeue(){
		if(isempty()){
			cout<<"queue underflow";
			return;
		}
		Node<ticket>*todequeue=front;
		front=front->getNextPtr();
		delete todequeue;
		return;
	
		
	}
	bool isempty(){
		if(front==NULL){
			return true;
		}
		else 
		return false;
	}
	void getqueuesize(){
		Node<ticket>*current=front;
		int size=0;
		while(current!=NULL){
			size++;
			current=current->getNextPtr();
		}
		cout<<size;
	}
	void printqueue(){
		if(isempty()){
			cout<<"Queue is empty";
			return;
		}
		else{
		
		Node<ticket>*current=front;
		while(current!=NULL){
		current->getData().printdetails();
		cout<<endl;
		current=current->getNextPtr();
		
		}
	}}
};
int main(){

	ticketqueue ticketQueue;
	ticket ticket1(1, "Internet nahi", 2);
    ticket ticket2(2, "nstallation problem", 1);
    ticket ticket3(3, "xncns", 3);

    ticketQueue.enqueue(ticket1);
    ticketQueue.enqueue(ticket2);
    ticketQueue.enqueue(ticket3);
    ticketQueue.printqueue();
    ticketQueue.dequeue();
    cout<<"AFTER DCEQUEUING ONE TIME"<<endl;
    ticketQueue.printqueue();
    

    return 0;
}

