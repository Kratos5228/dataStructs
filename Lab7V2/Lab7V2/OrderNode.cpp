#include "OrderNode.h"

void OrderNode::AddItem(string item){
    if (itemCount < 5){
        orderItems[itemCount] = item;
        itemCount++;
    }
    else
    {
        throw string("Order full. Please begin another.\n\n");
    }
}

string& OrderNode::operator[](int index){
        if (index < 0 || index >= itemCount)
            throw string("Index out of range");
        else
            return orderItems[index];
}
