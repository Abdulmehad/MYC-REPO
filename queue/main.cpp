#include"queue.h"
#include<iostream>
using namespace std;
int main(){
    queue<int> q1;
    q1.enqueue(12);
    q1.enqueue(2);
    q1.enqueue(42);
    q1.printqueue();
    cout<<endl;
    q1.dequeue();
    q1.printqueue();
   
}
