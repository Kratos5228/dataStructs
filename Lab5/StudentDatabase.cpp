#include <algorithm>
#include "StudentDatabase.h"
#include "Student.h"

StudentDatabase::StudentDatabase(){
    stuPtr = new Student[SIZE];
}

void StudentDatabase::add(string finame, string laname, double score){    
    stuPtr[forCount].setFname(finame);
    stuPtr[forCount].setLname(laname);
    stuPtr[forCount].setGPA(score);
    
    forCount++;
}

void StudentDatabase::display(){
    for (int i = 0; i < forCount; i++){
        cout << stuPtr[i].getFname() << " " << stuPtr[i].getLname() << " " << fixed << setprecision(1)  << stuPtr[i].getGPA() << endl;
    }
}


void StudentDatabase::Read(){
    ifstream inFile;
    
    inFile.open("/Users/ramonbernal/Desktop/Spring 22'/Lab5/Lab5/students.txt");
    
    string finame, laname;
    int num;
    double score;
    
    delete[] stuPtr;
    stuPtr = new Student[SIZE];
    forCount = 0;
    
    if(!inFile){                            //if statement if the file is unable to open
        cout << "Error opening data file. Exiting Program." << endl;
    }
    
    inFile >> num;
    setNum(num);
    while(!inFile.eof()){
        inFile >> finame >> laname >> score;
        inFile.ignore(100, '\n');
        
        add(finame, laname, score);
    }
    
    inFile.close();
}

void StudentDatabase::mergeSort(Student arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void StudentDatabase::merge(Student arr[], int left, int mid, int right){
    int i, j, k;
    int s1 = mid - left + 1;
    int s2 = right - mid;
    
    Student* leftArr = new Student[s1];
    Student* rightArr = new Student[s2];
    
    for(i = 0; i < s1; i++){
        leftArr[i] = arr[left + i];
    }
    
    for(j = 0; j < s2; j++){
        rightArr[j] = arr[mid + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = left;
    
    while (i < s1 && j < s2){
        if(leftArr[i].getGPA() <= rightArr[j].getGPA()){
            arr[k] = leftArr[i];
            i++;
        }
        else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < s1){
        
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while ( j < s2){
        
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    
}

void StudentDatabase::quickSort(Student arr[], int low, int high){
    
    if( low < high ) {
        int index = partition(arr, low, high);
        
        quickSort(arr, low, index - 1);
        quickSort(arr, index + 1, high);
    }
}

int StudentDatabase::partition(Student arr[], int low, int high){
    
    int mid = (low + high) / 2;
    
    if(arr[mid].getGPA() < arr[low].getGPA()){
        swap(arr[mid], arr[low]);
    }if(arr[high].getGPA() < arr[low].getGPA()){
        swap(arr[high], arr[low]);
    }if(arr[mid].getGPA() < arr[high].getGPA()){
        swap(arr[high], arr[low]);
    }
    

    double pivot = arr[high].getGPA();
    int index = low;
    
    for(int j = low; j <= high - 1; j++){
        if(arr[j].getGPA() <= pivot){
            swap(arr[index], arr[j]);
            index++;
        }
    }
    swap(arr[index], arr[high]);
    
    return index;
}

void StudentDatabase::heapify(Student arr[], int size, int index){
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;
    if(leftChild < size && arr[leftChild].getGPA() > arr[largest].getGPA()){
        largest = leftChild;
    }
    if(rightChild < size && arr[rightChild].getGPA() > arr[largest].getGPA()){
        largest = rightChild;
    }
    if(largest != index){
        swap(arr[index], arr[largest]);
        heapify(arr, size, largest);
    }
}

void StudentDatabase::heapSort(Student arr[], int size){
    for(int index = (size/2) - 1; index >= 0; index--){
        heapify(arr, size, index);
    }
    for(int index = size-1; index >= 0; index--){
        swap(arr[0], arr[index]);
        heapify(arr, index, 0);
    }
}
