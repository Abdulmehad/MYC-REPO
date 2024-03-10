#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include<iostream>
using namespace std;
#include "node.h"
template<class T>
class BST
{
	private:
		
		Node<T> *head;
		
		void insert(T, Node<T> *);//add a new node where appropriate
		
		void preOrder(Node<T>*);
		
		void inOrder(Node<T>*);
		
		void postOrder(Node<T>*);		
		
		Node<T>* deleteNode(Node<T>*, T);
		
		void makeEmpty(Node<T> *);
	
		
		
		
	public:
		BST();//set head to null
		
		~BST();// ???
		
		void insert(T);//add a new node where appropriate
		
		void preOrder();//print the tree in pre order
		
		void inOrder();
		
		void postOrder();		
	
		void deleteNode(T);
		
		bool search(T);
			T findSmallest(Node<T>*);
			T findSmalest();
			T sumLeftNodes(Node<T>* );
			T sumLeftNodes();
			T findKthLargest(Node<T>* , int , int&);
			T findKthLargest(int ); 
			bool areIdentical(BST<T>&);
			bool areIdentical(Node<T>* , Node<T>* );
			Node<T>*insertData(T , Node<T> *);
			int countNodes(T, T);
			int countNodes(Node<T>*,T, T );
			int sumNodes(T , T );
			int sumNodes(Node<T>*,  T, T);
			int sumRightNodes();
			int sumRightNodes(Node<T>*);
			int sum=0;
			Node<T>*findLCA(Node<T>* ,int ,int) ;
			Node<T>*findLCA(int ,int );
			T findKsmallest(T );
			T findKsmallest(Node<T>*,T );
			int count=0;
			int countnodes();
			int countnodes(Node<T>* n);
			void deleteinrange(Node<T>* ,T ,T );
			void deleteinrange(T ,T );
		
};

#endif
