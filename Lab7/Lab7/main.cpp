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
    void AddItem(string item)
    {
        if (itemCount < 5)
        {
            orderItems[itemCount] = item;
            itemCount++;
        }
        else
        {
            throw string("Order full. Please begin another.\n\n");
        }
    }

    string &operator[](int index)
    {
        if (index < 0 || index >= itemCount)
            throw string("Index out of range");
        else
            return orderItems[index];
    }
};

class OrderQueue{
     public:
     OrderNode *front = NULL;
     OrderNode *rear = NULL;
     
     void enqueue(OrderNode*& n){
          
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
     
     void dequeue(OrderNode*& n){
          if(isEmpty()){
               throw string("Queue is Empty\n\n");
          }else{
               n = front;
               front = front->next;
          }
     }
     
     bool isEmpty(){
          if(front == NULL){
               return true;
          }else
               return false;
     }
     
     void display(){
          display(front);
          cout << endl;
     }
     
     void display(OrderNode* n){
          if (n != NULL)
          {
               cout << "Order Subtotal: $" << n->subTotal << endl;
               display(n->next);
          }
     }
};

int main() {
    
    int userChoice;
     
     OrderQueue q;
     OrderNode *list = NULL;
     string listItems;

     do{
          cout << "Drive-Thru Order " << endl;
          cout << "1. Take an Order" << endl;
          cout << "2. Close out an Order" << endl;
          cout << "3. Review pending Orders" << endl;
          cout << "4. Go home and self-isolate" << endl;
          cout << ">> ";
          cin >> userChoice;
          cout << endl;
          switch(userChoice){
               case 1:
                    q.enqueue(list);
               break;
                    
               case 2:
                    try{
                         q.dequeue(list);
                         cout << "This order consists of the following items: \n";
                         for(int i = 0; i < list->itemCount; i++){
                              cout << list->operator[](i) << endl;
                         }
                         cout << "The subtotal is $" << list->subTotal << "\n\n";
                         delete list;
                    }catch(string message){
                         cout << message << endl;
                    }
               break;
                    
               case 3:
                    q.display();
               break;
                    
               case 4:
               break;
                    
               default:
               cout << "Wrong Choice\n\n";
               break;
          }
     }while(userChoice != 4);
     
    return 0;
}
