#include "OrderQueue.h"

void OrderQueue::enqueue(OrderNode*& n){
         OrderNode* newData;
         newData = new OrderNode();
         
         int choice;
         
         do{
              cout << "Select an Item: " << endl;
              cout << "1) Coffee -      $2.99" << endl;
              cout << "2) Tea -         $2.59"<< endl;
              cout << "3) Soft Drink -  $1.49" << endl;
              cout << "4) Water -       $0.99" << endl;
              cout << "5) No Other Items" << endl;
              cout << ">>";
              cin >> choice;
              cout << endl;
              switch(choice){
              case 1:
                        try{
                             newData->AddItem("Coffee");
                             newData->subTotal += + 2.99;
                        }catch(string message){
                             cout << message << endl;
                        }
              break;
                   
              case 2:
                        try{
                             newData->AddItem("Tea");
                             newData->subTotal += 2.59;
                        }catch(string message){
                             cout << message << endl;
                        }
              break;
                   
              case 3:
                        try{
                             newData->AddItem("Soft Drink");
                             newData->subTotal += 1.49;
                        }catch(string message){
                             cout << message << endl;
                        }
              break;
                   
              case 4:
                        try{
                             newData->AddItem("Water");
                             newData->subTotal += 0.99;
                        }catch(string message){
                             cout << message;
                        }
              break;
              
              case 5:
                        cout << "Order Placed.\n" << endl;
              break;
                        
              default:
              cout << "Wrong Choice\n\n";
              break;
              }
         }while(choice != 5);
         if (front == NULL ){
              front = newData;
              rear = newData;
             }
             else{
                  rear->next = newData;
                  rear = rear->next;
             }
}

void OrderQueue::dequeue(OrderNode*& n){
    if(isEmpty()){
        throw string("Queue is Empty\n\n");
    }else{
         n = front;
         front = front->next;
    }
}

bool OrderQueue::isEmpty(){
    if(front == NULL){
        return true;
    }else
        return false;
}

void OrderQueue::display(OrderNode* n){
    if (n != NULL){
        cout << "Order Subtotal: $" << n->subTotal << endl;
        display(n->next);
    }
}
