#include <iostream>
using namespace std;
class Student{
    private:
    string name;int roll;
double matric,inter,test,interview,aggregate;
  public:
  Student(){}
  Student(string n,int r,double m,double i,double t,double in){
     name=n;
	 roll=r;
	 matric=m;
	 inter=i;
     test=t;
	 interview=in;
     calculateagg();
   }
   void calculateagg(){
   aggregate=(0.4*matric/1100*100)+(0.10*inter/1100*100)+(0.30*test/30*100)+(0.20*interview/20*100);
   }
   double returnagg(){
       return aggregate;
   }
   string getName(){
       return name;
   }
   void info(){
     cout<<"Name: "<<name<<" Roll no. "<<roll<<" Aggregate: "<<aggregate<<endl;
   }
};