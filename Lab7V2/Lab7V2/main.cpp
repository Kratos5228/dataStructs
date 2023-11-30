#include <iostream>
#include "OrderQueue.h"

using namespace std;

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
