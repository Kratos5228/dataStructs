#include <iostream>

const int SIZE = 11;
using namespace std;

struct Node{
    char data;
    Node* next;
    
    Node(char l, Node* n = NULL){
        data = l;
        next = n;
    }
};

void insert(Node*& head, char l){
    Node* traverse = head;
    
    if( head == NULL){
        head = new Node(l);
    }else{
        while ( traverse->next != NULL){
            traverse = traverse->next;
        }
        traverse->next = new Node(l);
    }
}

void enqueue(Node* &front, Node* &rear, char data) {
    Node* new_node = new Node(data);
    new_node->next = NULL;
    
    if (rear == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue(Node* &front, Node* &rear, char &data) {
    if (front == NULL) {
        return;
    }
    data = front->data;
    Node* temp = front;
    if (front == rear) {
        front = NULL;
        rear = NULL;
    } else {
        front = front->next;
    }
    delete temp;
}

void dfs(char start, char end, Node** list){
    Node* head = NULL;
    Node* tail = NULL;
    
    bool markedL[SIZE] = { false };
    
    enqueue(head, tail, start);
    
    while (head != NULL) {
        char currentL;
        dequeue(head, tail, currentL);
        
        if (currentL == end) {
            cout << "Path exists from " << start << " to " << end << endl;
            return;
        }
        
        Node* traversal = list[currentL - 'A'];
        
        while (traversal != NULL) {
            if (!markedL[traversal->data - 'A']) {
                enqueue(head, tail, traversal->data);
                markedL[traversal->data - 'A'] = true;
            }
            traversal = traversal->next;
        }
    }
    
    cout << "Path does not exist from " << start << " to " << end << endl;
}

/*
 void push(Node*& t, char l){
     t = new Node(l, t);
 }

 void pop(Node*& t, char& l){
     Node* temp = t;
     
     l = t->data;
     t = t->next;
     delete temp;
}
 
void dfs(char start, char end, Node** list) {
    Node* stack = NULL;
    bool markedL[SIZE] = { false };
    
    push(stack, start);
    
    while (stack != NULL) {
        char currentL;
        pop(stack, currentL);
        
        if (currentL == end) {
            cout << "Path exists from " << start << " to " << end << endl;
            return;
        }
        
        Node* traversal = list[currentL - 'A'];
        
        while (traversal != NULL) {
            if (!markedL[traversal->data - 'A']) {
                push(stack, traversal->data);
                markedL[traversal->data - 'A'] = true;
            }
            traversal = traversal->next;
        }
    }
    
    cout << "Path does not exist from " << start << " to " << end << endl;
}
*/

int main(){
    
    Node* Letters[SIZE] = { NULL };
    char src, dest, choice;
    
    //Insert into vertex 'A' linked list
    insert(Letters[0], 'B');
    insert(Letters[0], 'C');
    insert(Letters[0], 'E');
    
    //Insert into vertex 'B' linked list
    insert(Letters[1], 'A');
    
    //Insert into vertex 'C' linked list
    insert(Letters[2], 'E');
    insert(Letters[2], 'D');
    
    //Insert into vertex 'D' linked list
    insert(Letters[3], 'B');
    insert(Letters[3], 'F');
    insert(Letters[3], 'H');
    
    //Insert into vertex 'E' linked list
    insert(Letters[4], 'G');
    insert(Letters[4], 'I');
    
    //Insert into vertex 'F' linked list
    insert(Letters[5], 'H');
    insert(Letters[5], 'B');
    
    //Insert into vertex 'G' linked list
    insert(Letters[6], 'H');
    insert(Letters[6], 'I');
    
    //Insert into vertex 'H' linked list
    insert(Letters[7], 'G');
    insert(Letters[7], 'K');
    
    //Insert into vertex 'I' linked list
    
    //Insert into vertex 'J' linked list
    insert(Letters[9], 'F');
    insert(Letters[9], 'K');

    //Insert into vertex 'K' linked list
    insert(Letters[10], 'J');
    
    do{
        cout << "Valid vertices are A thru K" << endl;
        cout << "Enter a starting verticies: ";
        cin >> src;
        cout << "Enter a ending verticies: ";
        cin >> dest;
        
        dfs(src, dest, Letters);
        
        cout << "\nCheck another path? <Y/N>\n";
        cout << ">>";
        cin >> choice;
        cout << "\n";
    }while (choice == 'Y' || choice == 'y');
    
    return 0;
}
