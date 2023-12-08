#ifndef STUDENTLIST_HPP
#define STUDENTLIST_HPP

#include <string> //you will have to use string in C++
#include <iostream>
#include <cassert>
#include "student.hpp"


using namespace std;

class Node; 
class StudentList 
{
public:
    StudentList();
    ~StudentList(){

    }
    Node *getHead() const;
    Node *getTail() const;


    bool mergeLists(DomesticList *domesticList, InternationalList *internationalList);
    void printHelper();     //prints out all
    void printHelper1(Node *nextStudent);    //prints out 1
    void deleteNode(string firstName, string lastName); //deletes node
    void insert(Node nextStudent);      //inserts
    void deleteHeadAndTail();  //deletes head and tail

    bool searchNames(string firstname, string lastname);    //search names

    //friend ostream &operator<<(ostream &STUDENTLIST_COUT, StudentList &StudentListobj);
    int isStudentCurrentGreater(Node *stu1, Node *stu2);    //compare domestic student
    
    void printCutCGPA(float cgpa,int reasearchScore);  //print based on cgpa cutoff
    void printCutRS(int reasearchScore);  //print based on rs cutoff

    ostream& isSuccessful( ostream &os, DomesticList *DomesticList, InternationalList *intenationalList);
    ostream& failedStudents(ostream &os , DomesticList *DomesticList, InternationalList *InternationalList);

    friend ostream *operator<<(ostream &os, StudentList *stuList);

    
private:
    Node *head;
    Node *tail;


};

class Node
{
    public:

    Node* next; 
    Node* previous; 

    Node();


    InternationalStudent internationalStudent; 
    DomesticStudent domesticStudent;
    Student studentObj;

    private:
   
 };


#endif