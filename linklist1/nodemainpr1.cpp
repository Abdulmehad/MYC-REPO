#include"nodepr.cpp"
//using namespace std;
int main(){
	Node<int>* n1=new Node<int>(1);
	Node<int>* n2=new Node<int>(2);
	Node<int>* n3=new Node<int>(3);
	Node<int>* n4=new Node<int>(4);
	Node<int>* n5=new Node<int>(5);
	
	Node<int>* head = n1;
	Node<int>* current = head;
	
	n1->setNextPtr(n2);
	n2->setNextPtr(n3);
	n3->setNextPtr(n4);
	n4->setNextPtr(n5);
	n5->setNextPtr(NULL);
	
	
	
	while(current->getNextPtr()!=NULL){
		cout<<current->getData();
	    current=current->getNextPtr();
	    cout<<"->";
	}
     cout <<"NULL"<<endl;

	cout<< *n1;
	
}