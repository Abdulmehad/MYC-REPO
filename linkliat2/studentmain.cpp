#include<iostream>
#include "linklist.h"
#include "linklistpr.cpp"
//#include"student.cpp"
#include"node.h"
#include"nodepr.cpp"
using namespace std;

int main(){
	Student s1("Ashir",59,1023,905,23,0);
	Student s2("Ali",53,1023,905,23,0);
	Student s3("mehad",51,1006,985,23,20);
	Student s4("zain",3,1043,505,5,4);
	
	 Linklist<Student>ahm;
    ahm.addElement(s1);
    ahm.addElement(s2);
    ahm.addElement(s3);
    ahm.addElement(s4);
	cout<<ahm;
	ahm.meritlist(2);
	return 0;
}