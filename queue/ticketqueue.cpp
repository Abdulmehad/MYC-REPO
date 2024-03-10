//#include"node.h"
#include"nodepr.cpp"
#include"ticket.cpp"
#include<iostream>
using namespace std;
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
			current=current->getNextPtr();
		
		}
	}}
};
int main(){
	ticketqueue ticketQueue;
	ticket ticket1(1, "installation problem", 200);
    ticket ticket2(2, "installation problem", 4);
    ticket ticket3(3, "installation problem", 1);
    ticket ticket4(4, "installation problem", 5);
    ticket ticket5(5, "installation problem", 1);
    

    ticketQueue.enqueue(ticket1);
    ticketQueue.enqueue(ticket2);
    ticketQueue.enqueue(ticket3);
    ticketQueue.enqueue(ticket5);
    ticketQueue.enqueue(ticket4);
    ticketQueue.printqueue();


    return 0;
}