#include "node.h"
#include "nodepr.cpp"
#include<iostream>
#include <cctype>
using namespace std;
template<class T>
class stack{
	public:
	Node<T>*top;
	stack(){
		top=NULL;
	}
T getTop(){
    if(top == NULL){
       // cout << "STACK IS EMPTY";
        return T();
    }
    else{
//        cout << top->getData();
        return top->getData();
    }
}

	bool isEmpty(){
		if(top==NULL){
			return true;
		}
		else 
		return false;
	}
	
	void push(T d){
		Node<T>*n=new Node<T>(d);
		if(n==NULL){
			cout<<"STACK OVERFLOW";
		}
		else{
			n->setNextPtr(top);
			top=n;
		}
	}
	void pop(){
		if(isEmpty()){
			cout<<"STACK UNDERFLOW";
		}
		else{
			Node<T>*n=top;
			top=top->getNextPtr();
		//	T x= n->getData();
			delete n;
		//	return x;
		}
	}
	


};
template<class T>
void palindrome(T t){
	    stack<char>chstack;
	    int l=t.length();
	    int mid=l/2;
		for(int i=0;i<mid;i++){
	    chstack.push(t[i]);
		}
		for(int j=(mid+1);j<l;j++){	
			if(t[j]==chstack.getTop()){
				chstack.pop();
			}
			else{
			
			cout<<"its not a palindrome";
			return;
			}
		}
			cout<<"ITS A PALINDROME";
	}
	template<class T>
	T reverse(T d){
		T reversedmessage;
			string t=" ";
		stack<char>puncstack;
		stack<string>stringstack;
		for(char c:d){
			if(ispunct(c)){
			puncstack.push(c);
			}
			else if((c>='a' && c<='z') || (c>='A' && c<='Z')){	
					t+=c;
			}
        	else{
					stringstack.push(t);
					  t = " ";
				}
		}
		if (!t.empty()) {
        stringstack.push(t);
    }
    
		//for printing
		while(stringstack.isEmpty()!=true){
			reversedmessage+=stringstack.getTop();
			stringstack.pop();
		}
		while(puncstack.isEmpty()!=true){
			reversedmessage+=puncstack.getTop();
			puncstack.pop();
		}
		return reversedmessage;
	}
int main(){


    stack<string>tack;
    tack.push("heleh");
   palindrome(string("12321"));
   cout<<endl;
     string reversedMessage = reverse(string("Kindness, is what thatity!"));
    cout << "Reversed Message: " << reversedMessage << endl;
	return 0;

}