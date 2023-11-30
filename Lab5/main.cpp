#include <iostream>
#include <string>
#include <iomanip>
#include "StudentDatabase.h"

using namespace std;

int main() {
    
    StudentDatabase db;
    
    int userChoice;
    do{
    cout << "1. Load the Data" << endl;
    cout << "2. View the Data" << endl;
    cout << "3. Merge-Sort Algorithm" << endl;
    cout << "4. QuickSort Algorithm" << endl;
    cout << "5. Heap Sort Algorithm" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter Your choice: ";
    cin >> userChoice;
    cout << endl;
    switch(userChoice){
      case 1:
            cout << "Loading Data..." << endl;
            db.Read();
      break;
      
      case 2:
            db.display();
      break;
      
      case 3:
            cout << "Sorting Data..." << endl;
            db.mergeSort(0, db.getNum() - 1);
      break;
      
      case 4:
            cout << "Sorting Data..." << endl;
            db.quickSort(0, db.getNum() - 1);
      break;
            
      case 5:
            cout << "Sorting Data..." << endl;
            db.heapSort(db.getNum());
      break;
            
      case 6:
      break;
            
      default:
      cout << "Wrong Choice\n";
      break;
    }
        cout << endl;
    }while(userChoice != 6);
    
      return 0;
  }
