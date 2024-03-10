using namespace std;
#include<iostream>
#include "linklist.h"
#include"student.cpp"

template<class T>
Linklist<T> :: Linklist()
{
	counter = 0;
	head = NULL;
}


template<class T>	
void Linklist<T> :: addElement(T a)
{
    Node<T>* node = new Node<T>(a);

    if (counter == 0) {
        head = node;
        counter++;
        return;
    }

    counter++;
    Node<T>* current = head;
    Node<T>* previous = nullptr;

    while (current != nullptr && current->getData().returnagg() >= node->getData().returnagg()) {
        previous = current;
        current = current->getNextPtr();
    }

    // at the beginning
    if (previous == NULL) {
        node->setNextPtr(head);
        head = node;
    }
	else {
    // in the middle or end
        previous->setNextPtr(node);
        node->setNextPtr(current);
    }
}

template<class T>	
void Linklist<T> :: addElementAt(int ind, T a)
{
	Node<T> *temp = new Node<T>(a);
	
	
	if((ind <= 0) || (ind > counter+1))  
	{
		cout<<"invalid index";
	}
	else if(ind == 1)
	{
		
     	temp->setNextPtr(head);
		head = temp;
		counter++;
	}
	else if(ind == counter+1)// add at tail
	{
		Node<T> *current = head;
		while(current->getNextPtr() != NULL)
		{
			current = current->getNextPtr();
		}
		current->setNextPtr(temp);
		temp->setNextPtr(NULL);
		counter++;
		//return true;
	}
	else// add in middle
	{
		
		Node<T> *current = head;
		for(int i = 2; i < ind; i++)
		{
			current = current->getNextPtr();
		}
		temp->setNextPtr(current->getNextPtr());
		current->setNextPtr(temp);
		counter++;
		return ;
	}
}




template<class T>
void Linklist<T> :: deleteElementAt(int ind)
{
	if(head == NULL)
	{
		cout<<"empty list";
	}
	else if((ind <= 0) || (ind > counter+1))
	{
		cout<<"ivalid index";
	}
	else if(ind == 1)
	{
		Node<T> *current = head;
		head = current->getNextPtr();
		counter--;
		delete current;
		return ;
	}
	else if(ind == counter)
	{
		Node<T> *current = head;
		Node<T> *previous = NULL;
		while(current->getNextPtr() != NULL)
		{
			previous = current;
			current = current->getNextPtr();
		}
		previous->setNextPtr(NULL);
		counter--;
		delete current;
		return ;
	}
	else
	{
		Node<T> *current = head;
		Node<T> *previous = NULL;
		for(int i =1; i < ind; i++)
		{
			previous = current;
			current = current->getNextPtr();
		}
		previous->setNextPtr(current->getNextPtr());
		counter--;
		delete current;
		return ;
	}
}


template<class T>	
void Linklist<T> :: deleteElement(T d)
{
	
	if(head == NULL)
	{
		cout<<"empty list";
	}
	else if(d == (head->getData()))
	{
		Node<T> *current = head;
		head = head->getNextPtr();
		delete current;
		return ;
	}
	
	else
	{
		Node<T> *current = head;
		Node<T> *previous;
		while(current->getNextPtr() != NULL)
		{
			previous = current;
			current = current->getNextPtr();
			if(d == (current->getData()))
			{
				previous->setNextPtr(current->getNextPtr());
				counter--;
				delete current;
				return ;
			}
			
		}
	}
	 return ;
}

template<class T>	
void Linklist<T> :: findElement (T d) const
{
	if(head == NULL)
	{
		cout<<"empty List" ;
	}
	else if(d == (head->getData()))
	{
		return ;
	}
	else
	{
		Node<T> *current = head;
		while(current->getNextPtr() != NULL)
		{
			current = current->getNextPtr();
			if(d == (current->getData()))
			{
				return ;
			}
		}
	}
	
}


template<class T>	
T Linklist<T> :: getElementAT(int ind) const
{
	if(head == NULL)
	{
		return 0;
	}
	else if((ind <= 0) || (ind > counter))
	{
		return 0;
	}
	else if(ind == 1)
	{
		return (head->getData());
	}
	else
	{
		Node<T> *current = head;
		for(int i = 2; i <= ind; i++)
		{
			current = current->getNextPtr();
		}
		return (current->getData());
	}
}



template<class T>	
void Linklist<T> :: updateElementAt (int ind, T d)
{
	if(head == NULL)
	{
		cout<<"empty list";
	}
	else if((ind <= 0) || (ind > counter))
	{
		cout<<"invalid index ";
	}
	else if(ind == 1)
	{
		head->setData(d);
		return ;
	}
	else
	{
		Node<T> *current = head;
		for(int i = 2; i <= ind; i++)
		{
			current = current->getNextPtr();
		}
		current->setData(d);
		return ;
	}
}


template<class T>	
Linklist<T> ::~Linklist()
{
	makeEmpty();
}


template<class T>	
void Linklist<T> :: makeEmpty()
{
	if(head != NULL)
	{
		Node<T> *current = head;
		Node<T> *previous;
		while(current->getNextPtr() != NULL)
		{
			previous = current;
			current = current->getNextPtr();
			delete previous;
		}
		delete current;
		counter = 0;
		head = NULL;
	}
}

template <class U>
ostream& operator<<(ostream &out,const Linklist<U> &d)
{
	Node<U> *current = d.head;
	while(current != NULL)
	{
	    current->getData().info();
		cout<<endl;
		current = current->getNextPtr();
	}

	return out;
	
}

template<class T>
void Linklist<T>::bubbleSort() {
    if (head == NULL) {
        cout<<"LIST IS EMPTY";
        return;
    }

    int swapped;
    Node<T> *current;
    Node<T> *ptr1 = NULL;

    do {
        swapped = 0;
        current = head;

        while (current->getNextPtr() != NULL) {
            Node<T> *nextNode = current->getNextPtr();
                //swapping
            if (current->getData() > nextNode->getData()) {
           
                T temp = current->getData();
                current->setData(nextNode->getData());
                nextNode->setData(temp);

                swapped = 1;
            }

            current = current->getNextPtr();
        }

       
        ptr1 = current;

    } while (swapped);
}

template<class T>
void Linklist<T>::insertionSort() {
    if (head == NULL) {
       cout<<"empty listttt";
        return;
    }

    Node<T> *sorted = NULL; 
    Node<T> *current = head;
 
    
    while (current != NULL) {
           Node<T> *next = current->getNextPtr();
        if (sorted == NULL || current->getData() < sorted->getData()) {
     
            current->setNextPtr(sorted);
            sorted = current;
        } else {
            
            Node<T> *sortPtr = sorted;
            while (sortPtr->getNextPtr() != NULL && sortPtr->getNextPtr()->getData() < current->getData()) {
                sortPtr = sortPtr->getNextPtr();
            }

       
            current->setNextPtr(sortPtr->getNextPtr());
            sortPtr->setNextPtr(current);
        }

        
        current = next;
    }

 
    head = sorted;
}

template<class T>
void Linklist<T>::meritlist(int seats){

   cout<<"Students got selected are "<<endl;
   Node<T>* str = head;
   for(int i=1;i<=seats;i++){
str->getData().info();
cout<<endl; 
str=str->getNextPtr();
   }
}
