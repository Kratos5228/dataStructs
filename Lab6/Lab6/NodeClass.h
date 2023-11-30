#pragma once
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

/*
//Recursive Function for Length Linked List
template<class T>
int length(Node<T>* head){
    if (head == NULL)
        return 0;
    else
        return 1 + length(head->next);
}
    
//Recursive Function for Displaying Linked List
template<class T>
void display(Node<T>* head){
    if (head != NULL)
    {
        cout << head->data << endl;
        display(head->next);
    }
}
    
template<class T>
void Read(){
    ifstream inFile;
        
    inFile.open("/Users/ramonbernal/Desktop/Spring 22'/Lab6/Lab6/numbersUnsorted.txt");
        
    T score;
        
    if(!inFile){                            //if statement if the file is unable to open
        cout << "Error opening data file. Exiting Program." << endl;
    }
        
    while(!inFile.eof()){
        inFile >> score;
        inFile.ignore(100, '\n');
            
        addNode(score);
    }
        
    inFile.close();
}
