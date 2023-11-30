#include <iostream>

using namespace std;

class EmployeeInfo{
    
public:
    string EmployeeName;
    int EmployeeID;
    
    EmployeeInfo(){
         EmployeeName = " ";
         EmployeeID = 0;
    }
    
};

struct TreeNode{
public:
    EmployeeInfo data;
    TreeNode * lChild;
    TreeNode * rChild;

    TreeNode(string name, int id, TreeNode * l = NULL, TreeNode * r = NULL)
    {
        data.EmployeeName = name;
        data.EmployeeID = id;
        lChild = l;
        rChild = r;
    }
    
};

void insert(string name, int id, TreeNode *& leaf){
    if (leaf == NULL)
    {
        leaf = new TreeNode(name, id);
        return;
    }
    
    if(id == leaf->data.EmployeeID){
        throw string("\nChoosen ID Already Used\n");
    }
    if (id < leaf->data.EmployeeID)
        insert(name, id, leaf->lChild);
    else
        insert(name, id, leaf->rChild);
}

void inOrder(TreeNode* r){
    if (r != NULL)
    {
        inOrder(r->lChild);
        cout << r->data.EmployeeID << " " << r->data.EmployeeName<< endl;
        inOrder(r->rChild);
    }
}

void preOrder(TreeNode* r){
    if (r != NULL)
    {
        cout << r->data.EmployeeID << " " << r->data.EmployeeName << endl;
        preOrder(r->lChild);
        preOrder(r->rChild);
    }
}

void postOrder(TreeNode* r){
    if (r != NULL)
    {
        postOrder(r->lChild);
        postOrder(r->rChild);
        cout << r->data.EmployeeID << " " << r->data.EmployeeName<< endl;
    }
}

bool search(int id, TreeNode* root){
    TreeNode* leaf = root;

    while (leaf != NULL)
    {
        if (id == leaf->data.EmployeeID){
            cout << leaf->data.EmployeeID << " " << leaf->data.EmployeeName << endl;
            return true;
        }else if (id < leaf->data.EmployeeID){
            leaf = leaf->lChild;
        }else
            leaf = leaf->rChild;
    }
    cout << "Employee ID Not Found" << endl;
    return false;
}

int main() {
    
    TreeNode* root = NULL;
    
    int choice;
    string name;
    int id;
    
    insert("Sam Kennedy", 1015, root);
    insert("Connor Mills", 1277, root);
    insert("Ty Watkins", 1668, root);
    insert("Yasmin Lane", 1497, root);
    insert("Ashley Chapman ", 1016, root);
    insert("Vic Conrad ", 2829, root);
    insert("Ryan Dawson ", 1049, root);
    insert("Isabella Wright ", 1504, root);
    insert("Charlie Riddle ", 2111, root);
    insert("Crystal Boyer ", 1850, root);
    
    cout << "\nImplemented the Data from the Lab Documnet\n" << endl;
    
    do{
    cout << "1) Add an Employee Info " << endl;
    cout << "2) Search for Employee Info " << endl;
    cout << "3) Print Out " << endl;
    cout << "4) Exit " << endl;
    cout << ">>";
    cin >> choice;
    cout << endl;
        
    switch (choice){
            
        case 1:
            try{
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter ID: " ;
                cin >> id;
                insert(name, id, root);
                cout << endl;
                
            }catch(string message){
                cout << message << endl;
            }
        break;
            
        case 2:
            cout << "Search for the Employee ID for Info" << endl;
            cout << ">>";
            cin >> id;
            cout << endl;
            search(id, root);
            cout << endl;
        break;
        
        case 3:
            inOrder(root);
            cout << endl;
            preOrder(root);
            cout << endl;
            postOrder(root);
            cout << endl;
        break;
            
        case 4:
            
        break;
            
        default:
            cout << "Wrong Choice Entered\n" << endl;
        break;
     }
    }while(choice != 4);
    
    return 0;
}
