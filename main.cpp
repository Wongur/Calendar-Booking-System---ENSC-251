/*

*/
#include <iostream> //cin and cout
#include <fstream>  //file processing
#include <sstream>  //formatted string processing
#include <cstdlib>  //atof and atoi
#include "student.hpp"
#include "mergedList.hpp"
#include "testingdriver.hpp"
const int MAX_STUDENTS = 100;

// Output file
ofstream SuccessfulStudents;
ofstream FailedStudents;

// Returns rounded float to 1 decimal place
float rounding(float roundedNumber)
{

  float value = (int)(roundedNumber * 10 + .5);
  // conversion from Float Int to int removes value, +0.5 rounds to nearest
  return value / 10;
}

// To capitalize first letter of each proper name (Country, Name)
// note that toupper is from STRING library (which is allowed according to '12')
string formatString_Capital_Lowercase(string &s)
{
  s[0] = toupper(s[0]);
  int stringLength = s.length();
  for (int j = 1; j < stringLength; j++)
  {
    s[j] = tolower(s[j]);
  }

  return s;
}

// caps  for province
string formatProvince(string &s)
{
  if (s[0] == tolower(s[0]))
  {
    s[0] = toupper(s[0]);
  }

  if (s[1] == tolower(s[1]))
  {
    s[1] = toupper(s[1]);
  }

  return s;
}

// function to detect missing input in file
bool inputMissingChecker(string &input, int &lineOfMissingInput)
{
  if (input.empty())
  {
    cout << "Student Information input at line " << lineOfMissingInput + 2 << " is missing" << endl;
    return true;
  }
  else
  {

    return false;
  }
}

int main()
{
  StudentList studentList;
  // TODO: Compress entire taking international/local student file reading into a function
  string line;
  int avRSTotal;
  int avCGPATotal;
  int choiceInt;

  ifstream domesticFile("domestic-stu.txt");
  if (!domesticFile.is_open())
  {
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }
  getline(domesticFile, line);
  // cout << "File format: " << line << endl;

  DomesticList domesticStudentListObj;
  int line_number_count = 0;

  while (getline(domesticFile, line))
  {

    istringstream ss(line);
    string first_Name_Domestic, last_Name_Domestic, province, s_cgpa, s_researchScore;
    float cgpaDomestic;
    int researchScoreDomestic;

    // get firstName separated by comma
    getline(ss, first_Name_Domestic, ',');

    // correct input checker, prints out what line incorrect input is as well as the type of input required to be fixed
    if (inputMissingChecker(first_Name_Domestic, line_number_count))
    {
      cout << "Type of Information missing is : First Name Domestic Student \n";
    }

    // Capitalize first letter of each first name
    formatString_Capital_Lowercase(first_Name_Domestic);

    // get lastName separated by comma
    getline(ss, last_Name_Domestic, ',');
    formatString_Capital_Lowercase(last_Name_Domestic);
    if (inputMissingChecker(last_Name_Domestic, line_number_count))
    {
      cout << "Type of Information missing is : Last Name Domestic Student \n";
    }

    // get province separated by comma
    getline(ss, province, ',');
    if (inputMissingChecker(province, line_number_count))
    {
      cout << "Type of Information missing is : Province Domestic Student \n";
    }

    // get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    if (inputMissingChecker(s_cgpa, line_number_count))
    {
      cout << "Type of Information missing is : CGPA Domestic Student \n";
    }

    cgpaDomestic = atof(s_cgpa.c_str());
    // rounding CGPA to 1 decimal pt.
    cgpaDomestic = rounding(cgpaDomestic);
    // get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    if (inputMissingChecker(s_researchScore, line_number_count))
    {
      cout << "Type of Information missing is : Research Score Domestic Student \n";
    }
    researchScoreDomestic = atoi(s_researchScore.c_str());

    DomesticStudent tempStu;
    tempStu.setFirstName(first_Name_Domestic);
    tempStu.setLastName(last_Name_Domestic);
    tempStu.setProvince(province);
    tempStu.setApplicationID(20220000 + line_number_count);
    tempStu.setCGPA(cgpaDomestic);
    tempStu.setResearchScore(researchScoreDomestic);

    // Shouldnt print out anything w current data set
    if (!(tempStu.isCGPAvalid()))
    {
      cout << "Applicant number: " << tempStu.getAppIdNumber() << " has an invalid CGPA";
    }
    if (!(tempStu.isProvinceValid()))
    {
      cout << "Applicant number: " << tempStu.getAppIdNumber() << " has an invalid province specified";
    }

    domesticStudentListObj.insertNode(tempStu);
    line_number_count++;
  }
  // domesticStudentListObj.printList();
  domesticFile.close();

  string line1;
  ifstream internationalFile("international-stu.txt");
  if (!internationalFile.is_open())
  {
    cout << "Unable to open file international.txt" << endl;
    return -1;
  }

  getline(internationalFile, line1);

  int line_number_count_international = 0;
  bool isTypoFound = 0;
  // Creating international student array of objects
  InternationalList internationalStudentListObj;

  while (getline(internationalFile, line1))
  {

    istringstream ss(line1);

    string firstNameInternational, lastNameInternational, country, internationalCGPA, researchScoreInternational, readingScore, listeningScore, speakingScore, writingScore;
    float internationalStudentCGPA_float;
    int internationalResearchScore;
    int reading, listening, speaking, writing;

    getline(ss, firstNameInternational, ',');
    if (inputMissingChecker(firstNameInternational, line_number_count_international))
    {
      cout << "Type of Information missing is : First Name International Student \n";
    }
    formatString_Capital_Lowercase(firstNameInternational);

    getline(ss, lastNameInternational, ',');
    if (inputMissingChecker(lastNameInternational, line_number_count_international))
    {
      cout << "Type of Information missing is : Last Name International Student \n";
    }
    formatString_Capital_Lowercase(lastNameInternational);

    // get country separated by comma
    getline(ss, country, ',');
    if (inputMissingChecker(country, line_number_count_international))
    {
      cout << "Type of Information missing is : Country International Student \n";
    }
    formatString_Capital_Lowercase(country);

    // get cpga separated by comma, and convert string to float
    getline(ss, internationalCGPA, ',');
    if (inputMissingChecker(internationalCGPA, line_number_count_international))
    {
      cout << "Type of Information missing is : CGPA International Student \n";
    }
    internationalStudentCGPA_float = atof(internationalCGPA.c_str());
    internationalStudentCGPA_float = rounding(internationalStudentCGPA_float);
    // get researchScore separated by comma, and convert it to int
    getline(ss, researchScoreInternational, ',');
    if (inputMissingChecker(researchScoreInternational, line_number_count_international))
    {
      cout << "Type of Information missing is : Research Score International Student \n";
    }
    internationalResearchScore = atoi(researchScoreInternational.c_str());

    // get reading, listening, speaking and writing separated by comma, and convert it to int
    getline(ss, readingScore, ',');
    if (inputMissingChecker(readingScore, line_number_count_international))
    {
      cout << "Type of Information missing is : Reading Score International Student \n";
    }
    reading = atoi(readingScore.c_str());

    getline(ss, listeningScore, ',');
    if (inputMissingChecker(listeningScore, line_number_count_international))
    {
      cout << "Type of Information missing is : Listening Score International Student \n";
    }
    listening = atoi(listeningScore.c_str());

    getline(ss, speakingScore, ',');
    if (inputMissingChecker(speakingScore, line_number_count_international))
    {
      cout << "Type of Information missing is : Speaking Score International Student \n";
    }
    speaking = atoi(speakingScore.c_str());

    getline(ss, writingScore, ',');
    if (inputMissingChecker(writingScore, line_number_count_international))
    {
      cout << "Type of Information missing is : Writing Score International Student \n";
    }
    writing = atoi(writingScore.c_str());

    InternationalStudent tempStuInternational;
    tempStuInternational.setFirstName(firstNameInternational);
    tempStuInternational.setLastName(lastNameInternational);
    tempStuInternational.setCountryOrigin(country);
    tempStuInternational.setApplicationID(20220000 + line_number_count + line_number_count_international);
    tempStuInternational.setCGPA(internationalStudentCGPA_float);
    tempStuInternational.setResearchScore(internationalResearchScore);
    tempStuInternational.setToeflScoreHelper(reading, listening, speaking, writing);

    if (!(tempStuInternational.isCountryValidAndInternational()))
    {
      // Checks for India typo.
      if (tempStuInternational.getCountryOrigin() == "Idian")
      {
        if (!(isTypoFound))
        {
          cout << "Typo detected in country name. Replacing \"Idian\" with \"India\" for all applicants." << endl; // for applicant number " << tempStuInternational.getAppIdNumber() << endl;
          isTypoFound = 1;
        }

        tempStuInternational.setCountryOrigin("India");
      }
      else
      {
        cout << "Applicant number: " << tempStuInternational.getAppIdNumber() << " has an invalid country of origin.";
        exit(1);
      }
    }

    if (!(tempStuInternational.isCGPAvalid()))
    {
      cout << "Applicant number: " << tempStuInternational.getAppIdNumber() << " has an invalid CGPA";
    }

    internationalStudentListObj.insertNode(tempStuInternational);

    line_number_count_international++;
  }
  // internationalStudentListObj.printList();

  internationalFile.close();
  cout << "Hello, starting main graduate sorting systems process now!";
  cout << "Please select an option by entering it's corresponding number" << endl;
  // END OF initalization of STUDENTS

  DomesticStudent tempDomStudent;
  InternationalStudent tempIntStudent;

  // total number of applicants + base number, to be used to set Student numbers
  int student_number_of_applicants = 20220000 + line_number_count + line_number_count_international;
  int reading_score_set, listening_score_set, speaking_score_set, writing_score_set;

  while (true)
  {

    int choice, secondChoice, thirdChoice;
    string firstNameChoice, lastNameChoice, firstNameTemp, lastNameTemp;
    float choiceFloat;
    string choiceStr;
    string choiceString;

    cout << "\nMain menu:  " << endl;
    cout << "-=-=-=-=-=-=-=--=-=-=--=-=-=--=-=-=--=-=-=-" << endl;
    cout << "0:  Exit the program" << endl;
    cout << "1:  Search for domestic students via specified field" << endl;
    cout << "2:  Search for international students via specified field" << endl;
    cout << "3:  Insert a new student" << endl;
    cout << "4:  Print out list of all students " << endl;
    cout << "5:  Delete a student" << endl;
    cout << "6:  Delete most/least competetive students" << endl;
    cout << "7:  Merge Domestic Students and International Students & perform operations on merged list" << endl;
    cout << "8:  Perform a unit test: " << endl;
    cout << "9:  CGPA and Research Score averages" << endl;
    cout << "10: Edit student information" << endl;
    cout << "11: Output students that will be admitted and students that failed into seperate text files " << endl;
    cout << ">> ";
    cin >> choice;

    if (cin.fail())
    {
      {
        choice = -1;
        cout << "Error, invalid entry.\n\n";
      }
      cin.clear(); // Clears any error flags
      cin.ignore(1000, '\n');
    }

    switch (choice)
    {

    case -1:
      cout << "Please select an option by entering it's corresponding number" << endl;
      cout << "Valid input numbers are between \"0\" to \"11\"" << endl;
      continue;

    case 0:
      exit(1);

    case 1:
      cout << "Would you like to search domestic students via:\n"
              "1. CGPA \n"
              "2. Application ID\n"
              "3. Research score\n"
              "4. Student's name\n"
           << endl;
      cout << ">> ";
      cin >> choice;
      if (choice == 1)
      {
        cout << "Enter CGPA which youd like to search for: " << endl;
        cout << ">> ";
        cin >> choiceFloat;
        domesticStudentListObj.searchDomesticCGPA(choiceFloat);
      }
      else if (choice == 2)
      {
        cout << "Enter application ID for which you'd like to search for: " << endl;
        cout << ">> ";
        cin >> secondChoice;
        domesticStudentListObj.searchDomesticApplicationID(secondChoice);
      }
      else if (choice == 3)
      {
        cout << "Enter research score for which you'd like to search for: " << endl;
        cout << ">> ";
        cin >> secondChoice;
        domesticStudentListObj.searchDomesticResearchScore(secondChoice);
      }
      else if (choice == 4)
      {
        cout << "Enter Student's first name which youd like to search for: " << endl;
        cout << ">> ";
        cin >> choiceStr;
        choiceStr = formatString_Capital_Lowercase(choiceStr);
        cout << "Enter Student's last name which youd like to search for: " << endl;
        cout << ">> ";
        cin >> choiceString;
        choiceString = formatString_Capital_Lowercase(choiceString);
        domesticStudentListObj.searchDomesticNames(choiceStr, choiceString);
      }

      break;

    case 2:
      cout << "Would you like to search international students via:\n"
              "1. CGPA \n"
              "2. Application ID\n"
              "3. Research score\n"
              "4. Student's name"
           << endl;
      cout << ">> ";
      cin >> choice;
      if (choice == 1)
      {
        cout << "Enter CGPA which youd like to search for: " << endl;
        cout << ">> ";
        cin >> choiceFloat;
        internationalStudentListObj.searchInternationalCGPA(choiceFloat);
      }
      else if (choice == 2)
      {
        cout << "Enter application ID for which you'd like to search for: " << endl;
        cout << ">> ";
        cin >> secondChoice;
        internationalStudentListObj.searchInternationalApplicationID(secondChoice);
      }
      else if (choice == 3)
      {
        cout << "Enter research score for which you'd like to search for: " << endl;
        cout << ">> ";
        cin >> secondChoice;
        internationalStudentListObj.searchInternationalResearchScore(secondChoice);
      }
      else if (choice == 4)
      {
        cout << "Enter Student's first name which youd like to search for: " << endl;
        cout << ">> ";
        cin >> choiceStr;
        choiceStr = formatString_Capital_Lowercase(choiceStr);
        cout << "Enter Student's last name which youd like to search for: " << endl;
        cout << ">> ";
        cin >> choiceString;
        choiceString = formatString_Capital_Lowercase(choiceString);
        internationalStudentListObj.searchInternationalNames(choiceStr, choiceString);
      }
      break;
    case 3:
      cout << "Would you like to insert a new:\n"
              "1. Domestic student \n"
              "2. International student"
           << endl;
      cout << ">> ";
      cin >> choice;

      if (choice == 1)
      {
        cout << "Enter the domestic student information which you'd like to insert: " << endl;

        cout << "Please enter the students first name: " << endl;
        cout << ">> ";
        cin >> choiceStr;
        choiceStr = formatString_Capital_Lowercase(choiceStr);
        tempDomStudent.setFirstName(choiceStr);

        cout << "Please enter the students last name: " << endl;
        cout << ">> ";
        cin >> choiceStr;
        choiceStr = formatString_Capital_Lowercase(choiceStr);
        tempDomStudent.setLastName(choiceStr);

        cout << "Please enter the students province: " << endl;
        cout << "Accepted provinces are: NL, PE, NS, NB, QC, ON, MB, SK, AB, BC, YT, NT, NU. " << endl;
        cout << ">> ";
        cin >> choiceStr;
        choiceStr[0] = toupper(choiceStr[0]);
        choiceStr[1] = toupper(choiceStr[1]);

        tempDomStudent.setProvince(choiceStr);

        if (!tempDomStudent.isProvinceValid())
        {
          cout << "Invalid province specified" << endl;
          continue;
        }

        cout << "Please enter the students CGPA: " << endl;
        cout << ">> ";
        cin >> choiceFloat;
        tempDomStudent.setCGPA(rounding(choiceFloat));
        if (!tempDomStudent.isCGPAvalid())
        {
          cout << "Invalid CGPA specified, please enter a number between 0 and 4.3" << endl;
          continue;
        }

        cout << "Please enter the students research score: " << endl;
        cout << ">> ";
        cin >> choiceFloat;
        tempDomStudent.setResearchScore(int(choiceFloat));
        if (tempDomStudent.getResearchScore() > 100 || tempDomStudent.getResearchScore() < 0)
        {
          cout << "Invalid research score specified, please enter a number between 0 and 100" << endl;
          continue;
        }

        tempDomStudent.setApplicationID(student_number_of_applicants);
        student_number_of_applicants += 1;

        domesticStudentListObj.insertNode(tempDomStudent);
      }
      else if (choice == 2)
      {

        cout << "Please enter international student information which you'd like to insert: " << endl;

        cout << "Please enter the students first name: " << endl;
        cout << ">> ";
        cin >> choiceStr;
        choiceStr = formatString_Capital_Lowercase(choiceStr);
        tempIntStudent.setFirstName(choiceStr);

        cout << "Please enter the students last name: " << endl;
        cout << ">> ";
        cin >> choiceStr;
        choiceStr = formatString_Capital_Lowercase(choiceStr);
        tempIntStudent.setLastName(choiceStr);

        cout << "Please enter the students CGPA: " << endl;
        cout << ">> ";
        cin >> choiceFloat;
        tempIntStudent.setCGPA(rounding(choiceFloat));
        if (!(tempIntStudent.isCGPAvalid()))
        {
          cout << "Invalid CGPA specified, please enter a number between 0 and 4.3" << endl;
          continue;
        }

        cout << "Please enter the students research score: " << endl;
        cout << ">> ";
        cin >> choice;
        if (choice > 100 || choice < 0)
        {
          cout << "Invalid research score specified, please enter a number between 1 and 100" << endl;
          continue;
        }
        tempIntStudent.setResearchScore(choice);

        cout << "Please enter the students country of origin: " << endl;
        cout << "Accepted answers are the following: China, India, Iran, Korea" << endl;
        cout << ">> ";
        cin >> choiceStr;

        choiceStr = formatString_Capital_Lowercase(choiceStr);
        tempIntStudent.setCountryOrigin(choiceStr);
        if (!(tempIntStudent.isCountryValidAndInternational()))
        {
          cout << "Invalid country entered. " << endl;
          continue;
        }

        cout << "Please enter the students reading score: " << endl;
        cout << ">> ";
        cin >> reading_score_set;

        cout << "Please enter the students listening score: " << endl;
        cout << ">> ";
        cin >> listening_score_set;

        cout << "Please enter the students speaking score: " << endl;
        cout << ">> ";
        cin >> speaking_score_set;

        cout << "Please enter the students writing score: " << endl;
        cout << ">> ";
        cin >> writing_score_set;

        // tempIntStudent.getToeflScoreobj().setListening(listening_score_set);
        tempIntStudent.setToeflScoreHelper(reading_score_set, listening_score_set, speaking_score_set, writing_score_set);
        // Validity check here:

        if (!(tempIntStudent.getToeflScoreobj().isToeflCorrect()))
        {
          cout << "Please enter TOEFLscore's fields as values between 0 and 30." << endl;
          continue;
        }

        // NOTE: this should be the last thing, as all other fields do validity checks, and may not result in sucessful insertion
        tempIntStudent.setApplicationID(student_number_of_applicants);
        student_number_of_applicants += 1;

        internationalStudentListObj.insertNode(tempIntStudent);
      }
      break;

    case 4:
      cout << "Would you like to print:\n"
              "1. Domestic student list \n"
              "2. International student list\n"
              "3. Merged student list"
           << endl;
      cout << ">> ";
      cin >> choice;
      if (choice == 1)
      {
        domesticStudentListObj.printList();
      }
      else if (choice == 2)
      {
        internationalStudentListObj.printList();
      }
      else if (choice == 3)
      {
        cout << "Priting in order of: " << endl;
        cout << "Research score, CGPA, Student Number, Country/Province of origin, TOEFL status, Name" << endl;
        studentList.mergeLists(&domesticStudentListObj, &internationalStudentListObj);
        cout << &studentList;
      }
      break;

    case 5:
      cout << "Would you like to delete:\n"
              "1. all Domestic students with specified name\n"
              "2. all International student with specified name\n"
              "3. all Students with specified CGPA\n"
              "4. all Students with specified research score"
           << endl;
      cout << ">> ";
      cin >> choice;
      if (choice == 1)
      {
        cout << "Please enter the students first name: " << endl;
        cout << ">> ";
        cin >> firstNameChoice;
        cout << "Please enter the students last name: " << endl;
        cout << ">> ";
        cin >> lastNameChoice;
        firstNameTemp = formatString_Capital_Lowercase(firstNameChoice);
        lastNameTemp = formatString_Capital_Lowercase(lastNameChoice);
        if (domesticStudentListObj.searchDomesticNames(firstNameTemp, lastNameTemp) == 1)
        {
          cout << "Name found -- deleting from list" << endl;
          domesticStudentListObj.deleteDomestic(firstNameChoice, lastNameChoice);
        }
      }
      else if (choice == 2)
      {

        cout << "Please enter the students first name: " << endl;
        cout << ">> ";
        cin >> firstNameChoice;
        cout << "Please enter the students last name: " << endl;
        cout << ">> ";
        cin >> lastNameChoice;
        firstNameTemp = formatString_Capital_Lowercase(firstNameChoice);
        lastNameTemp = formatString_Capital_Lowercase(lastNameChoice);
        if (internationalStudentListObj.searchInternationalNames(firstNameTemp, lastNameTemp) == 1)
        {
          cout << firstNameTemp << " " << lastNameTemp << " was found -- deleting from list." << endl;
          internationalStudentListObj.deleteInternational(firstNameChoice, lastNameChoice);
        }
      }
      else if (choice == 3)
      {
        cout << "Would you like to delete from (1)Domestic or (2)International" << endl;
        cin >> secondChoice;
        if (secondChoice == 1)
        {
          cout << "What value for CGPA would you like to remove from list: " << endl;
          cin >> choiceFloat;
          if (domesticStudentListObj.searchDomesticCGPA(choiceFloat) == 1)
          {
            cout << "Students with " << choiceFloat << " CGPA were found -- deleting all from list." << endl;
            domesticStudentListObj.deleteDomesticCGPA(choiceFloat);
          }
        }
        if (secondChoice == 2)
        {
          cout << "What value for CGPA would you like to remove from list: " << endl;
          cin >> choiceFloat;
          if (internationalStudentListObj.searchInternationalCGPA(choiceFloat) == 1)
          {
            cout << "Students with " << choiceFloat << " CGPA were found -- deleting all from list." << endl;
            internationalStudentListObj.deleteInternationalCGPA(choiceFloat);
          }
        }
      }
      else if (choice == 4)
      {
        cout << "Would you like to delete from (1)Domestic or (2)International" << endl;
        cin >> secondChoice;
        if (secondChoice == 1)
        {
          cout << "What value for research score would you like to remove from list: " << endl;
          cin >> thirdChoice;
          if (domesticStudentListObj.searchDomesticResearchScore(thirdChoice) == 1)
          {
            cout << "Students with " << thirdChoice << " research score were found -- deleting all from list." << endl;
            domesticStudentListObj.deleteDomesticRS(thirdChoice);
          }
        }
        if (secondChoice == 2)
        {
          cout << "What value for research score would you like to remove from list: " << endl;
          cin >> thirdChoice;
          if (internationalStudentListObj.searchInternationalResearchScore(thirdChoice) == 1)
          {
            cout << "Students with " << thirdChoice << " research score were found -- deleting all from list." << endl;
            internationalStudentListObj.deleteInternationalRS(thirdChoice);
          }
        }
      }
      break;

  
    case 6:
      cout << "Would you like to delete most and least competetive students from:\n"
              "1. Domestic list \n"
              "2. International list"
           << endl;
      cout << ">> ";
      cin >> choice;
      if (choice == 1)
      {
        cout << "Deleting most competetive domestic student, " << domesticStudentListObj.getHead()->getFirstName() << " " << domesticStudentListObj.getHead()->getLastName() << endl;
        cout << "and least competitive domestic student, " << domesticStudentListObj.getTail()->getFirstName() << " " << domesticStudentListObj.getTail()->getLastName() << "." << endl;
        domesticStudentListObj.deleteDomesticHeadAndTail();
      }
      else if (choice == 2)
      {
        cout << "Deleting most competetive international student, " << internationalStudentListObj.getHead()->getFirstName() << " " << internationalStudentListObj.getHead()->getLastName() << endl;
        cout << "and least competitive international student, " << internationalStudentListObj.getTail()->getFirstName() << " " << internationalStudentListObj.getTail()->getLastName() << "." << endl;
        internationalStudentListObj.deleteInternationalHeadAndTail();
      }
      break;

    case 7:
      cout << "Merging lists together and printing out sorted Student Objects" << endl;
      studentList.mergeLists(&domesticStudentListObj, &internationalStudentListObj);

      if (choice == 0)
      {
        exit(1);
      }
      while (choice != 1)
      {
        //internal menu of merge
        cout << "\nWhat operations would you like to perform on the merged list? \n"
                "0. Exit program\n"
                "1. Exit to main menu\n"
                "2. Print list \n"
                "3. Delete element\n"
                "4. Delete head and tail\n"
                "5. Search\n"
                "6. Insert\n"
                "7. Print by Cutoff for CGPA & Research Score"
             << endl;
        cout << ">> ";
        cin >> choice;
        if (cin.fail())
        {
          {
            choice = -1;
            cout << "Error, invalid entry.\n\n";
          }
          cin.clear(); // Clears any error flags
          cin.ignore(1000, '\n');
        }
        
        if (choice == 0)
        {
          exit(1);
        }
        else if (choice == 1)
        {
          break;
        }
        else if (choice == 2)
        {
          cout << &studentList;
        }
        else if (choice == 3)
        {

          cout << "Please enter the students first name: " << endl;
          cout << ">> ";
          cin >> firstNameChoice;
          cout << "Please enter the students last name: " << endl;
          cout << ">> ";
          cin >> lastNameChoice;
          firstNameTemp = formatString_Capital_Lowercase(firstNameChoice);
          lastNameTemp = formatString_Capital_Lowercase(lastNameChoice);

          if (studentList.searchNames(firstNameTemp, lastNameTemp) == 1)
          {
            cout << "Name found -- deleting from list" << endl;
            studentList.deleteNode(firstNameChoice, lastNameChoice);
          }
        }
        else if (choice == 4)
        {
          studentList.deleteHeadAndTail();
        }
        else if (choice == 5)
        {
          cout << "Please enter the students first name: " << endl;
          cout << ">> ";
          cin >> firstNameChoice;
          cout << "Please enter the students last name: " << endl;
          cout << ">> ";
          cin >> lastNameChoice;
          firstNameTemp = formatString_Capital_Lowercase(firstNameChoice);
          lastNameTemp = formatString_Capital_Lowercase(lastNameChoice);

          studentList.searchNames(firstNameTemp, lastNameTemp);
        }
        else if (choice == 6)
        {
          cout << "Would you like to insert a new:\n"
                  "1. Domestic student \n"
                  "2. International student"
               << endl;
          cout << ">> ";
          int choice2;
          cin >> choice2;

          if (choice2 == 1)
          {
            
            cout << "Enter the domestic student information which you'd like to insert: " << endl;

            cout << "Please enter the students first name: " << endl;
            cout << ">> ";
            cin >> choiceStr;
            choiceStr = formatString_Capital_Lowercase(choiceStr);
            tempDomStudent.setFirstName(choiceStr);

            cout << "Please enter the students last name: " << endl;
            cout << ">> ";
            cin >> choiceStr;
            choiceStr = formatString_Capital_Lowercase(choiceStr);
            tempDomStudent.setLastName(choiceStr);

            cout << "Please enter the students province: " << endl;
            cout << "Accepted provinces are: NL, PE, NS, NB, QC, ON, MB, SK, AB, BC, YT, NT, NU. " << endl;
            cout << ">> ";
            cin >> choiceStr;
            choiceStr[0] = toupper(choiceStr[0]);
            choiceStr[1] = toupper(choiceStr[1]);

            tempDomStudent.setProvince(choiceStr);

            if (!tempDomStudent.isProvinceValid())
            {
              cout << "Invalid province specified" << endl;
              continue;
            }

            cout << "Please enter the students CGPA: " << endl;
            cout << ">> ";
            cin >> choiceFloat;
            tempDomStudent.setCGPA(rounding(choiceFloat));
            if (!tempDomStudent.isCGPAvalid())
            {
              cout << "Invalid CGPA specified, please enter a number between 0 and 4.3" << endl;
              continue;
            }

            cout << "Please enter the students research score: " << endl;
            cout << ">> ";
            cin >> choiceFloat;
            tempDomStudent.setResearchScore(int(choiceFloat));
            if (tempDomStudent.getResearchScore() > 100 || tempDomStudent.getResearchScore() < 0)
            {
              cout << "Invalid research score specified, please enter a number between 0 and 100" << endl;
              continue;
            }

            tempDomStudent.setApplicationID(student_number_of_applicants);
            student_number_of_applicants += 1;

            Node nodelist;
            nodelist.studentObj = tempDomStudent;
            studentList.insert(nodelist);
          }
          else if (choice2 == 2)
          {

            cout << "Please enter international student information which you'd like to insert: " << endl;

            cout << "Please enter the students first name: " << endl;
            cout << ">> ";
            cin >> choiceStr;
            choiceStr = formatString_Capital_Lowercase(choiceStr);
            tempIntStudent.setFirstName(choiceStr);

            cout << "Please enter the students last name: " << endl;
            cout << ">> ";
            cin >> choiceStr;
            choiceStr = formatString_Capital_Lowercase(choiceStr);
            tempIntStudent.setLastName(choiceStr);

            cout << "Please enter the students CGPA: " << endl;
            cout << ">> ";
            cin >> choiceFloat;
            tempIntStudent.setCGPA(rounding(choiceFloat));
            if (!(tempIntStudent.isCGPAvalid()))
            {
              cout << "Invalid CGPA specified, please enter a number between 0 and 4.3" << endl;
              continue;
            }

            cout << "Please enter the students research score: " << endl;
            cout << ">> ";
            cin >> choice;
            if (choice > 100 || choice < 0)
            {
              cout << "Invalid research score specified, please enter a number between 1 and 100" << endl;
              continue;
            }
            tempIntStudent.setResearchScore(choice);

            cout << "Please enter the students country of origin: " << endl;
            cout << "Accepted answers are the following: China, India, Iran, Korea" << endl;
            cout << ">> ";
            cin >> choiceStr;

            choiceStr = formatString_Capital_Lowercase(choiceStr);
            tempIntStudent.setCountryOrigin(choiceStr);
            if (!(tempIntStudent.isCountryValidAndInternational()))
            {
              cout << "Invalid country entered. " << endl;
              continue;
            }

            cout << "Please enter the students reading score: " << endl;
            cout << ">> ";
            cin >> reading_score_set;

            cout << "Please enter the students listening score: " << endl;
            cout << ">> ";
            cin >> listening_score_set;

            cout << "Please enter the students speaking score: " << endl;
            cout << ">> ";
            cin >> speaking_score_set;

            cout << "Please enter the students writing score: " << endl;
            cout << ">> ";
            cin >> writing_score_set;

            // tempIntStudent.getToeflScoreobj().setListening(listening_score_set);
            tempIntStudent.setToeflScoreHelper(reading_score_set, listening_score_set, speaking_score_set, writing_score_set);
            // Validity check here:

            if (!(tempIntStudent.getToeflScoreobj().isToeflValid()))
            {
              cout << "Only valid toeflscores can be inputted. Must be minimum 93, with 20 each field. " << endl;
              continue;
            }

            // NOTE: this should be the last thing, as all other fields do validity checks, and may not result in sucessful insertion
            tempIntStudent.setApplicationID(student_number_of_applicants);
            student_number_of_applicants += 1;

            Node nodelist;
            nodelist.studentObj = tempIntStudent;
            studentList.insert(nodelist);
          }
          
        }
        else if(choice == 7) 
        {
          //printing out by cutoff
            choiceFloat = -1;
            choiceInt =-1;

            while(choiceFloat < 0 || choiceFloat > 100) {
              cout<<"Enter a cgpa for the cutoff "<<endl;
              cin>>choiceFloat;
            }
            while(choiceInt < 0 || choiceInt > 100) {
                cout<<"Enter a Research Score for the cutoff "<<endl;
                cin>>choiceInt;
            }
              studentList.printCutCGPA(choiceFloat,choiceInt);

        }
      }
      break;

    case 8:

      cout << "Running Unit Tests..." << endl;

      unit_test(&domesticStudentListObj, &internationalStudentListObj, student_number_of_applicants, &studentList);

      break;

    case 9:

      cout << endl
           << "TOEFL: " << endl;
      internationalStudentListObj.averageTOEFL();

      cout << endl
           << "Domestic/International/Total: " << endl;
      avRSTotal = (domesticStudentListObj.averageDomesticRS() + internationalStudentListObj.averageInternationalRS()) / 2;
      avCGPATotal = (domesticStudentListObj.averageDomesticCGPA() + internationalStudentListObj.averageInternationalCGPA()) / 2;
      cout << "There are 200 total students with a Total average CGPA is " << avCGPATotal << endl;
      cout << "There are 200 total students with a Total average Research Score is " << avRSTotal << endl;
      break;

    case 10:
      // edit domestic info
      cout << "Would you like to edit a:\n"
              "1. Domestic student \n"
              "2. International student"
           << endl;
      cout << ">> ";
      cin >> choice;
      if (choice == 1)
      {
        domesticStudentListObj.editDomestic();
      }
      else if (choice == 2)
      {
        internationalStudentListObj.editInternational();
      }

      break;

    case 11:

      cout << "Outputing the top Students who will be admitted to SFU (See file SuccessfulStudents.txt) " << endl;
      // function to output successful students
      SuccessfulStudents.open("SuccessfulStudents.txt", ios::out);

      if (SuccessfulStudents.is_open())
      {

        studentList.isSuccessful(SuccessfulStudents, &domesticStudentListObj, &internationalStudentListObj) << endl;
        SuccessfulStudents.close();
      }

      cout << "Outputing the Students that were not successful (See file FailedStudents) " << endl;

      FailedStudents.open("FailedStudents.txt", ios::out);
      if (FailedStudents.is_open())
      {

        studentList.failedStudents(FailedStudents, &domesticStudentListObj, &internationalStudentListObj) << endl;
        FailedStudents.close();
      }
      break;

    default:
      // Continues looping
      continue;
    }
  }

  return 0;
}
