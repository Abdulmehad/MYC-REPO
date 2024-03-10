#include "node.h"
#include "nodepr.cpp"
#include <iostream>
using namespace std;

template <class T>
class queue {
public:
    Node<T>* front;
    Node<T>* back;
    queue(){
    	front=NULL;
    	back=NULL;
	}

    void enqueue(T a) {
        Node<T>* n = new Node<T>(a);
        if (front == NULL) {
            front = back = n;
            return;
        } else {
            back->setNextPtr(n);
            back = n;
            return;
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "QUEUE UNDERFLOW";
            return;
        } else {
            Node<T>* todelete = front;
            front = front->getNextPtr();
            delete todelete;
            return;
        }
    }

    T peak() {
        return front->getData();
    }

    bool empty() {
        if (front == NULL) {
            return true;
        } else {
            return false;
        }
    }

    void printqueue() {
        Node<T>* p = front;
        while (p != NULL) {
            cout << p->getData() << "->";
            p = p->getNextPtr();
        }
        cout << "NULL" << endl;
    }
};
