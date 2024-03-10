using namespace std;
#include<iostream>
#include "bst.h"
template<class T>
BST<T> :: BST()
{
	head = NULL;
}
template<class T>
BST<T> :: ~BST()
{
	if(head != NULL)
	{
		makeEmpty(head->getLeftPtr());
		delete head->getLeftPtr();
		makeEmpty(head->getRightPtr());
		delete head->getRightPtr();
		delete head;
	}
}
template<class T>
void BST<T> :: makeEmpty(Node<T> *head)
{
	if(head != NULL)
	{
		makeEmpty(head->getLeftPtr());
		delete head->getLeftPtr();
		makeEmpty(head->getRightPtr());
		delete head->getRightPtr();
	}
}
template<class T>
void BST<T> :: insert(T data)   //setting first three nodes   5
//                                                           / \
//                                                          3   9 
{
	if(head == NULL)
	{
		head = new Node<T>(data);
	}
	else
	{
		if(head -> getData() > data)
		{
			if(head->getLeftPtr() == NULL)
				head->setLeftPtr(new Node<T>(data));	
			
			else
				insert(data, head->getLeftPtr());
		}
		else
		{
			if(head->getRightPtr() == NULL)
				head->setRightPtr(new Node<T>(data));	
			
			else
				insert(data, head->getRightPtr());
		}
	}
	
	
}
template<class T>
void BST<T> :: insert(T data, Node<T> *head)
{
	if(head -> getData() > data)
	{
		if(head->getLeftPtr() == NULL)
			head->setLeftPtr(new Node<T>(data));	
		
		else
			insert(data, head->getLeftPtr());
	}
 	else
	{
		if(head->getRightPtr() == NULL)
			head->setRightPtr(new Node<T>(data));	
		
		else
			insert(data, head->getRightPtr());
	}
}
template<class T>
Node<T>* BST<T> :: insertData(T data, Node<T> *root){
	if(root==NULL){
		return new Node<T>*(data);
	}
	if(data<root->geData()){
		root->setLeftPtr(insertData(data,root->getLeftPtr()));
	}
	else{
		//insert at right
		root->setRightPtr(insertData(data,root->getRightPtr()));
	}
	return root;
}
template<class T>
void BST<T> :: preOrder()
{
	if(head != NULL)
	{
		cout << head->getData() << " ";
		preOrder(head->getLeftPtr());
		preOrder(head->getRightPtr());
	}
}

template<class T>
void BST<T> :: preOrder(Node<T> *head)
{
	if(head != NULL)
	{
		cout << head->getData() << " ";
		preOrder(head->getLeftPtr());
		preOrder(head->getRightPtr());
	}
}
template<class T>
void BST<T> :: inOrder()
{
	if(head != NULL)
	{
		inOrder(head->getLeftPtr());
		cout << head->getData() << " ";
		inOrder(head->getRightPtr());
	}
}

template<class T>
void BST<T> :: inOrder(Node<T> *head)
{
	if(head != NULL)
	{
		inOrder(head->getLeftPtr());
		cout << head->getData() << " ";
		inOrder(head->getRightPtr());
	}
}

template<class T>
void BST<T> :: postOrder()
{
	if(head != NULL)
	{
		postOrder(head->getLeftPtr());
		postOrder(head->getRightPtr());
		cout << head->getData() << " ";
	}
}

template<class T>
void BST<T> :: postOrder(Node<T> *head)
{
	if(head != NULL)
	{
		postOrder(head->getLeftPtr());
		postOrder(head->getRightPtr());
		cout << head->getData() << " ";
	}
}

template<class T>
void BST<T> :: deleteNode(T key)
{	
	if(head == NULL)
	{
		return;
	}
	if(head->getData() > key)
	{
		head->setLeftPtr(deleteNode(head->getLeftPtr(), key));
	}
	
	if(head->getData() < key)
	{
		head->setRightPtr(deleteNode(head->getRightPtr(), key));
	}
	
	if(head->getData() == key)
	{
		Node<T>* temp = head;
		if((head->getLeftPtr() == NULL) && (head->getRightPtr() == NULL))
		{
			head = NULL;
			delete temp;
		}
		else if((head->getLeftPtr() == NULL) && (head->getRightPtr() != NULL))
		{
			head = head->getRightPtr();
			delete temp;
			
		}
		else if((head->getLeftPtr() != NULL) && (head->getRightPtr() == NULL))
		{
			head = head->getLeftPtr();
			delete temp;
		}
		else
		{
			Node<T>* temp1 = temp;
			temp = temp->getRightPtr();
			while(temp->getLeftPtr() != NULL)
			{
				temp = temp->getLeftPtr();
			}
			head->setData(temp->getData());
			temp1->setRightPtr(deleteNode(temp1->getRightPtr(), temp->getData()));
		}
	}
}
template<class T>
Node<T>* BST<T> :: deleteNode(Node<T> *head, T key)
{

	if(head == NULL)
	{
		return NULL;
	}
	if(head->getData() > key)
	{
		head->setLeftPtr(deleteNode(head->getLeftPtr(), key));
		return head;
	}
	if(head->getData() < key)
	{
		head->setRightPtr(deleteNode(head->getRightPtr(), key));
		return head;
	}
	
	if(head->getData() == key)
	{
		Node<T>* temp = head;
		if((head->getLeftPtr() == NULL) && (head->getRightPtr() == NULL))
		{
			delete temp;
			return NULL;
		}
		else if((head->getLeftPtr() == NULL) && (head->getRightPtr() != NULL))
		{
 			Node<T> *temp1 = head->getRightPtr();
			delete temp;
			return temp1;
		}
		else if((head->getLeftPtr() != NULL) && (head->getRightPtr() == NULL))
		{
			Node<T> *temp1 = head->getLeftPtr();
			delete temp;
			return temp1;
		}
		else
		{
			Node<T>* temp1 = temp;
			temp = temp->getRightPtr();
			while(temp->getLeftPtr() != NULL)
			{
				temp = temp->getLeftPtr();
			}
			head->setData(temp->getData());
			temp1->setRightPtr(deleteNode(temp1->getRightPtr(), temp->getData()));
			return head;
		}
	}
}

template<class T>
bool BST<T> :: search(T data)
{
	Node<T> *temp = head;
	
	while(temp != NULL)
	{
		if(temp->getData() == data)
			return true;
		else
		{
			if(temp->getData() > data)
				temp = temp->getLeftPtr();
			else
				temp = temp->getRightPtr();
		}
	}
	return false;
}
template<class T>
T BST<T>::findSmalest() {
    if (head == nullptr) {
    	cout<<"empty tree";
        return T();
    }
   
    return findSmallest(head);
}
template<class T>
T BST<T>::findSmallest(Node<T>* node) {
    if (node->getLeftPtr() == nullptr) {
        return node->getData();
    } else {
        return findSmallest(node->getLeftPtr());
    }
}
template<class T>
T BST<T>::sumLeftNodes() {
    return sumLeftNodes(head->getLeftPtr());
}

template<class T>
T BST<T>::sumLeftNodes(Node<T>* node) {
    if (node == nullptr) {
        return 0;
    } else {
        return node->getData() + sumLeftNodes(node->getLeftPtr());
    }
}

template<class T>
bool BST<T>::areIdentical(BST<T>& otherTree) {
    return areIdentical(head, otherTree.head);
}

template<class T>
bool BST<T>::areIdentical(Node<T>* node1, Node<T>* node2) {
    if (node1 == nullptr && node2 == nullptr) {
        return true;
    }

    if (node1 != nullptr && node2 != nullptr) {
        return (
            node1->getData() == node2->getData() &&
            areIdentical(node1->getLeftPtr(), node2->getLeftPtr()) &&
            areIdentical(node1->getRightPtr(), node2->getRightPtr())
        );
    }

    return false;
}
template<class T>
T BST<T>::findKthLargest(int k) {
    int count = 0;
    return findKthLargest(head, k, count);
}

template<class T>
T BST<T>::findKthLargest(Node<T>* node, int k, int& count) {
    if (node == nullptr || count >= k) {
        return T(); 
    }

  
    T rightResult = findKthLargest(node->getRightPtr(), k, count);

   
    if (count < k) {
        count++;
        if (count == k) {
            return node->getData(); 
        }

       
        return findKthLargest(node->getLeftPtr(), k, count);
    }

    return rightResult;
}

template <class T>
int BST<T>::sumNodes( T low,T high){
    return sumNodes(head, low, high);
}

template <class T>
int BST<T>::sumNodes(Node<T>* node,  T low, T high) {
    if (node == nullptr) {
        return 0;
    }

    T sum = 0;

    if (node->getData() >= low && node->getData() <= high) {
        sum = node->getData();
    }

    sum += sumNodes(node->getLeftPtr(), low, high);
    sum += sumNodes(node->getRightPtr(), low, high);

    return sum;
}
template <class T>
int BST<T>::countNodes(T low, T high) {
    return countNodes(head, low, high);
}

template <class T>
int BST<T>::countNodes(Node<T>* node,  T low, T high){
    if (node == nullptr) {
        return 0;
    }

    int count = 0;

    if (node->getData() >= low && node->getData()<= high) {
        count = 1;
    }

    count += countNodes(node->getLeftPtr(), low, high);
    count += countNodes(node->getRightPtr(), low, high);

    return count;
}
template <class T>
int BST<T>::sumRightNodes(){
    return sumRightNodes(head->getRightPtr());
}
template <class T>
int BST<T>::sumRightNodes(Node<T>* n){
	if(n==NULL){
		return 0;
	}

	sum+=n->getData();
	sumRightNodes(n->getRightPtr());
	return sum;
	
}
template<class T>
Node<T>* BST<T>::findLCA(int k1,int k2){
	return findLCA(head,k1,k2);
}
template<class T>
Node<T>* BST<T>::findLCA(Node<T>* n,int k1,int k2){
	if(n==NULL){	
	return 0;
	}
	
	if(k1>n->getData()&&k2>n->getData()){     //its in left side
	return	findLCA(n->getRightPtr(),k1,k2);
	}
	
    if(k1<n->getData()&&k2<n->getData()){   // it is in right side
	return	findLCA(n->getLeftPtr(),k1,k2);
	}
	return n;
}
template<class T>
T BST<T>::findKsmallest(T a){
	return findKsmallest(head,a);
}
template<class T>
T BST<T>::findKsmallest(Node<T>* n,T k){
	int c;
	if(n==NULL || c<k){
		return nullptr;
	}
	
	findKsmallest(n->getLeftPtr(),k,c);
	c++;
	
	if(c==k){
		cout<<n->getData();
		return ;
	}
	
	return findKsmallest(n->getRightPtr(),k,c);
	
	
	
}
template<class T>
int BST<T>::countnodes(){
	return countnodes(head);
}
template<class T>
int BST<T>::countnodes(Node<T>* n){
	if(n==NULL){
		return 0;
	}
	countnodes(n->getLeftPtr());
	count++;
	countnodes(n->getRightPtr());
	return count;
}
template<class T>
void BST<T>::deleteinrange(T high,T low){
	return deleteinrange(head,high,low);
}
template<class T>
void BST<T>::deleteinrange(Node<T>* n,T high,T low){
	if(n==NULL){
		return ;
	}
	
	  if (n->getData() >= low && n->getData() <= high){
	  	T z=n->getData();
		deleteNode(z);
	}
	
	deleteinrange(n->getLeftPtr(),high,low);
	deleteinrange(n->getRightPtr(),high,low);
}


