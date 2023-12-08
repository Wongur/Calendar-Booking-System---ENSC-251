//TESTING DRIVER
#include "testingdriver.hpp"
#include "student.hpp"
#include "mergedList.hpp"
#include <iostream> //cin and cout
#include <fstream>  //file processing
#include <sstream>  //formatted string processing
#include <cstdlib>  //atof and atoi

string formatString_Capital_Lowercase1(string &s)
{
  s[0] = toupper(s[0]);
  int stringLength = s.length();
  for (int j = 1; j < stringLength; j++)
  {
    s[j] = tolower(s[j]);
  }

  return s;
}

int test_menu()
{
    
    int input;
    while(true){
    cout << "Perform which unit test" << endl;
    cout << "1.) Insert Student" << endl;
    cout << "2.) Search List on CGPA, App Id or Research Score" << endl;
    cout << "3.) Search List on Name" << endl;
    cout << "4.) Delete Student based on First/Last Name" << endl;
    cout << "5.) Delete the head and tail nodes" << endl;
    cout << "6.) Merge Lists" << endl;
    cout << "7.) Search List by threshold" << endl;
    cout << "To Exit test menu: any other input" << endl;
    cin >> input;
    if (cin.fail())
    {
      {
        cout << "Quitting test menu\n\n";
        input = -1;
        return(input);
      }
      cin.clear(); // Clears any error flags
      cin.ignore(1000, '\n');
    }else{
        return input;
    }
    }
}

void unit_test(DomesticList *domesticStudentListObj, InternationalList *internationalStudentListObj, int student_number_of_applicants, StudentList *studentList){
    int menu_input;
    int searchInput;
    menu_input = test_menu();
    switch(menu_input){

        //INSERT 
        case 1:{
            
            cout << "Would you like to unit test (1)Domestic or (2)International" << endl;
            cin >> menu_input;

            //DOMESTIC INSERT
            if(menu_input == 1){

                //CORNER CASES
                cout << "Inserting in Domestic..." << endl;
                DomesticStudent tempDomStudent;
                string testFirstName = "Aaron";
                string testLastName = "Armstead";
                string testProvince = "BC";
                float testCGPA = 4.30;
                float testResearchScore = 100; 
                tempDomStudent.setFirstName(testFirstName);
                tempDomStudent.setLastName(testLastName);
                tempDomStudent.setProvince(testProvince);
                if(!tempDomStudent.isProvinceValid()){
                cout << "Invalid province specified" << endl;
                }
                tempDomStudent.setCGPA(testCGPA);
                if(!tempDomStudent.isCGPAvalid()){
                cout << "Invalid CGPA specified" << endl;
                }
                tempDomStudent.setResearchScore(testResearchScore);  
                tempDomStudent.setApplicationID(student_number_of_applicants);
                student_number_of_applicants += 1;
                domesticStudentListObj->insertNode(tempDomStudent);

                DomesticStudent tempDomStudent1;
                string testFirstName2 = "Zack";
                string testLastName2 = "Zimmerman";
                string testProvince2 = "YT";
                float testCGPA2 = 0.00;
                float testResearchScore2 = 0; 
                tempDomStudent1.setFirstName(testFirstName2);
                tempDomStudent1.setLastName(testLastName2);
                tempDomStudent1.setProvince(testProvince2);
                if(!tempDomStudent1.isProvinceValid()){
                    cout << "Invalid province specified" << endl;
                }
                tempDomStudent1.setCGPA(testCGPA2);
                if(!tempDomStudent1.isCGPAvalid()){
                    cout << "Invalid CGPA specified" << endl;
                }
                tempDomStudent1.setResearchScore(testResearchScore2);  
                tempDomStudent1.setApplicationID(student_number_of_applicants);
                student_number_of_applicants += 1;
                domesticStudentListObj->insertNode(tempDomStudent1);

                //NORMAL CASE
                DomesticStudent tempDomStudent3;
                string testFirstName6 = "Mickey";
                string testLastName6 = "Mantle";
                string testProvince6 = "ON";
                float testCGPA6 = 3.00;
                float testResearchScore6 = 80; 
                tempDomStudent3.setFirstName(testFirstName6);
                tempDomStudent3.setLastName(testLastName6);
                tempDomStudent3.setProvince(testProvince6);
                if(!tempDomStudent3.isProvinceValid()){
                    cout << "Invalid province specified" << endl;
                }
                tempDomStudent3.setCGPA(testCGPA6);
                if(!tempDomStudent3.isCGPAvalid()){
                    cout << "Invalid CGPA specified" << endl;
                }
                tempDomStudent3.setResearchScore(testResearchScore6);  
                tempDomStudent3.setApplicationID(student_number_of_applicants);
                student_number_of_applicants += 1;
                domesticStudentListObj->insertNode(tempDomStudent3);
                domesticStudentListObj->printList();

                //ILLEGAL CASE
                cout << endl << "Illegal case unit test" << endl;
                DomesticStudent tempDomStudent2;
                string testFirstName4 = "Nathan";
                string testLastName4 = "Drake";
                string testProvince4 = "XX";
                float testCGPA4 = -1.00;
                float testResearchScore4 = 1000; 
                tempDomStudent2.setFirstName(testFirstName4);
                tempDomStudent2.setLastName(testLastName4);
                tempDomStudent2.setProvince(testProvince4);
                if(!tempDomStudent2.isProvinceValid()){
                    cout << endl << "Invalid province specified" << endl;
                }
                tempDomStudent2.setCGPA(testCGPA4);
                if(!tempDomStudent2.isCGPAvalid()){
                    cout << "Invalid CGPA specified" << endl;
                }
                tempDomStudent2.setResearchScore(testResearchScore4);  
                tempDomStudent2.setApplicationID(student_number_of_applicants);
                student_number_of_applicants += 1;
                domesticStudentListObj->insertNode(tempDomStudent2);
            }

            //INTERNATIONAL INSERT
            if(menu_input == 2){
                
                //CORNER CASE
                cout << endl << "Inserting in International..." << endl;
                InternationalStudent tempIntStudent;
                string testFirstName1 = "Aaron";
                string testLastName1 = "Armstead";
                string testCountry = "China";
                float testCGPA1 = 4.30;
                float testResearchScore1 = 100; 
                int readingTemp = 25;
                int writingTemp = 25;
                int listeningTemp = 25;
                int speakingTemp = 25;
                tempIntStudent.setFirstName(testFirstName1);
                tempIntStudent.setLastName(testLastName1);
                tempIntStudent.setCountryOrigin(testCountry);
                if(!tempIntStudent.isCountryValidAndInternational()){
                    cout << "Invalid country specified" << endl;
                }
                tempIntStudent.setCGPA(testCGPA1);
                if(!tempIntStudent.isCGPAvalid()){
                    cout << "Invalid CGPA specified" << endl;
                }
                tempIntStudent.setResearchScore(testResearchScore1);  
                tempIntStudent.setApplicationID(student_number_of_applicants);
                student_number_of_applicants += 1;
                tempIntStudent.setToeflScoreHelper(readingTemp, writingTemp, listeningTemp, speakingTemp);
                internationalStudentListObj->insertNode(tempIntStudent);

                InternationalStudent tempIntStudent1;
                string testFirstName3 = "Zack";
                string testLastName3 = "Zimmerman";
                string testCountry1 = "Korea";
                float testCGPA3 = 0.00;
                float testResearchScore3 = 0; 
                int readingTemp1 = 0;
                int writingTemp1 = 0;
                int listeningTemp1 = 0;
                int speakingTemp1 = 0;
                tempIntStudent1.setFirstName(testFirstName3);
                tempIntStudent1.setLastName(testLastName3);
                tempIntStudent1.setCountryOrigin(testCountry1);
                if(!tempIntStudent1.isCountryValidAndInternational()){
                    cout << "Invalid country specified" << endl;
                }
                tempIntStudent1.setCGPA(testCGPA3);
                if(!tempIntStudent1.isCGPAvalid()){
                    cout << "Invalid CGPA specified" << endl;
                }
                tempIntStudent1.setResearchScore(testResearchScore3);  
                tempIntStudent1.setApplicationID(student_number_of_applicants);
                student_number_of_applicants += 1;
                tempIntStudent1.setToeflScoreHelper(readingTemp1, writingTemp1, listeningTemp1, speakingTemp1);
                internationalStudentListObj->insertNode(tempIntStudent1);

                //NORMAL CASE
                InternationalStudent tempIntStudent3;
                string testFirstName7 = "Mickey";
                string testLastName7 = "Mantle";
                string testCountry3 = "Iran";
                float testCGPA7 = 3.00;
                float testResearchScore7 = 80; 
                int readingTemp3 = 25;
                int writingTemp3 = 25;
                int listeningTemp3 = 25;
                int speakingTemp3 = 25;
                tempIntStudent3.setFirstName(testFirstName7);
                tempIntStudent3.setLastName(testLastName7);
                tempIntStudent3.setCountryOrigin(testCountry3);
                if(!tempIntStudent3.isCountryValidAndInternational()){
                    cout << "Invalid country specified" << endl;
                }
                tempIntStudent3.setCGPA(testCGPA7);
                if(!tempIntStudent3.isCGPAvalid()){
                    cout << "Invalid CGPA specified" << endl;
                }
                tempIntStudent3.setResearchScore(testResearchScore7);  
                tempIntStudent3.setApplicationID(student_number_of_applicants);
                student_number_of_applicants += 1;
                tempIntStudent3.setToeflScoreHelper(readingTemp3, writingTemp3, listeningTemp3, speakingTemp3);
                internationalStudentListObj->insertNode(tempIntStudent3);
                internationalStudentListObj->printList();

                //ILLEGAL CASE
                cout << endl << "Illegal case unit test: " << endl;
                InternationalStudent tempIntStudent2;
                string testFirstName5 = "Nathan";
                string testLastName5 = "Drake";
                string testCountry2 = "Portugal";
                float testCGPA5 = -1.00;
                float testResearchScore5 = 1000; 
                int readingTemp2 = -1;
                int writingTemp2 = -1;
                int listeningTemp2 = -1;
                int speakingTemp2 = -1;
                tempIntStudent2.setFirstName(testFirstName5);
                tempIntStudent2.setLastName(testLastName5);
                tempIntStudent2.setCountryOrigin(testCountry2);
                if(!tempIntStudent2.isCountryValidAndInternational()){
                    cout << "Invalid country specified" << endl;
                }
                tempIntStudent2.setCGPA(testCGPA5);
                if(!tempIntStudent2.isCGPAvalid()){
                    cout << "Invalid CGPA specified" << endl;
                }
                tempIntStudent2.setResearchScore(testResearchScore5);  
                tempIntStudent2.setApplicationID(student_number_of_applicants);
                student_number_of_applicants += 1;
                tempIntStudent2.setToeflScoreHelper(readingTemp2, writingTemp2, listeningTemp2, speakingTemp2);
                internationalStudentListObj->insertNode(tempIntStudent2);
            }
            break;
        }

        //SEARCH BY CGPA ,RESEARCH SCORE AND APPLICATION ID
        case 2:{  

            cout << "Would you like to unit test (1)CGPA, (2)research score or (3)application ID: " << endl;
            cin >> searchInput;

            //CGPA SEARCH
            if(searchInput == 1){

                //CORNER CASES (DOMESTIC)
                float testCGPA = 4.30;
                cout << endl << "Unit test -- searching Domestic list for all students with " << testCGPA << " CGPA." << endl;
                domesticStudentListObj->searchDomesticCGPA(testCGPA);

                float testCGPA1 = 0.00;
                cout << endl << "Unit test -- searching Domestic list for all students with " << testCGPA1 << " CGPA." << endl;
                domesticStudentListObj->searchDomesticCGPA(testCGPA1);

                //CORNER CASES (INTERNATIONAL)
                float testCGPA2 = 4.30;
                cout << endl << "Unit test -- searching International list for all students with " << testCGPA2 << " CGPA." << endl;
                internationalStudentListObj->searchInternationalCGPA(testCGPA2);

                float testCGPA3 = 0.00;
                cout << endl << "Unit test -- searching International list for all students with " << testCGPA3 << " CGPA." << endl;
                internationalStudentListObj->searchInternationalCGPA(testCGPA3);

                //NORMAL (DOMESTIC)
                float testCGPA6 = 3.00;
                cout << endl << "Unit test -- searching Domestic list for all students with " << testCGPA6 << " CGPA." << endl;
                domesticStudentListObj->searchDomesticCGPA(testCGPA6);

                //NORMAL (INTERNATIONAL)
                float testCGPA7 = 3.00;
                cout << endl << "Unit test -- searching International list for all students with " << testCGPA7 << " CGPA." << endl;
                internationalStudentListObj->searchInternationalCGPA(testCGPA7);

                //ILLEGAL (DOMESTIC)
                float testCGPA4 = -1.00;
                cout << endl << "Unit test -- searching Domestic list for all students with " << testCGPA4 << " CGPA." << endl;
                domesticStudentListObj->searchDomesticCGPA(testCGPA4);

                //ILLEGAL (INTERNATIONAL)
                float testCGPA5 = 5.00;
                cout << endl << "Unit test -- searching International for all students with " << testCGPA5 << " CGPA." << endl;
                internationalStudentListObj->searchInternationalCGPA(testCGPA5);
            
            }

            //RESEARCH SCORE SEARCH
            if(searchInput == 2){ 
                
                //CORNER CASES (DOMESTIC)
                int testResearchScore = 100;
                cout << endl << "Unit test -- searching Domestic list for all students with " << testResearchScore << " research score." << endl;
                domesticStudentListObj->searchDomesticResearchScore(testResearchScore);

                int testResearchScore1 = 0;
                cout << endl << "Unit test -- searching Domestic list for all students with " << testResearchScore1 << " research score." << endl;
                domesticStudentListObj->searchDomesticResearchScore(testResearchScore1);

                //CORNER CASES (INTERNATIONAL)
                int testResearchScore3 = 100;
                cout << endl << "Unit test -- searching International list for all students with " << testResearchScore3 << " research score." << endl;
                internationalStudentListObj->searchInternationalResearchScore(testResearchScore3);
                
                int testResearchScore4 = 0;
                cout << endl << "Unit test -- searching International list for all students with " << testResearchScore4 << " research score." << endl;
                internationalStudentListObj->searchInternationalResearchScore(testResearchScore4);

                //NORMAL (DOMESTIC)
                int testResearchScore6 = 80;
                cout << endl << "Unit test -- searching Domestic list for all students with " << testResearchScore6 << " research score." << endl;
                domesticStudentListObj->searchDomesticResearchScore(testResearchScore6);

                //NORMAL (INTERNATIONAL)
                int testResearchScore7 = 80;
                cout << endl << "Unit test -- searching International list for all students with " << testResearchScore7 << " research score." << endl;
                internationalStudentListObj->searchInternationalResearchScore(testResearchScore7);
                
                //ILLEGAL (DOMESTIC)
                int testResearchScore2 = -1000;
                cout << endl << "Unit test -- searching Domestic list for all students with " << testResearchScore2 << " research score." << endl;
                domesticStudentListObj->searchDomesticResearchScore(testResearchScore2);

                //ILLEGAL (INTERNATIONAL)
                int testResearchScore5 = 200;
                cout << endl << "Unit test -- searching International list for all students with " << testResearchScore5 << " research score." << endl;
                internationalStudentListObj->searchInternationalResearchScore(testResearchScore5);
            } 

            //APP ID SEARCH
            if(searchInput == 3){

                //CORNER CASES (DOMESTIC)
                int TestAppID = 20220000;
                cout << "Unit test -- search Domestic list for all students with " << TestAppID << " application ID." << endl;
                domesticStudentListObj->searchDomesticApplicationID(TestAppID);

                int TestAppID1 = 20220099;
                cout << "Unit test -- search Domestic list for all students with " << TestAppID1 << " application ID." << endl;
                domesticStudentListObj->searchDomesticApplicationID(TestAppID1);

                //CORNER CASES (INTERNATIONAL)
                int TestAppID2 = 20220100;
                cout << "Unit test -- search International list for all students with " << TestAppID2 << " application ID." << endl;
                internationalStudentListObj->searchInternationalApplicationID(TestAppID2);

                int TestAppID3 = 20220199;
                cout << "Unit test -- search International list for all students with " << TestAppID3 << " application ID." << endl;
                internationalStudentListObj->searchInternationalApplicationID(TestAppID3);

                //NORMAL (DOMESTIC)
                int TestAppID6 = 20220001;
                cout << "Unit test -- search Domestic list for all students with " << TestAppID6 << " application ID." << endl;
                domesticStudentListObj->searchDomesticApplicationID(TestAppID6);

                //NORMAL (INTERNATIONAL)
                int TestAppID7 = 20220110;
                cout << "Unit test -- search International list for all students with " << TestAppID7 << " application ID." << endl;
                internationalStudentListObj->searchInternationalApplicationID(TestAppID7);

                //ILLEGAL (DOMESTIC)
                int TestAppID4 = 20219999;
                cout << "Unit test -- search Domestic list for all students with " << TestAppID4 << " application ID." << endl;
                domesticStudentListObj->searchDomesticApplicationID(TestAppID4);

                //ILLEGAL (INTERNATIONAL)
                int TestAppID5 = 20220200;
                cout << "Unit test -- search International list for all students with " << TestAppID5 << " application ID." << endl;
                internationalStudentListObj->searchInternationalApplicationID(TestAppID5);
            }
            else{
                
                cout << "Invalid input" << endl;
                return;
            }
            break;
        }

        //SEARCH BY NAMES
        case 3:{ 
            
            cout << endl << "Would you like to search in (1)Domestic or (2)International: " << endl;
            cin  >> menu_input;

            //SEARCH DOMESTIC 
            if(menu_input == 1){

                //CORNER
                string testFirstName = "AuRoRa";
                string testLastName = "fOsTeR";
                cout << "Unit Test -- search Domestic list for '" << testFirstName << " " << testLastName << "'." << endl;
                testFirstName = formatString_Capital_Lowercase1(testFirstName);
                testLastName = formatString_Capital_Lowercase1(testLastName);
                domesticStudentListObj->searchDomesticNames(testFirstName, testLastName);

                string testFirstName4 = "eMiLy";
                string testLastName4 = "RiVeRa";
                cout << "Unit Test -- search Domestic list for '" << testFirstName4 << " " << testLastName4 << "'." << endl;
                testFirstName4 = formatString_Capital_Lowercase1(testFirstName4);
                testLastName4 = formatString_Capital_Lowercase1(testLastName4);
                domesticStudentListObj->searchDomesticNames(testFirstName4, testLastName4);

                //ILLEGAL 
                string testFirstName2 = "Benjamin";
                string testLastName2 = "Button";
                cout << "Unit Test -- search Domestic list for '" << testFirstName2 << " " << testLastName2 << "'." << endl;
                testFirstName2 = formatString_Capital_Lowercase1(testFirstName2);
                testLastName2 = formatString_Capital_Lowercase1(testLastName2);
                domesticStudentListObj->searchDomesticNames(testFirstName2, testLastName2);

            }

            //SEARCH INTERNATIONAL
            if(menu_input == 2){

                //CORNER 
                string testFirstName1 = "TiNg";
                string testLastName1 = "fAnG";
                cout << "Unit Test -- search International list for '" << testFirstName1 << " " << testLastName1 << "'." << endl;
                testFirstName1 = formatString_Capital_Lowercase1(testFirstName1);
                testLastName1 = formatString_Capital_Lowercase1(testLastName1);
                internationalStudentListObj->searchInternationalNames(testFirstName1, testLastName1);

                string testFirstName5 = "sHaYaN";
                string testLastName5 = "GhArAbAgHi";
                cout << "Unit Test -- search International list for '" << testFirstName5 << " " << testLastName5 << "'." << endl;
                testFirstName5 = formatString_Capital_Lowercase1(testFirstName5);
                testLastName5 = formatString_Capital_Lowercase1(testLastName5);
                internationalStudentListObj->searchInternationalNames(testFirstName5, testLastName5);

                //ILLEGAL 
                string testFirstName3 = "Robin";
                string testLastName3 = "Hood";
                cout << "Unit Test -- search International list for '" << testFirstName3 << " " << testLastName3 << "'." << endl;
                testFirstName3 = formatString_Capital_Lowercase1(testFirstName3);
                testLastName3 = formatString_Capital_Lowercase1(testLastName3);
                internationalStudentListObj->searchInternationalNames(testFirstName3, testLastName3);
            }
            break;
        }
        
        //DELETE BASED ON NAME 
        case 4:{ 

            cout << "Would you like to delete in (1)Domestic or (2)International" << endl; 
            cin >> menu_input;

            //DELETE (DOMESTIC)
            if(menu_input == 1){
                
                cout << "Would you like to unit test (1)corner case, (2)normal case or (3)illegal case" << endl;
                cin >> searchInput;
                if(searchInput == 1){
                    //CORNER
                    string testFirstName = "AuRoRa";
                    string testLastName = "FoStEr";
                    testFirstName = formatString_Capital_Lowercase1(testFirstName);
                    testLastName = formatString_Capital_Lowercase1(testLastName);
                    if(domesticStudentListObj->searchDomesticNames(testFirstName, testLastName) == 1){
                        cout << endl << "Unit Test -- Delete student in Domestic list for '" << testFirstName << " " << testLastName << "'." << endl;
                        domesticStudentListObj->deleteDomestic(testFirstName, testLastName);
                    }
                    string testFirstName4 = "EmIlY";
                    string testLastName4 = "rIvErA";
                    testFirstName4 = formatString_Capital_Lowercase1(testFirstName4);
                    testLastName4 = formatString_Capital_Lowercase1(testLastName4);
                    if(domesticStudentListObj->searchDomesticNames(testFirstName4, testLastName4) == 1){
                        cout << endl << "Unit Test -- Delete student in Domestic list for '" << testFirstName4 << " " << testLastName4 << "'." << endl;
                        domesticStudentListObj->deleteDomestic(testFirstName4, testLastName4);
                    }
                    cout << "Domestic list after deletion of " << testFirstName << " " << testLastName << " and " << testFirstName4 << " " << testLastName4 << ":" << endl;
                    domesticStudentListObj->printList();
                }

                if(searchInput == 2){
                    //NORMAL
                    string testFirstName5 = "DyLaN";
                    string testLastName5 = "bArNeS";
                    testFirstName5 = formatString_Capital_Lowercase1(testFirstName5);
                    testLastName5 = formatString_Capital_Lowercase1(testLastName5);
                    if(domesticStudentListObj->searchDomesticNames(testFirstName5, testLastName5) == 1){
                        cout << endl << "Unit Test -- Delete student in Domestic list for '" << testFirstName5 << " " << testLastName5 << "'." << endl;
                        domesticStudentListObj->deleteDomestic(testFirstName5, testLastName5);
                    }
                    string testFirstName6 = "ViOlEt";
                    string testLastName6 = "sImMoNs";
                    testFirstName6 = formatString_Capital_Lowercase1(testFirstName6);
                    testLastName6 = formatString_Capital_Lowercase1(testLastName6);
                    if(domesticStudentListObj->searchDomesticNames(testFirstName6, testLastName6) == 1){
                        cout << endl << "Unit Test -- Delete student in Domestic list for '" << testFirstName6 << " " << testLastName6 << "'." << endl;
                        domesticStudentListObj->deleteDomestic(testFirstName6, testLastName6);
                        cout << " " << endl;
                    }
                    cout << "Domestic list after deletion of " << testFirstName5 << " " << testLastName5 << " and " << testFirstName6 << " " << testLastName6 << ":" << endl;
                    domesticStudentListObj->printList();
                }

                if(searchInput == 3){
                    //ILLEGAL
                    string testFirstName2 = "Benjamin";
                    string testLastName2 = "Button";
                    testFirstName2 = formatString_Capital_Lowercase1(testFirstName2);
                    testLastName2 = formatString_Capital_Lowercase1(testLastName2);
                    if(domesticStudentListObj->searchDomesticNames(testFirstName2, testLastName2) == 1){
                        cout << endl << "Unit Test -- Delete student in Domestic list for '" << testFirstName2 << " " << testLastName2 << "'." << endl;
                        domesticStudentListObj->deleteDomestic(testFirstName2, testLastName2);
                    }    
                }
            }

            //DELETE (INTERNATIONAL)
            if(menu_input == 2){
                
                cout << "Would you like to unit test (1)corner case, (2)normal case or (3)illegal case" << endl;
                cin >> searchInput;

                if(searchInput == 1){
                    //CORNER
                    string testFirstName1 = "TinG";
                    string testLastName1 = "fAnG";
                    testFirstName1 = formatString_Capital_Lowercase1(testFirstName1);
                    testLastName1 = formatString_Capital_Lowercase1(testLastName1);
                    if(internationalStudentListObj->searchInternationalNames(testFirstName1,testLastName1) == 1){
                    cout << endl << "Unit Test -- Delete student in International list for '" << testFirstName1 << " " << testLastName1 << "'." << endl;
                    internationalStudentListObj->deleteInternational(testFirstName1, testLastName1);
                    }

                    string testFirstName7 = "Shayan";
                    string testLastName7 = "Gharabaghi";
                    testFirstName1 = formatString_Capital_Lowercase1(testFirstName1);
                    testLastName1 = formatString_Capital_Lowercase1(testLastName1);
                    if(internationalStudentListObj->searchInternationalNames(testFirstName7,testLastName7) == 1){
                        cout << endl << "Unit Test -- Delete student in International list for '" << testFirstName7 << " " << testLastName7 << "'." << endl;
                        internationalStudentListObj->deleteInternational(testFirstName7, testLastName7);
                    }
                    cout << "International list after deletion of " << testFirstName1 << " " << testLastName1 << " and " << testFirstName7 << " " << testLastName7 << ":" << endl;
                    internationalStudentListObj->printList();
                    cout << " " << endl;
                }

                if(searchInput == 2){

                    //NORMAL
                    string testFirstName8 = "TiNgTiNg";
                    string testLastName8 = "ZhAo";
                    testFirstName8 = formatString_Capital_Lowercase1(testFirstName8);
                    testLastName8 = formatString_Capital_Lowercase1(testLastName8);
                    if(internationalStudentListObj->searchInternationalNames(testFirstName8,testLastName8) == 1){
                        cout << endl << "Unit Test -- Delete student in International list for '" << testFirstName8 << " " << testLastName8 << "'." << endl;
                        internationalStudentListObj->deleteInternational(testFirstName8, testLastName8);
                    }

                    string testFirstName9 = "MaRy";
                    string testLastName9 = "GhArAbAgHi";
                    testFirstName9 = formatString_Capital_Lowercase1(testFirstName9);
                    testLastName9 = formatString_Capital_Lowercase1(testLastName9);
                    if(internationalStudentListObj->searchInternationalNames(testFirstName9,testLastName9) == 1){
                        cout << endl << "Unit Test -- Delete student in International list for '" << testFirstName9 << " " << testLastName9 << "'." << endl;
                        internationalStudentListObj->deleteInternational(testFirstName9, testLastName9);
                    }
                    cout << "International list after deletion of " << testFirstName8 << " " << testLastName8 << ", " << testFirstName9 << " " << testLastName9 << endl;
                    internationalStudentListObj->printList();
                    cout << " " << endl;
                }

                if(searchInput == 3){
                    //ILLEGAL 
                    string testFirstName3 = "Robin";
                    string testLastName3 = "Hood";
                    if(internationalStudentListObj->searchInternationalNames(testFirstName3, testLastName3) == 1){
                        cout << endl << "Unit Test -- Delete student in International list for '" << testFirstName3 << " " << testLastName3 << "'." << endl; 
                        testFirstName3 = formatString_Capital_Lowercase1(testFirstName3);
                        testLastName3 = formatString_Capital_Lowercase1(testLastName3);
                        internationalStudentListObj->deleteInternational(testFirstName3, testLastName3);
                    }
                }
            }
            break;
        }

        //DELETE HEAD AND TAIL 
        case 5:{ //international list is not being imported properly (toeflscores issue) and therefore international tail is not deleted 

            cout << endl << "Domestic list BEFORE deletion of head and tail: " << endl;
            domesticStudentListObj->printList();
            cout << endl << "International list BEFORE deletion of head and tail: " << endl;
            internationalStudentListObj->printList();


            domesticStudentListObj->deleteDomesticHeadAndTail();
            internationalStudentListObj->deleteInternationalHeadAndTail();
            cout << endl << "Domestic list AFTER deletion of head and tail: " << endl;
            domesticStudentListObj->printList();
            cout << endl << "International list AFTER deletion of head and tail: " << endl;
            internationalStudentListObj->printList();
            break;
        }

        //MERGE BOTH LISTS 
        case 6:{

            studentList->mergeLists(domesticStudentListObj, internationalStudentListObj);
            break;
        }

        //SEARCH BY THRESHOLD
        case 7:{

            studentList->mergeLists(domesticStudentListObj, internationalStudentListObj);
            //corner
            float testCGPA8 = 0;  
            float testCGPA10 = 4.3;
            //normal
            float testCGPA9 = 3;
            //illegal
            float testCGPA11 = 5;
            
            //corner
            int testResearchScore8 = 0;
            int testResearchScore10 = 99;
            //normal
            int testResearchScore9 = 3;
            //illegal 
            int testResearchScore11 = 101;
           
                cout << endl << "Prining all students above the cutoff " << testCGPA8 << "&" << testResearchScore8 <<endl;  
                studentList->printCutCGPA(testCGPA8,testResearchScore8);
                cout << endl << "Prining all students above the cutoff " << testCGPA10 << "&" << testResearchScore10 <<endl;
                studentList->printCutCGPA(testCGPA10,testResearchScore10);
                cout << endl << "Prining all students above the cutoff " << testCGPA9 << "&" << testResearchScore9 <<endl;
                studentList->printCutCGPA(testCGPA9,testCGPA9);
                cout << endl << "Prining all students above the cutoff " << testCGPA11 << "&" << testResearchScore11<<endl;
                studentList->printCutCGPA(testCGPA11,testCGPA11);    
            
            break;
        }
        case -1:
            break;
    }   
}
    