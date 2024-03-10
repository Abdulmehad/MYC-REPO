#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

template <class T>
class Queue {
private:
    Node<T>* front;
    Node<T>* back;

public:
    Queue();           // Constructor
    ~Queue();          // Destructor
    void enqueue(T a); // Enqueue operation
    void dequeue();    // Dequeue operation
    T peak();          // Return the front element
    bool empty();       // Check if the queue is empty
    void printqueue();  // Print the queue
};

#include "queue.cpp"  // Include the implementation file

#endif // QUEUE_H
