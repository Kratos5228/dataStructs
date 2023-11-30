#pragma once
#include <iostream>
#include "OrderNode.h"

using namespace std;

class OrderQueue{
    public:
    OrderNode *front = NULL;
    OrderNode *rear = NULL;
     
    void enqueue(OrderNode*& n);
    void dequeue(OrderNode*& n);
    
    void display(OrderNode* n);
    void display(){
        display(front);
        cout << endl;
    }
    
    bool isEmpty();
};
