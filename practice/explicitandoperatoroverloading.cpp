#include<iostream>
using namespace std;
class A{
	public:
		int age;
		int marks;
	explicit A(int b,int a)
	{
		age=b;
		marks=a;
	}
	friend A operator +(const A& other1,const A& other2){
	
		A result(other1.age+other2.age,other1.marks+other2.marks);
	    return result;
	}

};
int main(){
	A obj1(6,6);
//	A obj2=5;  //error
    A obj2(5,7);
    A obj3(4,6);
    obj3 = obj1 + obj2;
	cout<<obj3.age<<endl;
    cout<<obj3.marks<<endl;
	//cout<<obj2.age;
	return 0;
}