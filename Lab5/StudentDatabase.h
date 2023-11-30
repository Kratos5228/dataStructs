#pragma once
#include "Student.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class StudentDatabase{
    public:
        int SIZE = NULL;
        int forCount = 0;
        double gpa = NULL;
        Student *stuPtr = NULL;
    
        int getNum(){return SIZE;}
        void setNum(int num){ SIZE = num; }
        
        double getGPA(){ return gpa; }
        void setGPA(double score) { gpa = score; }
    
        void Read();
        void add(string finame, string laname, double score);
        void display();
        StudentDatabase();
    
        void mergeSort(Student arr[], int left, int right);
        void mergeSort(int left, int right){
            mergeSort(stuPtr, left, right);
        }
        void merge(Student arr[], int left, int mid, int right);
    
        void quickSort(Student arr[], int low, int high);
        void quickSort(int low, int high){
            quickSort(stuPtr, low, high);
        }
        int partition(Student arr[], int low, int high);
    
        void heapify(Student arr[], int size, int index);
        void heapSort(Student arr[], int size);
        void heapSort(int size){
            heapSort(stuPtr, size);
        }
    
};
                    
