#include<iostream>
using namespace std;
class A{
	public:
		int age;
		int marks;
	 A(int b=0,int a=0):age(b),marks(a)
	{
	
	}
	A operator +(const A& rhs){
		A obj(2,3);
		obj.age=age+rhs.age;
		obj.marks=marks+rhs.marks;
		return obj;
	}
	A operator -(A ob){
		A obj(2,7);
		obj.age=age-ob.age;
		obj.marks=marks-ob.marks;
		return obj;
	}
	A operator -(){
		A obj(-age,-marks);
      return obj;
	 }
	
	A operator --(){
	A obj(--age,--marks);
		return obj;
	}
	};
	int main(){
	//	A obj2=5;  //error if it is explicit constructor
	A obj1(6,6);
    A obj2(5,7);
    A obj3(4,7);
    
       // A obj5=-obj2;
        A obj4=obj3+obj1+obj2; // A obj3 = obj1.operator:: + (obj2); // A obj4 = obj3.operator+(obj1).operator+(obj2);
        //A obj6=--obj2;
        A obj7=obj2-obj1;
        
	//cout<<obj4.age<<endl;
   // cout<<obj4.marks<<endl;
   //cout<<obj5.age<<endl;
   //cout<<obj5.marks<<endl;
         
        cout<<obj7.age<<endl;
        cout<<obj7.marks<<endl;

	return 0;
}