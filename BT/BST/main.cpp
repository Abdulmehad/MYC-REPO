using namespace std;
#include<iostream>
#include "bst.h"
#include "bst.cpp"
#include "node.cpp"
#include "node.h"
int main() {

    BST<int> bst;
    Node<int>* Head=NULL;
    bst.insert(10);
    bst.insert(7);
    bst.insert(3);
    bst.insert(8);
    bst.insert(18);
    bst.insert(20);
    bst.insert(16);
    bst.insert(19);
    bst.insert(25);
    bst.insert(12);
    bst.insert(13);

   
    cout << "Original BST:" <<endl;
    cout << "In-order: ";
    bst.inOrder();
    cout << endl;
//
//     int nodesInRange = bst.countNodes(10, 25);
//    cout << "Number of nodes in the range " << nodesInRange <<endl;
// 
//
//
//    int sumInRange = bst.sumNodes(5, 20);
//    cout << "Sum of nodes in the range " << sumInRange << endl;
//    
//    cout<<bst.sumRightNodes();
//    cout<<bst.sumLeftNodes();
//    cout<<endl;
//    cout<< bst.findLCA(16,19)->getData()<<endl;
//    cout<<bst.countnodes();

    bst.deleteinrange(Head,10,3);
    bst.inOrder();
    cout<<bst.countnodes();
    
       return 0;
}