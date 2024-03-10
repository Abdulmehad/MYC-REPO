#include<iostream>
#include"node.h"
using namespace std;
template<class T>
Node<T>::Node(T a){
	data=a;
	nextPtr=NULL;
}	
template<class T>
T Node<T>::getData()const{
	return data;
}
template<class T>
Node<T>* Node<T>::getNextPtr()const{
	return nextPtr;
}
template<class T>
void Node<T>::setData(T a){
	data=a;
}
template<class T>
void Node<T>::setNextPtr(Node* n){
	nextPtr=n;
}

template<class v>
 ostream &operator<<(ostream& output, Node<v>& n){
		cout<<(n.getData());
		return output;
	}


