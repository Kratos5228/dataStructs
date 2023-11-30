#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

template<class T>
struct Node{
    
    T data;
    Node *next;
    
    Node(T d, Node *p = NULL){
        data = d;
        next = p;
    }
};

template<class T>
void deleteNode(T newData, Node<T>*& listHead){
    Node<T> *temp = listHead, *prev = NULL;
    
    if (temp != NULL && temp->data == newData) {
            listHead = temp->next;
            delete temp;
            return;
        }
    
        while (temp != NULL && temp->data != newData) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL){
            cout << "Cannot Find Number Choosen!!" << endl;
            return;
        }
    
        prev->next = temp->next;
        delete temp;
}

template<class T>
void addNode(T newData, Node<T>*& listHead){
    
    Node<T> *newNode, *current;
    
    newNode = new Node<T>(newData);
    
    if (listHead == NULL || listHead->data >= newNode->data){
            newNode->next = listHead;
            listHead = newNode;
        }
        else {
            current = listHead;
            while (current->next != NULL && current->next->data < newNode->data)
                current = current->next;

            newNode->next = current->next;
            current->next = newNode;
        }
}

template<class T>
bool searchNode(T newData, Node<T>*& listHead){
    Node<T>* curr = listHead;
        while (curr != NULL) {
            if (curr->data == newData) {
                return true;
            }
            curr = curr->next;
        }
        return false;
}

void read(Node<double>*& listHead){
    
    ifstream inFile;
    inFile.open("/Users/ramonbernal/Desktop/Spring 22'/Lab6/Lab6/numbersUnsorted.txt");
    double score;
    if(!inFile){                            //if statement if the file is unable to open
        cout << "Error opening data file. Exiting Program." << endl;
    }
    while(!inFile.eof()){
        inFile >> score;
        inFile.ignore(100, '\n');
            
        addNode(score, listHead);
        
    }
    inFile.close();
    
}

template<class T>
void display(Node<T>* head)
{
    if (head != NULL)
    {
        cout << head->data << endl;
        display(head->next);
    }
}

template<class T>
int length(Node<T>* head)
{
    if (head == NULL)
        return 0;
    else
        return 1 + length(head->next);
}


int main() {
    
    int userChoice;
    Node<double> *listHead = NULL;
    read(listHead);
    double numData;
    
    do{
    cout << "1. Display Contents of Linked List" << endl;
    cout << "2. Display Length of Linked List" << endl;
    cout << "3. Add a New Element to Linked List" << endl;
    cout << "4. Delete Element from Linked List" << endl;
    cout << "5. Search Element in Linked List" << endl;
    cout << "0. Exit Program" << endl;
    cout << "Enter Your Choice: ";
    cin >> userChoice;
    cout << endl;
    switch(userChoice){
      
      case 1:
            cout << "Current List Contents: " << endl;
            display(listHead);
      break;
      
      case 2:
            cout << length(listHead) << endl;
      break;
      
      case 3:
            cout << "Enter a Number: ";
            cin >> numData;
            addNode(numData, listHead);
      break;
            
      case 4:
            cout << "Enter a Number: ";
            cin >> numData;
            deleteNode(numData, listHead);
      break;
        
      case 5:
            cout << "Search for a Number: ";
            cin >> numData;
            searchNode(numData, listHead)? cout << "Number Found\n" : cout << "Number Not Found\n";
      break;
      
      case 0:
      break;

      default:
      cout << "Wrong Choice\n";
      break;
    }
    cout << endl;

      }while(userChoice != 0);
    
    
    return 0;
}
