// header file student.hpp to declare your classes

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string> //you will have to use string in C++
#include <iostream>
#include <cassert> //do we need this????
using namespace std;

// define classes for the all merge
class InternationalStudent;
class DomesticStudent;
class InternationalList;
class DomesticList;

class Student
{

private:
    string firstName, lastName, x, y;
    float CGPA;
    int researchScore, app_id_number;
    string region;

public:
    Student();              // default constructor
    Student(Student &stu1); // copy construcotr
    Student(string firstName, string lastName, float CGPA, int researchScore, int app_id_number);

    // Returns true if valid, false if invalid
    bool isCGPAvalid() const;
    // bool isResearchScoreValid() const;

    // Getter functions
    string getFirstName() const;
    string getLastName() const;
    float getCGPA() const;
    int getResearchScore() const;
    int getAppIdNumber() const;
    string getRegion() const;

    // setter functions
    void setFirstName(string firstName);
    void setLastName(string nameLast);
    void setCGPA(float CGPA);
    void setResearchScore(int rScore);
    void setApplicationID(int app_id_number);
    void setRegion(string region);

    // Merge linked Lists
    //  Student Clone(DomesticList *SortedDList, InternationalList *SortedIList);   //copy the old LL
    Student *SortedMerge(Student *a, Student *b);          // combines both and sorts in order
    void MoveNode(Student **destRef, Student **sourceRef); // helper for SortedMerge
    void printList(Student *newList);
    virtual void virtualPrint();

    // Innovation
    bool FilterStudents();

    // friend functions
    // returns 0 if same, 1 if stu1 is greater, 2 if stu 2 is greater.
    friend int compareCGPA(const Student &stu1, const Student &stu2);
    // returns 0 if same, 1 if stu1 is greater, 2 if stu 2 is greater.
    friend int compareResearchScore(const Student &stu1, const Student &stu2);
    // returns 0 if same, 1 if stu1 is greater, 2 if stu 2 is greater.
    friend int compareFirstName(const Student &stu1, const Student &stu2);
    // returns 0 if same, 1 if stu1 is greater, 2 if stu 2 is greater.
    friend int compareLastName(const Student &stu1, const Student &stu2);
};

class DomesticStudent : public Student
{

private:
    string province;

public:
    DomesticStudent *next;
    DomesticStudent *previous;

    DomesticStudent(); // Default constructor

    // DomesticStudent(string firstName, string lastName, float CGPA, int researchScore, int app_id_number, string province);
    DomesticStudent(const string &province, string firstName, string lastName, float CGPA, int researchScore, int app_id_number); // non-default constructor

    // getters and setters
    void setIndex(const int &_index);
    string getProvince() const;
    void setProvince(const string &province);

    // returns TRUE if province is valid, FALSE if invalid
    bool isProvinceValid() const;
    // operator overload
    friend ostream &operator<<(ostream &COUT, DomesticStudent &_domesticStudent);

    void virtualPrint();
    // returns 1 if Student current is greater, if next student is greater returns returns -1. if equal 0.

    // compares provinces
    friend int compareProvince(string province1, string province2);
};

class ToeflScore
{

private:
    int reading;
    int listening;
    int speaking;
    int writing;

public:
    ToeflScore();                                                                                  // default constructor
    ToeflScore(const int &listening, const int &reading, const int &speaking, const int &writing); // non-default constructor
    // getter functions
    int getReading() const;
    int getListening() const;
    int getSpeaking() const;
    int getWriting() const;
    int getTotalSum() const;

    // setter functions
    void setReading(const int &reading);
    void setListening(const int &listening);
    void setSpeaking(const int &speaking);
    void setWriting(const int &writing);
    void setTotalSum(int readingS, int listeningS, int speakingS, int writingS);

    bool isToeflCorrect(); // removes toefl scores with low scores
    bool isToeflValid();

    // Operator Overload for the TOEFL class
    friend ostream &operator<<(ostream &TOEFL_COUT, ToeflScore &TOEFL_InternationalStudent);
};
class InternationalStudent : public Student
{

private:
    // instantiation of TOEFLScore for international student
    ToeflScore InternationalStuToeflScore;
    string countryOrigin;

public:
    InternationalStudent *next;
    InternationalStudent *previous;
    
    InternationalStudent();                                                                                                                 // Default constructor
    InternationalStudent(const string &countryOrigin, string firstName, string lastName, float CGPA, int researchScore, int app_id_number); // non-default constructor

    // getter functions
    string getCountryOrigin() const;
    ToeflScore getToeflScoreobj() const;
    void setToeflScoreHelper(const int &reading, const int &listening, const int &speaking, const int &writing);

    InternationalStudent* getNext();
    InternationalStudent* getPrevious();
    // setter function
    void setCountryOrigin(const string &_countryOrigin);
    // void setTOEFLscore(const int& _TOEFLscore);

    void virtualPrint();

    // returns true if country is valid.
    bool isCountryValidAndInternational() const;

    // compares countries
    friend int compareCountry(string country1, string country2);
    
    //  operator overload
    friend ostream &operator<<(ostream &_COUT, InternationalStudent &_internationalStudent);
};

class DomesticList
{
public:
    DomesticList();
    ~DomesticList();

    DomesticStudent *getHead() const;
    DomesticStudent *getTail() const;
    // void setHead(DomesticStudent *student);

    void insertNode(DomesticStudent nextStudent);

    void printList();

    // return 1 if sucess, 0 if fails
    bool searchDomesticApplicationID(int id);
    // return 1 if sucess, 0 if fails
    bool searchDomesticCGPA(float cgpa);
    // return 1 if sucess, 0 if fails
    bool searchDomesticResearchScore(int researchScore);
    // return 1 if sucess, 0 if fails
    bool searchDomesticNames(string firstName, string lastName);

    bool searchProvince(string province);

    // prompt UI for first name, last name
    // return 1 if sucess, 0 if fails
    void deleteDomestic(string firstName, string lastName);

    // return 1 if sucess, 0 if fails (ie. Empty list, single element list)
    // void deleteDomesticHeadAndTail(class DomesticStudent* head);
    void deleteDomesticHeadAndTail();
    // bool deleteDomesticTail(class DomesticList* head);

    float averageDomesticCGPA(); // calculates the average cgpa for domestic
    int averageDomesticRS();     // calculates the average rs score for domestic
    void deleteDomesticCGPA(float CGPA);    //deletes domestic cgpa
    void deleteDomesticRS(int researchScore);
    
    void editDomestic();                    // edit domestic applicants
    string stringFormat(string &s);         // formats strings
    string provinceFormat(string &s);       // formats provinces
    bool isProvinceValid(string &province); // checks provinces

    friend int isStudentCurrentGreater(DomesticStudent *stu1, DomesticStudent *stu2);

private:
    DomesticStudent *head;
    DomesticStudent *tail;
};

class InternationalList
{
public:
    InternationalList();
    ~InternationalList()
    {
        InternationalStudent *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            delete (temp->previous);
        }
        delete (temp);
    };

    InternationalStudent *getHead() const;
    InternationalStudent *getTail() const;
    void printList();
    void insertNode(InternationalStudent nextStudent);
    // return 1 if sucess, 0 if fails
    bool searchInternationalApplicationID(int id);
    // return 1 if sucess, 0 if fails
    bool searchInternationalCGPA(float cgpa);
    // return 1 if sucess, 0 if fails
    bool searchInternationalResearchScore(int researchScore);
    // return 1 if sucess, 0 if fails
    bool searchInternationalNames(string firstName, string lastName);

    // prompt UI for first name, last name
    // return 1 if sucess, 0 if fails
    void deleteInternational(string firstName, string lastName);

    // return 1 if sucess, 0 if fails (ie. Empty list, single element list)
    // void deleteInternationalHeadAndTail(class InternationalStudent* head);
    void deleteInternationalHeadAndTail();
    // bool deleteInternationalTail(class InternationalList* head);

    float averageInternationalCGPA(); // calculates the average cgpa for International
    int averageInternationalRS();     // calculates the average rs score for International
    void deleteInternationalCGPA(float CGPA);
    void deleteInternationalRS(int researchScore);

    int averageTOEFL(); //calculates avergae TOEFL values
    void editInternational();       // edits international information
    string stringFormat(string &s); // formats strings

    friend int isStudentCurrentGreater(InternationalStudent *stu1, InternationalStudent *stu2);

private:
    InternationalStudent *head;
    InternationalStudent *tail;
};

#endif