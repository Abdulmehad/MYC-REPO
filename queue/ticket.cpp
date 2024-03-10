#include"node.h"
//#include"nodepr.cpp"
#include<iostream>
using namespace std;
class ticket{
	public:
		ticket(){
		}
	ticket(int ticketid,string description,int priority){
		this->description=description;
		this->ticketid=ticketid;
		this->priority=priority;
	}
	int ticketid;
	string description;
	int priority;
void printdetails(){
    cout << "TICKET ID           DESCRIPTION             PRIORITY" << endl;
    cout << ticketid <<"\t     " << description <<"\t     "<< priority << endl;
}
	
	
	
};
