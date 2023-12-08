#ifndef TESTINGDRIVER_HPP
#define TESTINGDRIVER_HPP

#include <iostream> //cin and cout
#include <fstream>  //file processing
#include <sstream>  //formatted string processing
#include <cstdlib>  //atof and atoi
#include "student.hpp"
#include "mergedList.hpp"
using namespace std;


int test_menu();
void unit_test(DomesticList *domesticStudentListObj, InternationalList *internationalStudentListObj, 
               int student_number_of_applicants, StudentList *studentList);//the whole test

#endif