#include <iostream>
using namespace std;
template<class T>
class Node
{
	private:
		T data;
		Node<T>* nextPtr;
		
     public:
		Node(T);
		Node();
		T getData()const;
		Node<T>* getNextPtr()const;
		void setData(T);
		void setNextPtr(Node*);

};
template<class T>
Node<T>::Node(T a){
    data = a;
    nextPtr=NULL;
}
template<class T>
void Node<T>::setData(T a){
    data = a;
}
template<class T>
void Node<T>::setNextPtr(Node* p){
    nextPtr=p;
}
template<class T>
T Node<T>::getData()const{
    return data;
}
template<class T>
Node<T>* Node<T>::getNextPtr()const{
    return nextPtr;
}
template<class T>
class Queue{
    private:
    Node<T>* head;
    Node<T>* end;
    public:
    Queue(){
      head=NULL;  
      end=NULL;
    }
    void enqueue(T a){
    Node<T>* node = new Node<T>(a);
        if(head==NULL){
          head=node;
          end = node;
          return ;
        }
     Node<T>*str=head;
     while(str!=NULL){
     	if(a.getPriority()==str->getData().getPriority()){
     		node->setNextPtr(str->getNextPtr());
     		str->setNextPtr(node);
     		return ;
		 }
    if(node->getData().getPriority()<str->getData().getPriority()){
          T swap = str->getData();
          str->setData(a);
          node->setData(swap);
         }
         str = str->getNextPtr();
     }
     end->setNextPtr(node); end = node;
    }
    void dequeue(){
         if(isEmpty()){
            cout<<"Queue is Empty "<<endl; return ;
        }
        Node<T>* del;
        if(head!=NULL){
           del=head;
           head=head->getNextPtr();
           T value = del->getData();
           delete del;
        }
    }
    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        return false;
    }
    void print_queue(){
        if(isEmpty()){
            cout<<"Queue is Empty "<<endl; return ;
        }
        Node<T>* str=head;
        while(str!=NULL){
          str->getData().display();
          str=str->getNextPtr();
        }
    }
    
};
class Ticket{
  private:
    int ticketId,priority;
    string description;

 public:
 Ticket(){
 }
  Ticket(int id,int prior,string desc){
      ticketId=id; priority=prior; description=desc;
  }
  int getPriority(){
      return priority;
  }
  void display(){
      cout<<"Priority "<<priority<<endl;
     cout<<"Ticket Id "<<ticketId<<endl;
     cout<<"Description "<<description<<endl;
  }
};
int main() {
    Ticket t1 (123,4,"Issue2");
    Ticket t2 (124,1,"Issue1");
     Ticket t3 (125,2,"Issue4");
    Ticket  t4 (126,1,"Issue3");
    Queue<Ticket> q;
     q.enqueue(t1);
    q.enqueue(t2);
    q.enqueue(t3);
    q.enqueue(t4);
    q.print_queue();
    q.dequeue();
    cout<<"After Dequeue "<<endl;
    q.print_queue();
    

    return 0;
}