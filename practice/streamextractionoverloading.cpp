#include<iostream>
using namespace std;

class A{
public:
	int age;
	string name;
		
	A(int x,string nam){
		age=x;
		name=nam;
	}
	friend ostream& operator <<(ostream& output,A& obj);
};
ostream& operator <<(ostream& output,A& obj){
output<<obj.name<<" "<<obj.age;
	return output;
}
istream& operator >>(istream& in,A& obj){
	cin>>obj.name>>obj.age;
	return in;
}

int main(){
	A obj1(2,"abdul");
	cin>>obj1;
	cout<<obj1;
}