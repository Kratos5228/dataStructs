#pragma once
#include <string>
#include <iostream>
#include<iomanip>

using namespace std;

class Student{
    public:
    string fname;
    string lname;
    double gpa;

    string getFname(){ return fname; }
    void setFname(string finame) { fname = finame; }
    
    string getLname(){ return lname; }
    void setLname(string laname) { lname = laname; }
    
    double getGPA(){ return gpa; }
    void setGPA(double score) { gpa = score; }
    
    Student(){
        fname = "";
        lname = "";
        gpa = 0;
    }

};

