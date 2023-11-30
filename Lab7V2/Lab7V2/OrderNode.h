#pragma once
#include <iostream>

using namespace std;

struct OrderNode
{
private:
    string orderItems[5] = { "","","","","" };

public:
    // Data items
    double subTotal;
    int itemCount;

    // Queue Pointers
    OrderNode *next;

    // Constructor
    OrderNode(OrderNode *n = NULL){
         next = n;
         subTotal = 0.0;
         itemCount = 0;
    }

    // Other Methods
    void AddItem(string item);
    string &operator[](int index);
    
};
