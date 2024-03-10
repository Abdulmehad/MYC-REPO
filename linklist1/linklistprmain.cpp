#include"linklistpr.cpp"
#include "node.h"
#include "linklist.h"
#include "nodepr.cpp"
using namespace std;
int main(){
	Linklist<int> temp;
	temp.addElement(10);
	cout << temp << endl;
	
	temp.addElement(20);
	cout << temp << endl;
	
	temp.addElementAt(3,15);
	cout << temp << endl;

	cout << temp.getElementAT(2);
	cout<<endl; 
	cout<<temp;
	cout<<endl; 
	temp.bubbleSort();
	cout<<temp;
	temp.addElement(43);
	temp.addElement(34);
	temp.addElement(34);
	
	cout<<endl;
	 temp.insertionSort();
	cout<<temp;
    temp.removeduplicate();
    cout<<temp;


	
	return 0;
}
