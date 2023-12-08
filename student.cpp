// student.cpp to implement your classes
#include "student.hpp"
#include "mergedList.hpp"
#include <iostream>
#include <string>

using namespace std;

// CODE FOR STUDENT CLASS

// default constructors
Student::Student()
{
    firstName = "John";
    lastName = "Doe";
    CGPA = 0;               // random value
    researchScore = 0;       // random value
    app_id_number = 20219999; // Before starting indicies
}
// Non default constructor
Student::Student(string firstName, string lastName, float CGPA, int researchScore, int app_id_number)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->CGPA = CGPA;
    this->researchScore = researchScore;
    this->app_id_number = app_id_number;
}
void Student::virtualPrint()
{
    cout << "Research Score:" << this->getResearchScore();
    if (this->getResearchScore() != 100)
    {
        cout << " ";
    }
    cout << " ";
    if (this->getCGPA() == 1 || this->getCGPA() == 2 || this->getCGPA() == 3 || this->getCGPA() == 4)
    {
        cout << "CGPA"
             << " " << this->getCGPA() << ".0 ID:" << this->getAppIdNumber();
    }
    else
    {
        cout << "CGPA"
             << " " << this->getCGPA() << " ID:" << this->getAppIdNumber();
    }
    cout << " Name: " << this->getFirstName() << " " << this->getLastName() << " ";
    /*
    
    cout << "Name: " << this->getFirstName() << ' ' << this->getLastName() << endl;
    cout << "CGPA: " << this->getCGPA() << endl;
    cout << "Research Score: " << this->getResearchScore() << endl;
    cout << "Application ID Number: " << this->getAppIdNumber() << endl;*/
}

// Setters:
void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Student::setCGPA(float CGPA)
{
    this->CGPA = CGPA;
}

void Student::setResearchScore(int rScore)
{
    this->researchScore = rScore;
}

void Student::setApplicationID(int app_id_number)
{
    this->app_id_number = app_id_number;
}

void Student::setRegion(string region)
{
    this->region = region;
}

// copy constructor
Student::Student(Student &stu1)
{
    firstName = stu1.getFirstName();
    lastName = stu1.getLastName();
    CGPA = stu1.getCGPA();
    researchScore = stu1.getResearchScore();
    app_id_number = stu1.getAppIdNumber();
}

// friend functions - to compare CGPA, Research score, name
// Returns 1 - stu1 is greater, -1 stu2 is greater, 0 - equal
int compareCGPA(const Student &stu1, const Student &stu2)
{
    float CGPA_student1 = stu1.getCGPA();
    float CGPA_student2 = stu2.getCGPA();
    if (CGPA_student1 == CGPA_student2)
    {
        return 0;
    }
    else if (CGPA_student1 > CGPA_student2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

// Returns 1 - stu1 is greater, -1 stu2 is greater, 0 - equal
int compareResearchScore(const Student &stu1, const Student &stu2)
{
    float RS_student1 = stu1.getResearchScore();
    float RS_student2 = stu2.getResearchScore();
    if (RS_student1 == RS_student2)
    {
        return 0;
    }
    else if (RS_student1 > RS_student2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

// Returns 1 - stu1 is greater, -1 stu2 is greater, 0 - equal
// NOTE: We assume that blank characters are HIGHER priority then existing letters. Ie
// Aaron compared to Aarona would result in AARON being the alphabetically greater name.
int compareFirstName(const Student &stu1, const Student &stu2)
{
    string FirstNameStudent1 = stu1.getFirstName();
    string FirstNameStudent2 = stu2.getFirstName();
    int numOfComparasons = 0; // This will be whichever length is greater between Length of student names
    int lenStu1 = FirstNameStudent1.length();
    int lenStu2 = FirstNameStudent2.length();
    if (lenStu1 > lenStu2)
    {
        numOfComparasons = lenStu1;
    }
    else
    {
        numOfComparasons = lenStu2;
    }
    for (int i = 0; i < numOfComparasons; i++)
    {
        if (FirstNameStudent1[i] == FirstNameStudent2[i])
        {
            continue; // if letter is same
        }
        else if (FirstNameStudent1[i] > FirstNameStudent2[i])
        {
            // this case: stu1 is greater
            return 1;
        }
        else
        {
            return -1;
        }
    }
    // assuming all elements are equal, returns 0.
    return 0;
}

// Returns 1 - stu1 is greater, -1 stu2 is greater, 0 - equal
int compareLastName(const Student &stu1, const Student &stu2)
{
    string LastNameStudent1 = stu1.getLastName();
    string LastNameStudent2 = stu2.getLastName();
    int numOfComparasons = 0; // This will be whichever length is greater between Length of student names
    int lenStu1 = LastNameStudent1.length();
    int lenStu2 = LastNameStudent2.length();
    if (lenStu1 > lenStu2)
    {
        numOfComparasons = lenStu1;
    }
    else
    {
        numOfComparasons = lenStu2;
    }
    for (int i = 0; i < numOfComparasons; i++)
    {
        if (LastNameStudent1[i] == LastNameStudent2[i])
        {
            continue; // if letter is same
        }
        else if (LastNameStudent1[i] > LastNameStudent2[i])
        {
            // this case: stu1 is greater
            return 1;
        }
        else
        {
            return -1;
        }
    }
    // assuming all elements are equal, returns 0.
    return 0;
}

// returns true if valid, else returns false
bool Student::isCGPAvalid() const
{
    if (CGPA >= 0 && CGPA < 4.35)
    { // since everything under 4.35 IS ROUNDED DOWN TO 4.3- which is a valid CGPA on SFU scale
        return true;
    }
    else
    {
        return false;
    }
}

// getters
string Student::getFirstName() const
{
    return firstName;
}

string Student::getLastName() const
{
    return lastName;
}

float Student::getCGPA() const
{
    return CGPA;
}

int Student::getResearchScore() const
{
    return researchScore;
}

int Student::getAppIdNumber() const
{
    return app_id_number; // TODO: change naming of Student Number to application id/app id as it is more descriptive -Anton
}

string Student::getRegion() const
{
    return region;
}

// END FOR CODE FOR STUDENT CLASS

// CODE FOR DOMESTIC STUDENT

DomesticStudent::DomesticStudent() : Student()
{
    // sets default to NULL so that our validity checker will check if the provience is within list of valid provinces OR NULL
    next = NULL;
    previous = NULL;
    province = "None";
}

// non-default constructor
DomesticStudent::DomesticStudent(const string &province, string firstName, string lastName, float CGPA, int researchScore, int app_id_number)
{
    this->province = province;

    // from the student parent class, calls functions due to private member variables of the student parent class
    this->setFirstName(firstName);
    this->setLastName(lastName);
    this->setCGPA(CGPA);
    this->setResearchScore(researchScore);
    this->setApplicationID(app_id_number);
}
void DomesticStudent::virtualPrint()
{
    cout << " Province: " << this->getProvince() << " ";
    
    /*
    cout << this->getResearchScore();
    if (this->getResearchScore() != 100)
    {
        cout << " ";
    }

    if (this->getCGPA() == 1 || this->getCGPA() == 2 || this->getCGPA() == 3 || this->getCGPA() == 4)
    {
        cout << ""
             << " " << this->getCGPA() << ".0 " << this->getAppIdNumber() << " " << this->getProvince() << "    " << "N/A  "<< this->getFirstName() << " " << this->getLastName();
    }
    else
    {
        cout << ""
             << " " << this->getCGPA() << " " << this->getAppIdNumber() << " " << this->getProvince() << "    " << "N/A  " <<this->getFirstName() << " " << this->getLastName();
    }
    cout << endl;*/
    
}

// getters/setters:
string DomesticStudent::getProvince() const
{
    return this->province;
}

void DomesticStudent::setProvince(const string &_province)
{
    this->province = _province;
}

// compares province, returns 1 if prov1 > prov2, returns -1 if prov 2 is greater
int compareProvince(string province1, string province2)
{

    int numOfComparasons = 0; // This will be whichever length is greater between Length of student names
    int lenStu1 = province1.length();
    int lenStu2 = province2.length();
    if (lenStu1 > lenStu2)
    {
        numOfComparasons = lenStu1;
    }
    else
    {
        numOfComparasons = lenStu2;
    }
    for (int i = 0; i < numOfComparasons; i++)
    {
        if (province1[i] == province2[i])
        {
            continue; // if letter is same
        }
        else if (province1[i] > province2[i])
        {
            // this case: stu1 is greater
            return 1;
        }
        else
        {
            return -1;
        }
    }
    return 0;
}

// Validity check
// TODO: impliment this with a loop/switch statement & string array for all provinces
bool DomesticStudent::isProvinceValid() const
{
    if (province == "AB" || province == "BC" || province == "MB" || province == "NB" || province == "QC" || province == "ON" || province == "NU" || province == "NL" || province == "NS" || province == "NT" || province == "SK" || province == "YT" || province == "PE")
    {
        return true;
    }
    return false;
}

// Overloading << to print out class information (DomesticStudent)
ostream &operator<<(ostream &COUT, DomesticStudent &_domesticStudent)
{
    // prints out all information in the domestic student object
    COUT << "First Name: " << _domesticStudent.getFirstName() << endl;
    COUT << "Last Name: " << _domesticStudent.getLastName() << endl;
    COUT << "CGPA: " << _domesticStudent.getCGPA() << endl;
    COUT << "Research Score: " << _domesticStudent.getResearchScore() << endl;
    COUT << "Application ID Number: " << _domesticStudent.getAppIdNumber() << endl;
    COUT << "Province of Student: " << _domesticStudent.getProvince() << endl;

    return COUT;
}

// CODE FOR DOMESTICSTUDENT ENDS

// CODE FOR INTERNATIONALSTUDENT BEGINS

// International Student Constructor
InternationalStudent::InternationalStudent() : Student()
{

    this->countryOrigin = "None";
    InternationalStuToeflScore = ToeflScore();
    next = NULL;
    previous = NULL;
    //  this->InternationalStuToeflScore.setTotalSum(0,0,0,0);
}

InternationalStudent::InternationalStudent(const string &countryOrigin, string firstName, string lastName, float CGPA, int researchScore, int app_id_number)
{
    this->countryOrigin = countryOrigin;

    // from the student parent class, calls functions due to private member variables of the student parent class
    this->setFirstName(firstName);
    this->setLastName(lastName);
    this->setCGPA(CGPA);
    this->setResearchScore(researchScore);
    this->setApplicationID(app_id_number);
    // this->InternationalStuToeflScore.setTotalSum(10,10,10,10);
}

void InternationalStudent::virtualPrint()
{ // RS GPA # COUNTRY TOEFL NAME printList

    cout << " Country: " << this->getCountryOrigin();
    cout << " TOEFL Score: " << this->getToeflScoreobj().getTotalSum() << "  ";
    

}

// getters / setters (InternationalStudent)
string InternationalStudent::getCountryOrigin() const
{
    return this->countryOrigin;
}

void InternationalStudent::setCountryOrigin(const string &_countryOrigin)
{
    this->countryOrigin = _countryOrigin;
}
InternationalStudent* InternationalStudent::getNext(){
    return next;
}
InternationalStudent* InternationalStudent::getPrevious(){
    return previous;
}

bool InternationalStudent::isCountryValidAndInternational() const
{
    // correcting India typo
    if (countryOrigin == "India" || countryOrigin == "Iran" || countryOrigin == "China" || countryOrigin == "Korea") //|| countryOrigin == "Canada")
    {
        return true;
    }
    else if (countryOrigin == "Canada")
    {
        cout << "Please enter canadian students as domestic students" << endl;
    }

    return false;
}

// compares country, returns 1 if country 1 is greater, -1 if country 2 is greater
int compareCountry(string country1, string country2)
{

    int numOfComparasons = 0; // This will be whichever length is greater between Length of student names
    int lenStu1 = country1.length();
    int lenStu2 = country2.length();
    if (lenStu1 > lenStu2)
    {
        numOfComparasons = lenStu1;
    }
    else
    {
        numOfComparasons = lenStu2;
    }
    for (int i = 0; i < numOfComparasons; i++)
    {
        if (country1[i] == country2[i])
        {
            continue; // if letter is same
        }
        else if (country1[i] > country2[i])
        {
            // this case: stu1 is greater
            return 1;
        }
        else
        {
            return -1;
        }
    }
    return 0;
}

// operator overload (InternationalStudent)
ostream &operator<<(ostream &_COUT, InternationalStudent &_internationalStudent)
{

    // Prints out all the information in the international student class
    _COUT << "First Name: " << _internationalStudent.getFirstName() << endl;
    _COUT << "Last Name: " << _internationalStudent.getLastName() << endl;
    _COUT << "CGPA: " << _internationalStudent.getCGPA() << endl;
    _COUT << "Research Score: " << _internationalStudent.getResearchScore() << endl;
    _COUT << "TOEFL Score: " << _internationalStudent.getToeflScoreobj().getTotalSum() << endl;
    _COUT << "Application ID Number: " << _internationalStudent.getAppIdNumber() << endl;
    _COUT << "Country of Origin of Student: " << _internationalStudent.getCountryOrigin() << endl;
    return _COUT;
}
// CODE FOR INTERNATIONAL STUDENT ENDS

// CLASS TOEFLscore BEGINS

// default constructor definition

ToeflScore::ToeflScore()
{

    this->listening = 0;
    this->reading = 0;
    this->speaking = 0;
    this->writing = 0;
}
// Non defualt Constructor function
ToeflScore::ToeflScore(const int &listening, const int &reading, const int &speaking, const int &writing)
{

    this->listening = listening;
    this->reading = reading;
    this->speaking = speaking;
    this->writing = writing;
}

// getter functions
int ToeflScore::getReading() const
{
    return this->reading;
}

int ToeflScore::getListening() const
{
    return this->listening;
}

int ToeflScore::getSpeaking() const
{
    return this->speaking;
}

int ToeflScore::getWriting() const
{
    return this->writing;
}

int ToeflScore::getTotalSum() const
{
    return (writing + reading + listening + speaking);
}

// setter functions for TOEFLScore
void ToeflScore::setReading(const int &_reading)
{

    // validity Checker if statement
    if (_reading >= 0 && _reading <= 30)
    {
        this->reading = _reading;
    }
    else
    {
        cout << "Reading score invalid" << endl;
        exit(1);
    }
}

void ToeflScore::setListening(const int &_listening)
{

    // validity Checker if statement
    if (_listening >= 0 && _listening <= 30)
    {
        this->listening = _listening;
    }
    // checker for invalid input
    else
    {
        cout << "Listening score invalid" << endl;
        exit(1);
    }
}

void ToeflScore::setSpeaking(const int &_speaking)
{

    // validity Checker if statement
    if (_speaking >= 0 && _speaking <= 30)
    {
        this->speaking = _speaking;
    }
    // checker for invalid input
    else
    {
        cout << "Speaking score invalid" << endl;
        exit(1);
    }
}

void ToeflScore::setWriting(const int &_writing)
{

    // validity Checker if statement
    if (_writing >= 0 && _writing <= 30)
    {
        this->writing = _writing;
    }
    // checker for invalid input
    else
    {
        cout << "Writing score invalid" << endl;
        exit(1);
    }
}

void ToeflScore::setTotalSum(int readingS, int listeningS, int speakingS, int writingS)
{

    this->reading = readingS;
    this->listening = listeningS;
    this->speaking = speakingS;
    this->writing = writingS;
}

// returns 1 if valid, else returns 0
bool ToeflScore::isToeflValid()
{

    // counting invalid entries as a fail.
    if (reading < 0 || reading > 30)
    {
        // cout << "Reading score invalid" << endl;
        reading = 0;
    }
    else if (listening < 0 || listening > 30)
    {
        // cout << "Listening score invalid" << endl;
        listening = 0;
    }
    else if (speaking < 0 || speaking > 30)
    {
        // cout << "Speaking score invalid" << endl;
        speaking = 0;
    }
    else if (writing < 0 || writing > 30)
    {
        // cout << "Writing score invalid" << endl;
        writing = 0;
    }

    // total score is less then Minimum passing score
    if (reading < 20 || writing < 20 || speaking < 20 || listening < 20)
    {
        // cout << "Individual score is less then pass threashold." << endl;
        return 0;
    }

    if (getTotalSum() <= 92)//min 93
    {
        // cout << "Toeflscore total is lower then pass threashold." << endl;
        return 0;
    }
    return 1;
}

// returns 0 if incorrect
bool ToeflScore::isToeflCorrect()
{
    if (reading < 0 || reading > 30)
    {
        // cout << "Reading score invalid" << endl;
        return 0;
    }
    else if (listening < 0 || listening > 30)
    {
        // cout << "Listening score invalid" << endl;
        return 0;
    }
    else if (speaking < 0 || speaking > 30)
    {
        // cout << "Speaking score invalid" << endl;
        return 0;
    }
    else if (writing < 0 || writing > 30)
    {
        // cout << "Writing score invalid" << endl;
        return 0;
    }
    return 1;
}

// overloaded operator for TOEFL score to print out the total sum (only used for ToeflScore objects)
ostream &operator<<(ostream &TOEFL_COUT, ToeflScore &TOEFL_InternationalStudent)
{
    // Prints out the Total TOEFL score for the interntaional student
    TOEFL_COUT << "TOEFL Score Total Sum: " << TOEFL_InternationalStudent.getTotalSum() << endl;
    return TOEFL_COUT;
}

ToeflScore InternationalStudent::getToeflScoreobj() const
{

    return this->InternationalStuToeflScore;
}

void InternationalStudent::setToeflScoreHelper(const int &reading, const int &listening, const int &speaking, const int &writing)
{

    this->InternationalStuToeflScore.setTotalSum(reading, listening, speaking, writing);
}

// DOMESTIC & INTERNATIONAL LINKED LISTS

DomesticList::DomesticList()
{
    head = NULL;
    tail = NULL;
}

DomesticList::~DomesticList()
{
    DomesticStudent *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        delete (temp->previous);
    }
    delete (temp);
}

DomesticStudent *DomesticList::getHead() const
{
    return head;
}

DomesticStudent *DomesticList::getTail() const
{
    return tail;
}

void DomesticList::printList()
{
    DomesticStudent *temp = head;
   cout << "Priting in order of: "
<< "\nResearch score, CGPA, Student Number, Province of origin, Name" << endl;
    while (temp != NULL)
    {
        // cout << "First Name: " << temp->getFirstName() << endl;
        // cout << "Last Name: " << temp->getLastName() << endl;
        // cout << "CGPA: " << temp->getCGPA() << endl;
        // cout << "Research Score: " << temp->getResearchScore() << endl;
        // cout << "Application ID Number: " << temp->getAppIdNumber() << endl;
        // cout << "Province of Student: " << temp->getProvince() << endl;
        // cout << "\n";
        cout << temp->getResearchScore();
        if(temp->getResearchScore() != 100){
            cout << " ";
        }
        if (temp->getCGPA() == 1 || temp->getCGPA() == 2 || temp->getCGPA() == 3 || temp->getCGPA() == 4)
        {
            cout << ""
                 << " " << temp->getCGPA() << ".0 " << temp->getAppIdNumber() << " " << temp->getProvince() << " " << temp->getFirstName() << " " << temp->getLastName();
        }
        else
        {
            cout << ""
                 << " " << temp->getCGPA() << " " << temp->getAppIdNumber() << " " << temp->getProvince() << " " << temp->getFirstName() << " " << temp->getLastName();
        }
        cout << "\n";
        temp = temp->next;
    }
}

// returns 1 if greater, -1 if smaller, 0 if same
int isStudentCurrentGreater(DomesticStudent *stu1, DomesticStudent *stu2)
{

    if (stu1->getResearchScore() > stu2->getResearchScore())
    {
        // cout << "First student has a greater research score" <<endl;
        return 1;
    }
    else if (stu1->getResearchScore() < stu2->getResearchScore())
    {
        // cout << "Second student has a greater research score" <<endl;
        return -1;
    }
    else if (stu1->getCGPA() > stu2->getCGPA())
    {
        // cout << "First student has a greater CGPA" <<endl;
        return 1;
    }
    else if (stu1->getCGPA() < stu2->getCGPA())
    {
        // cout << "Second student has a greater CGPA" <<endl;
        return -1;
    }
    else if (compareProvince(stu1->getProvince(), stu2->getProvince()) == -1)
    {
        return 1;
    }
    else if (compareProvince(stu1->getProvince(), stu2->getProvince()) == 1)
    {
        return -1;
    }

    return 0;
}

// o(n) for normal insert: case head/tail: o(1)
void DomesticList::insertNode(DomesticStudent nextStudent)
{

    if (head == NULL)
    {
        DomesticStudent *headNode;
        try
        {
            headNode = new DomesticStudent(nextStudent);
        }
        catch (bad_alloc &ba)
        {
            cout << "Bad Memory Allocation Caught: " << ba.what() << '\n';
        }

        head = headNode;
        head->previous = NULL;
        tail = head;
        return;
    }

    DomesticStudent *newNode;
    try
    {
        newNode = new DomesticStudent(nextStudent);
    }
    catch (bad_alloc &ba)
    {
        cout << "Bad Memory Allocation Caught: " << ba.what() << '\n';
    }

    DomesticStudent *tempNode = head;

    if (isStudentCurrentGreater(tempNode, newNode) != 1)
    {
        tempNode->previous = newNode;
        newNode->next = tempNode;
        head = newNode;
        return;
    }

    if (isStudentCurrentGreater(tail, newNode) != -1)
    {
        // cout << "Replace tail with value: " << newNode->getResearchScore() << endl;
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
        return;
    }

    newNode->previous = head;
    while (tempNode->next != NULL)
    {

        newNode->previous = tempNode;
        tempNode = tempNode->next;

        if (isStudentCurrentGreater(newNode, tempNode) != -1)
        {
            // insert BEFORE tempNode. (ie. tempNode is newNode->next)
            DomesticStudent *parentNode = tempNode->previous;
            newNode->previous = parentNode;
            parentNode->next = newNode;

            newNode->next = tempNode;
            tempNode->previous = newNode;
            // so it does reach here, but it freezes after this.
            //  cout << "Inserted node";
            //  exit(1);
            // printList();
            return;
        }
    }

    // Insert at end
    newNode->previous = tempNode;
    tempNode->next = newNode;
    tail = newNode;

    return;
}

// o(n)
bool DomesticList::searchDomesticApplicationID(int id)
{
    if (head == NULL)
    { // empty list
        cout << "Empty list. " << endl;
        return 0;
    }
    if (id > 20229999 || id < 20220000)
    { // invalid ID
        cout << "ID number invalid " << endl;
        return 0;
    }
    bool notFound = 1;

    DomesticStudent *temp;
    temp = head;

    while (temp != NULL)
    {
        if (temp->getAppIdNumber() == id) // not sure if its a ptr or a .
        {
            cout << "First Name: " << temp->getFirstName() << endl;
            cout << "Last Name: " << temp->getLastName() << endl;
            cout << "CGPA: " << temp->getCGPA() << endl;
            cout << "Research Score: " << temp->getResearchScore() << endl;
            cout << "Application ID Number: " << temp->getAppIdNumber() << endl;
            cout << "Province of Student: " << temp->getProvince() << endl;
            cout << "\n";
            notFound = 0;
        }
        temp = temp->next;
    }

    if (notFound)
    {
        cout << "Application ID : " << id << " is not within the list." << endl;
        return 0;
    }

    delete (temp);

    return 1;
}

// o(n)
bool DomesticList::searchDomesticCGPA(float cgpa)
{
    if (head == NULL)
    { // empty list
        cout << "Empty list. " << endl;
        return 0;
    }

    if (!(cgpa >= 0 && cgpa < 4.35))
    { // since everything under 4.35 IS ROUNDED DOWN TO 4.3- which is a valid CGPA on SFU scale
        cout << "Invalid specification for CGPA" << endl;
        return 0;
    }

    bool notFound = 1;

    DomesticStudent *temp;
    temp = head;

    while (temp != NULL)
    {
        if (temp->getCGPA() == cgpa) // not sure if its a ptr or a .
        {
            // cout << "\nFound object with CGPA: " << cgpa << endl;
            // cout << temp->getFirstName() << " " << temp->getLastName() << ", " << temp->getProvince() ", " << temp->getAppIdNumber() << ", " << temp->getResearchScore() << endl;
            cout << "First Name: " << temp->getFirstName() << endl;
            cout << "Last Name: " << temp->getLastName() << endl;
            cout << "CGPA: " << temp->getCGPA() << endl;
            cout << "Research Score: " << temp->getResearchScore() << endl;
            cout << "Application ID Number: " << temp->getAppIdNumber() << endl;
            cout << "Province of Student: " << temp->getProvince() << endl;
            cout << "\n";
            notFound = 0;
        }
        temp = temp->next;
    }

    if (notFound)
    {
        cout << "CGPA : " << cgpa << " is not within the list." << endl;
        return 0;
    }
    delete (temp);

    return 1;
}

bool DomesticList::searchDomesticResearchScore(int researchScore)
{
    if (head == NULL)
    {
        cout << "Empty list. " << endl;
        return 0;
    }

    if ((researchScore < 0 || researchScore > 100))
    {
        cout << "Invalid research score specified, please enter an int between 0 and 100" << endl;
        return 0;
    }

    bool notFound = 1;

    DomesticStudent *temp;
    temp = head;

    while (temp != NULL)
    {
        if (temp->getResearchScore() == researchScore) // not sure if its a ptr or a .
        {
            cout << "First Name: " << temp->getFirstName() << endl;
            cout << "Last Name: " << temp->getLastName() << endl;
            cout << "CGPA: " << temp->getCGPA() << endl;
            cout << "Research Score: " << temp->getResearchScore() << endl;
            cout << "Application ID Number: " << temp->getAppIdNumber() << endl;
            cout << "Province of Student: " << temp->getProvince() << endl;
            cout << "\n";
            notFound = 0;
        }
        temp = temp->next;
    }

    if (notFound)
    {
        cout << "Research score: " << researchScore << " is not within the list." << endl;
        return 0;
    }
    delete (temp);

    return 1;
}

bool DomesticList::searchDomesticNames(string firstName, string lastName)
{
    // similar to previous, convert UI to lowercase w my toLower function in main
    //  (ie. impliment this in Stu/stusort class?)

    bool notFound = 1;

    DomesticStudent *temp;
    temp = head;

    // insert string conversion here

    while (temp != NULL)
    {
        // TODO: check if this works, or only compares first letter of string
        if (temp->getFirstName() == firstName && temp->getLastName() == lastName) // not sure if its a ptr or a .
        {
            cout << "First Name: " << temp->getFirstName() << endl;
            cout << "Last Name: " << temp->getLastName() << endl;
            cout << "CGPA: " << temp->getCGPA() << endl;
            cout << "Research Score: " << temp->getResearchScore() << endl;
            cout << "Application ID Number: " << temp->getAppIdNumber() << endl;
            cout << "Province of Student: " << temp->getProvince() << endl;
            cout << "\n";
            notFound = 0;
        }
        temp = temp->next;
    }

    if (notFound)
    {
        cout << "Student with name " << firstName << " " << lastName << " is not within the list." << endl;
        return 0;
    }

    delete (temp);
    return 1;
}

void DomesticList::deleteDomestic(string firstName, string lastName)
{
    bool notFound = 1;
    DomesticStudent *nodeToDelete;

    if (head == NULL)
    {
        return;
    }

    if (head == tail && tail->getFirstName() == firstName && tail->getLastName() == lastName)
    {
        nodeToDelete = head;
        head = NULL;
        tail = NULL;
        delete (nodeToDelete);
        cout << "Deleted final element in list, list is now empty" << endl;
        return;
    }

    if (head != NULL && head->getFirstName() == firstName && head->getLastName() == lastName)
    {
        nodeToDelete = head;
        head = head->next;
        head->previous = NULL;
        delete (nodeToDelete);
        notFound = 0;
    }

    // if tail is chosen
    if (tail != NULL && tail->getFirstName() == firstName && tail->getLastName() == lastName)
    {
        tail = tail->previous;
        nodeToDelete = tail->next;
        tail->next = NULL;
        delete (nodeToDelete);
        notFound = 0;
    }

    DomesticStudent *temp = head;

    while (temp->next != NULL)
    {

        if (temp->next->getFirstName() == firstName && temp->next->getLastName() == lastName)
        {
            nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete (nodeToDelete);
            notFound = 0;
        }
        else
        {
            temp = temp->next;
        }
    }
/*
    if (notFound)
    {
        cout << "Student with name " << firstName << " " << lastName << " is not within the list." << endl;
    }
    delete (temp);
*/
    //THIS RECURSIVE CASE SHOULDNT BE CALLED
    // if(searchDomesticNames(firstName, lastName) == 1){
    //     deleteDomestic(firstName, lastName);
    // }
}

// // IS o(1) IN DOUBLY LINKED
void DomesticList::deleteDomesticHeadAndTail()
{
    if (head == NULL)
    // empty list
    {
        cout << "Empty list." << endl;
        return;
    }else if (tail == NULL)
    {    // Error: no tail
        cout << "Stack overflow" << endl;
        return;
    }else if (head->next == NULL)
    {    // single element
        head = NULL;
        delete (head);
        // since head == tail this should set them both to NULL/delete shared mem space
        return;
    }
    else if (head->next->next == NULL)
    {
        head = NULL;
        tail = NULL;        // case: head has 1 child (ie. the tail)
        delete (head); //  head->next = NULL;
        delete (tail);   //  tail->previous = NULL;
        return;
    }

    // deleting tail:
    tail = tail->previous;
    tail->next = NULL;
    delete (tail->next);

    // copying data
    head->setApplicationID(head->next->getAppIdNumber());
    head->setCGPA(head->next->getCGPA());
    head->setFirstName(head->next->getFirstName());
    head->setLastName(head->next->getLastName());
    head->setResearchScore(head->next->getResearchScore());
    head->setProvince(head->next->getProvince());

    head->next = head->next->next;
    head->next->previous = NULL;
    delete (head->next->previous);
    head->next->previous = head;

    // copy Data from next to head
    // head->next->get

    // deleting head:
}

// finding the average cgap
float DomesticList::averageDomesticCGPA()
{
    float average = 0;
    float count = 0;
    float total = 0;

    if (head == NULL) // error checking
    {
        cout << "Empty list. " << endl;
        return 0;
    }

    DomesticStudent *temp;
    temp = head;

    while (temp != NULL) // traversing the LL
    {
        total = total + temp->getCGPA();

        count++;
        temp = temp->next;
    }
    average = total / count;
    cout << "There are " << count << " domestic students with an average CGPA of " << average << endl;
    delete (temp);
    return average;
}

// calculates the domestic average research score
int DomesticList::averageDomesticRS()
{
    int average = 0;
    int count = 0;
    int total = 0;

    // error checking
    if (head == NULL)
    {
        cout << "Empty list. " << endl;
        return 0;
    }

    // traversing the list and adding the values up
    DomesticStudent *temp;
    temp = head;

    while (temp != NULL)
    {
        total = total + temp->getResearchScore();

        count++;
        temp = temp->next;
    }
    // calculating the average
    average = total / count;
    cout << "There are " << count << " domestic students with an average Research Score of " << average << endl;
    delete (temp);
    return average;
}

void DomesticList::editDomestic()
{ // edit domestic values
    // initiazling variables
    string firstName, lastName, province;
    int choice = -1;
    float cgpa = -1;
    int researchscore = -1;
    int count = 0;

    DomesticStudent *temp;
    temp = head;

    // checking to see if the user exists
    string name1, name2;
    cout << "First search For a user to edit" << endl;
    cout << "Please enter a first name" << endl;
    cin >> name1;
    name1 = stringFormat(name1);
    cout << "Please enter a last name" << endl;
    cin >> name2;
    name2 = stringFormat(name2);

    if (searchDomesticNames(name1, name2) == 1)
    {

        cout << "[1] Press 1 to edit first name" << endl;
        cout << "[2] Press 2 to edit last name" << endl;
        cout << "[3] Press 3 to edit CGPA" << endl;
        cout << "[4] Press 4 to edit Research Score" << endl;
        cout << "[5] Press 5 to edit Province" << endl;
        cin >> choice;

        if (choice == 1)
        { // edit the first name

            cout << "Please enter the new first name" << endl;
            cin >> firstName;
            firstName = stringFormat(firstName);

            while (temp != NULL)
            {
                if (temp->getFirstName() == name1 && temp->getLastName() == name2)
                {
                    temp->setFirstName(firstName);
                }
                temp = temp->next;
            }
            cout << "Success!" << endl;
        }
        else if (choice == 2)
        { // edit the last name

            cout << "Please enter the new last name" << endl;
            cin >> lastName;
            lastName = stringFormat(lastName);

            while (temp != NULL)
            {
                if (temp->getFirstName() == name1 && temp->getLastName() == name2)
                {
                    temp->setLastName(lastName);
                }
                temp = temp->next;
            }
            cout << "Success!" << endl;
        }
        else if (choice == 3)
        { // edit the cgpa

            while (cgpa < 0 || cgpa > 4.33)
            {
                if (count > 0)
                {
                    cout << "Invalid Input Try Again" << endl;
                }

                cout << "Please enter the new CGPA" << endl;
                cin >> cgpa;
                count++;
            }

            while (temp != NULL)
            {
                if (temp->getFirstName() == name1 && temp->getLastName() == name2)
                {
                    temp->setCGPA(cgpa);
                }
                temp = temp->next;
            }
            cout << "Success!" << endl;
        }
        else if (choice == 4)
        { // edit the research score

            while (researchscore < 0 || researchscore > 100)
            {
                if (count > 0)
                {
                    cout << "Invalid Input Try Again" << endl;
                }

                cout << "Please enter a new Research Score" << endl;
                cin >> researchscore;
                count++;
            }

            while (temp != NULL)
            {
                if (temp->getFirstName() == name1 && temp->getLastName() == name2)
                {
                    temp->setResearchScore(researchscore);
                }
                temp = temp->next;
            }
            cout << "Success!" << endl;
        }
        else if (choice == 5)
        { // edit the province

            while (isProvinceValid(province) == false)
            {
                if (count > 0)
                {
                    cout << "Invalid Input Try Again" << endl;
                }

                cout << "Please enter a new Province" << endl;
                cout << "Accepted provinces are: NL, PE, NS, NB, QC, ON, MB, SK, AB, BC, YT, NT, NU" << endl;
                cin >> province;
                count++;
                province = provinceFormat(province);
            }

            while (temp != NULL)
            {
                if (temp->getFirstName() == name1 && temp->getLastName() == name2)
                {
                    temp->setProvince(province);
                }
                temp = temp->next;
            }
            cout << "Success!" << endl;
        }
    }
    else
    {
        cout << "The user you entered does not exist, please try again" << endl; // telling hte user there is an error
    }

    delete (temp);
}

string DomesticList::stringFormat(string &s)
{ // capitalizes the first letter of the string
    s[0] = toupper(s[0]);
    int stringLength = s.length();
    for (int j = 1; j < stringLength; j++)
    {
        s[j] = tolower(s[j]);
    }

    return s;
}

string DomesticList::provinceFormat(string &s)
{ // capitalizes the first letter of the string
    s[0] = toupper(s[0]);
    s[1] = toupper(s[1]);
    int stringLength = s.length();
    for (int j = 2; j < stringLength; j++)
    {
        s[j] = tolower(s[j]);
    }

    return s;
}

bool DomesticList::isProvinceValid(string &province) // checks if province is valid
{
    if (province == "AB" || province == "BC" || province == "MB" || province == "NB" || province == "QC" || province == "ON" || province == "NU" || province == "NL" || province == "NS" || province == "NT" || province == "SK" || province == "YT" || province == "PE")
    {
        return true;
    }
    return false;
}
// ------------------------------ ------------------------------ ------------------------------
//------------------------------ INTERNATIONAL ------------------------------
// ------------------------------ Linked list ------------------------------

InternationalList::InternationalList()
{
    head = NULL;
    tail = NULL;
}

InternationalStudent *InternationalList::getHead() const
{
    return head;
}

InternationalStudent *InternationalList::getTail() const
{
    return tail;
}

void InternationalList::deleteInternational(string firstName, string lastName)
{
    bool notFound = 1;
    InternationalStudent *nodeToDelete;
  
     if (head == tail && tail->getFirstName() == firstName && tail->getLastName() == lastName)
    {
        nodeToDelete = head;
        head = NULL;
        tail = NULL;
        delete (nodeToDelete);
        cout << "Deleted final element in list, list is now empty" << endl;
        return;
    }

    if (head != NULL && head->getFirstName() == firstName && head->getLastName() == lastName)
    {
        nodeToDelete = head;
        head = head->next;
        head->previous = NULL;
        delete (nodeToDelete);
        notFound = 0;
    }

    // if tail is chosen
    if (tail != NULL && tail->getFirstName() == firstName && tail->getLastName() == lastName)
    {
        tail = tail->previous;
        nodeToDelete = tail->next;
        tail->next = NULL;
        delete (nodeToDelete);
        notFound = 0;
    }

    InternationalStudent *temp = head;
    if (temp != NULL)
    {
        while (temp->next != NULL)
        {
            if (temp->next->getFirstName() == firstName && temp->next->getLastName() == lastName)
            {
                nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete (nodeToDelete);
                notFound = 0;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
/*    
    if (notFound)
    {
        cout << "Student with name " << firstName << " " << lastName << " is not within the list." << endl;
    }
    delete (temp);
*/
    //THIS RECURSIVE CASE SHOULDNT BE CALLED
    // if(searchInternationalNames(firstName, lastName) == 1){
    //     deleteInternational(firstName, lastName);
    // }
}

void InternationalList::deleteInternationalHeadAndTail()
{
    if (head == NULL)
    // empty list
    {
        cout << "Empty list." << endl;
        return;
    }
    else if (tail == NULL)
    // Error: no tail
    {
        cout << "Stack overflow" << endl;
        return;
    }
    else if (head->next == NULL)
    // single element
    {
        head = NULL;
        delete (head);
        // since head == tail this should set them both to NULL/delete shared mem space
        return;
    }
    else if (head->next->next == NULL)
    {
        // case: head has 1 child (ie. the tail)
        //  head->next = NULL;
        //  tail->previous = NULL;
        head = NULL;
        tail = NULL;
        delete (head);
        delete (tail);
        return;
    }

    // deleting tail:
    tail = tail->previous;
    tail->next = NULL;
    delete (tail->next);

    // copying data
    head->setApplicationID(head->next->getAppIdNumber());
    head->setCGPA(head->next->getCGPA());
    head->setFirstName(head->next->getFirstName());
    head->setLastName(head->next->getLastName());
    head->setResearchScore(head->next->getResearchScore());
    // head->setProvince(head->next->getProvince());
    head->setCountryOrigin(head->next->getCountryOrigin());
    head->setToeflScoreHelper(head->next->getToeflScoreobj().getReading(), head->next->getToeflScoreobj().getListening(), head->next->getToeflScoreobj().getSpeaking(), head->next->getToeflScoreobj().getWriting());
    // r l s w
    head->next = head->next->next;
    head->next->previous = NULL;
    delete (head->next->previous);
    head->next->previous = head;
    return;
}

int isStudentCurrentGreater(InternationalStudent *stu1, InternationalStudent *stu2)
{
    // TODO: Print TOEFLfailers in order.

    if (stu1->getToeflScoreobj().isToeflValid() != 1 && stu2->getToeflScoreobj().isToeflValid() != 1)
    {
        // BOTH R INVALID. ie both toeflfailers -> SORT IN ORDER.
    }
    else if (stu1->getToeflScoreobj().isToeflValid() != 1)
    {
        // ie. Stu2 is greater, since Stu1 fails toeflscore
        return -1;
    }
    else if (stu2->getToeflScoreobj().isToeflValid() != 1)
    {
        return 1;
    } // else

    if (stu1->getResearchScore() > stu2->getResearchScore())
    {
        // cout << "First student has a greater research score" <<endl;
        return 1;
    }
    else if (stu1->getResearchScore() < stu2->getResearchScore())
    {
        // cout << "Second student has a greater research score" <<endl;
        return -1;
    }
    else if (stu1->getCGPA() > stu2->getCGPA())
    {
        // cout << "First student has a greater CGPA" <<endl;
        return 1;
    }
    else if (stu1->getCGPA() < stu2->getCGPA())
    {
        // cout << "Second student has a greater CGPA" <<endl;
        return -1;
    }
    else if (compareCountry(stu1->getCountryOrigin(), stu2->getCountryOrigin()) == -1)
    {
        return 1;
    }
    else if (compareCountry(stu1->getCountryOrigin(), stu2->getCountryOrigin()) == 1)
    {
        return -1;
    }

    // }else if (compareCountry(stu1->getCountryOrigin(), stu2->getCountryOrigin()) == -1){
    //     return 1;
    // }else if(compareCountry(stu1->getCountryOrigin(), stu2->getCountryOrigin()) == 1){
    //     return -1;
    // }

    return 0;
}

void InternationalList::insertNode(InternationalStudent nextStudent)
{
    if (head == NULL)
    {
        InternationalStudent *headNode;
        try
        {
            headNode = new InternationalStudent(nextStudent);
        }
        catch (bad_alloc &ba)
        {
            cout << "Bad Memory Allocation Caught: " << ba.what() << '\n';
        }

        head = headNode;
        head->previous = NULL;
        tail = head;
        return;
    }

    InternationalStudent *newNode;
    try
    {
        newNode = new InternationalStudent(nextStudent);
    }
    catch (bad_alloc &ba)
    {
        cout << "Bad Memory Allocation Caught: " << ba.what() << '\n';
    }
    InternationalStudent *tempNode = head;

    // insert to head
    if (isStudentCurrentGreater(tempNode, newNode) != 1)
    {
        tempNode->previous = newNode;
        newNode->next = tempNode;
        head = newNode;
        return;
    }

    if (isStudentCurrentGreater(tail, newNode) != -1)
    {
        // cout << "Replace tail with value: " << newNode->getResearchScore() << endl;
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
        return;
    }

    newNode->previous = head;
    while (tempNode->next != NULL)
    {

        newNode->previous = tempNode;
        tempNode = tempNode->next;

        if (isStudentCurrentGreater(newNode, tempNode) != -1)
        {
            // insert BEFORE tempNode. (ie. tempNode is newNode->next)
            InternationalStudent *parentNode = tempNode->previous;
            newNode->previous = parentNode;
            parentNode->next = newNode;

            newNode->next = tempNode;
            tempNode->previous = newNode;
            return;
        }
    }

    // Insert at end
    newNode->previous = tempNode;
    tempNode->next = newNode;
    tail = newNode;

    return;
}

void InternationalList::printList()
{
    InternationalStudent *temp = head;
       cout << "Priting in order of: "
<< "\nResearch score, CGPA, Student Number, Country of origin, TOEFL status, Name" << endl;
    while (temp != NULL)
    {
        // cout << "First Name: " << temp->getFirstName() << endl;
        // cout << "Last Name: " << temp->getLastName() << endl;
        // if (temp->getCGPA() == 1 || temp->getCGPA() == 2 || temp->getCGPA() == 3 || temp->getCGPA() == 4)
        // {
        //     cout << "First Name: " << temp->getFirstName() << endl;
        //     cout << "CGPA: " << temp->getCGPA() << ".0";
        // }else{
        //     cout << "CGPA: " << temp->getCGPA() << endl;
        // }

        // cout << "Research Score: " << temp->getResearchScore() << endl;
        // cout << "Application ID Number: " << temp->getAppIdNumber() << endl;
        // if (!(temp->getToeflScoreobj().isToeflValid() == 1))
        // {
        //     cout << "TOEFL Score: "
        //          << "FAILED ";
        // }
        // else
        // {
        //     cout << "TOEFL Score: " << temp->getToeflScoreobj().getTotalSum() << " ";
        // }
        // cout << "(Reading Score: " << temp->getToeflScoreobj().getReading() << ", Writing Score: " << temp->getToeflScoreobj().getWriting() << ", Speaking Score: " << temp->getToeflScoreobj().getSpeaking() << ", Listening score: " << temp->getToeflScoreobj().getListening() << ")" << endl;
        // cout << "Country of Origin of Student: " << temp->getCountryOrigin() << endl;

        cout << temp->getResearchScore();
        if (temp->getResearchScore() != 100)
        {
            cout << " ";
        }
        if (temp->getCGPA() == 1 || temp->getCGPA() == 2 || temp->getCGPA() == 3 || temp->getCGPA() == 4)
        {
            cout << " " << temp->getCGPA() << ".0";
        }
        else
        {
            cout << " " << temp->getCGPA();
        }
        cout << " " << temp->getAppIdNumber();
        cout << " " << temp->getCountryOrigin();
        if (temp->getCountryOrigin() == "Iran")
        {
            cout << " ";
        }
        if (!(temp->getToeflScoreobj().isToeflValid() == 1))
        {
            cout << " FAIL";
        }
        else if (temp->getToeflScoreobj().getTotalSum() > 99)
        {
            cout << " " << temp->getToeflScoreobj().getTotalSum() << " ";
        }
        else
        {
            cout << " " << temp->getToeflScoreobj().getTotalSum() << "  ";
        }
        // cout << "(Reading Score: " << temp->getToeflScoreobj().getReading() << ", Writing Score: " << temp->getToeflScoreobj().getWriting() << ", Speaking Score: " << temp->getToeflScoreobj().getSpeaking() << ", Listening score: " << temp->getToeflScoreobj().getListening() << ")" << endl;
        cout << " " << temp->getFirstName();
        cout << " " << temp->getLastName();
        cout << "\n";
        temp = temp->next;
    }
}

bool InternationalList::searchInternationalApplicationID(int id)
{
    if (head == NULL)
    { // empty list
        cout << "Empty list. " << endl;
        return 0;
    }
    if (id > 20229999 || id < 20220000)
    { // invalid ID
        cout << "ID number invalid " << endl;
        return 0;
    }
    bool notFound = 1;

    InternationalStudent *temp;
    temp = head;

    while (temp != NULL)
    {
        if (temp->getAppIdNumber() == id) // not sure if its a ptr or a .
        {
            cout << "First Name: " << temp->getFirstName() << endl;
            cout << "Last Name: " << temp->getLastName() << endl;
            cout << "CGPA: " << temp->getCGPA() << endl;
            cout << "Research Score: " << temp->getResearchScore() << endl;
            cout << "Application ID Number: " << temp->getAppIdNumber() << endl;
            if (!(temp->getToeflScoreobj().isToeflValid() == 1))
            {
                cout << "TOEFL Score: "
                     << "FAILED ";
            }
            else
            {
                cout << "TOEFL Score: " << temp->getToeflScoreobj().getTotalSum() << " ";
            }
            cout << "(Reading Score: " << temp->getToeflScoreobj().getReading() << ", Writing Score: " << temp->getToeflScoreobj().getWriting() << ", Speaking Score: " << temp->getToeflScoreobj().getSpeaking() << ", Listening score: " << temp->getToeflScoreobj().getListening() << ")" << endl;
            cout << "Country of Origin of Student: " << temp->getCountryOrigin() << endl;

            cout << "\n";
            notFound = 0;
        }
        temp = temp->next;
    }

    if (notFound)
    {
        cout << "Application ID : " << id << " is not within the list." << endl;
        return 0;
    }

    delete (temp);

    return 1;
}

bool InternationalList::searchInternationalCGPA(float cgpa)
{
    if (head == NULL)
    { // empty list
        cout << "Empty list. " << endl;
        return 0;
    }

    if (!(cgpa >= 0 && cgpa < 4.35))
    { // since everything under 4.35 IS ROUNDED DOWN TO 4.3- which is a valid CGPA on SFU scale
        cout << "Invalid specification for CGPA" << endl;
        return 0;
    }

    bool notFound = 1;

    InternationalStudent *temp;
    temp = head;

    while (temp != NULL)
    {
        if (temp->getCGPA() == cgpa) // not sure if its a ptr or a .
        {
            // cout << "\nFound object with CGPA: " << cgpa << endl;
            // cout << temp->getFirstName() << " " << temp->getLastName() << ", " << temp->getProvince() ", " << temp->getAppIdNumber() << ", " << temp->getResearchScore() << endl;
            // cout << "First Name: " << temp->getFirstName() << endl;
            // cout << "Last Name: " << temp->getLastName() << endl;
            // cout << "CGPA: " << temp->getCGPA() << endl;
            // cout << "Research Score: " << temp->getResearchScore() << endl;
            // cout << "Application ID Number: " << temp->getAppIdNumber() << endl;
            // cout << "TOEFL Score: " << temp->getToeflScoreobj().getTotalSum() << endl;
            // cout << "Country of Origin of Student: " << temp->getCountryOrigin() << endl;
            // cout << "\n";
            notFound = 0;

            cout << "First Name: " << temp->getFirstName() << endl;
            cout << "Last Name: " << temp->getLastName() << endl;
            if (temp->getCGPA() == 1 || temp->getCGPA() == 2 || temp->getCGPA() == 3 || temp->getCGPA() == 4)
            {
                cout << "First Name: " << temp->getFirstName() << endl;
                cout << "CGPA: " << temp->getCGPA() << ".0" << endl;
            }
            else
            {
                cout << "CGPA: " << temp->getCGPA() << endl;
            }

            cout << "Research Score: " << temp->getResearchScore() << endl;
            cout << "Application ID Number: " << temp->getAppIdNumber() << endl;
            if (!(temp->getToeflScoreobj().isToeflValid() == 1))
            {
                cout << "TOEFL Score: " << temp->getToeflScoreobj().getTotalSum()
                     << " - FAILED - ";
            }
            else
            {
                cout << "TOEFL Score: " << temp->getToeflScoreobj().getTotalSum() << " ";
            }
            cout << "(Reading Score: " << temp->getToeflScoreobj().getReading() << ", Writing Score: " << temp->getToeflScoreobj().getWriting() << ", Speaking Score: " << temp->getToeflScoreobj().getSpeaking() << ", Listening score: " << temp->getToeflScoreobj().getListening() << ")" << endl;
            cout << "Country of Origin of Student: " << temp->getCountryOrigin() << endl;
            cout << "\n";
        }
        temp = temp->next;
    }

    if (notFound)
    {
        cout << "CGPA : " << cgpa << " is not within the list." << endl;
        return 0;
    }
    delete (temp);

    return 1;
}

bool InternationalList::searchInternationalResearchScore(int researchScore)
{
    if (head == NULL)
    {
        cout << "Empty list. " << endl;
        return 0;
    }

    if ((researchScore < 0 || researchScore > 100))
    {
        cout << "Invalid research score specified, please enter an int between 0 and 100" << endl;
        return 0;
    }

    bool notFound = 1;

    InternationalStudent *temp;
    temp = head;

    while (temp != NULL)
    {
        if (temp->getResearchScore() == researchScore) // not sure if its a ptr or a .
        {
            cout << "First Name: " << temp->getFirstName() << endl;
            cout << "Last Name: " << temp->getLastName() << endl;
            if (temp->getCGPA() == 1 || temp->getCGPA() == 2 || temp->getCGPA() == 3 || temp->getCGPA() == 4)
            {
                cout << "First Name: " << temp->getFirstName() << endl;
                cout << "CGPA: " << temp->getCGPA() << ".0" << endl;
            }
            else
            {
                cout << "CGPA: " << temp->getCGPA() << endl;
            }

            cout << "Research Score: " << temp->getResearchScore() << endl;
            cout << "Application ID Number: " << temp->getAppIdNumber() << endl;
            if (!(temp->getToeflScoreobj().isToeflValid() == 1))
            {
                cout << "TOEFL Score: " << temp->getToeflScoreobj().getTotalSum()
                     << " - FAILED - ";
            }
            else
            {
                cout << "TOEFL Score: " << temp->getToeflScoreobj().getTotalSum() << " ";
            }
            cout << "(Reading Score: " << temp->getToeflScoreobj().getReading() << ", Writing Score: " << temp->getToeflScoreobj().getWriting() << ", Speaking Score: " << temp->getToeflScoreobj().getSpeaking() << ", Listening score: " << temp->getToeflScoreobj().getListening() << ")" << endl;
            cout << "Country of Origin of Student: " << temp->getCountryOrigin() << endl;
            cout << "\n";
            notFound = 0;
        }
        temp = temp->next;
    }

    if (notFound)
    {
        cout << "Research score: " << researchScore << " is not within the list." << endl;
        return 0;
    }
    delete (temp);

    return 1;
}

// returns 1 if found, 0 if not found.
// assumes good input (ie. Capitalized properly)
bool InternationalList::searchInternationalNames(string firstName, string lastName)
{
    bool notFound = 1;

    InternationalStudent *temp;
    temp = head;

    // insert string conversion here

    while (temp != NULL)
    {
        // TODO: check if this works, or only compares first letter of string
        if (temp->getFirstName() == firstName && temp->getLastName() == lastName) // not sure if its a ptr or a .
        {
            cout << "First Name: " << temp->getFirstName() << endl;
            cout << "Last Name: " << temp->getLastName() << endl;
            if (temp->getCGPA() == 1 || temp->getCGPA() == 2 || temp->getCGPA() == 3 || temp->getCGPA() == 4)
            {
                cout << "First Name: " << temp->getFirstName() << endl;
                cout << "CGPA: " << temp->getCGPA() << ".0" << endl;
            }
            else
            {
                cout << "CGPA: " << temp->getCGPA() << endl;
            }

            cout << "Research Score: " << temp->getResearchScore() << endl;
            cout << "Application ID Number: " << temp->getAppIdNumber() << endl;
            if (!(temp->getToeflScoreobj().isToeflValid() == 1))
            {
                cout << "TOEFL Score: " << temp->getToeflScoreobj().getTotalSum()
                     << " - FAILED - ";
            }
            else
            {
                cout << "TOEFL Score: " << temp->getToeflScoreobj().getTotalSum() << " ";
            }
            cout << "(Reading Score: " << temp->getToeflScoreobj().getReading() << ", Writing Score: " << temp->getToeflScoreobj().getWriting() << ", Speaking Score: " << temp->getToeflScoreobj().getSpeaking() << ", Listening score: " << temp->getToeflScoreobj().getListening() << ")" << endl;
            cout << "Country of Origin of Student: " << temp->getCountryOrigin() << endl;
            cout << "\n";
            notFound = 0;
            cout << "\n";
        }
        temp = temp->next;
    }

    if (notFound)
    {
        cout << "Student with name " << firstName << " " << lastName << " is not within the list." << endl;
        return 0;
    }
    delete (temp);

    return 1;
}

// calculates the cpga average
float InternationalList::averageInternationalCGPA()
{
    float average = 0;
    float count = 0;
    float total = 0;

    if (head == NULL)
    {
        cout << "Empty list. " << endl;
        return 0;
    }

    InternationalStudent *temp;
    temp = head;

    while (temp != NULL)
    {
        total = total + temp->getCGPA();

        count++;
        temp = temp->next;
    }
    average = total / count;
    cout << "There are " << count << " international students with an average CGPA of " << average << endl;
    delete (temp);
    return average;
}

// calculates the research score average
int InternationalList::averageInternationalRS()
{
    int average = 0;
    int count = 0;
    int total = 0;

    if (head == NULL)
    {
        cout << "Empty list. " << endl;
        return 0;
    }

    InternationalStudent *temp;
    temp = head;

    while (temp != NULL)
    {
        total = total + temp->getResearchScore();

        count++;
        temp = temp->next;
    }
    average = total / count;
    cout << "There are " << count << " international students with an average Research Score of " << average << endl;
    delete (temp);
    return average;
}

// calculates the toefl score averages
int InternationalList::averageTOEFL()
{
    int averageTotal, averageRead, averageWrite, averageListen, averageSpeak;
    int count = 0;
    int read = 0;
    int write = 0;
    int listen = 0;
    int speak = 0;
    int total = 0;

    if (head == NULL) // error checking
    {
        cout << "Empty list. " << endl;
        return 0;
    }

    InternationalStudent *temp;
    temp = head;
    // temp->getToeflScoreobj().isToeflCorrect();
    while (temp != NULL) // traversing the LL and calculating the totals
    {
        // if (temp->getToeflScoreobj().getReading() != 0 && temp->getToeflScoreobj().getWriting() != 0 && temp->getToeflScoreobj().getListening() !=0 && temp->getToeflScoreobj().getSpeaking() !=0 && temp->getToeflScoreobj().getTotalSum() != 0)
        //{
        total = total + temp->getToeflScoreobj().getTotalSum();
        read = read + temp->getToeflScoreobj().getReading();
        write = write + temp->getToeflScoreobj().getWriting();
        listen = listen + temp->getToeflScoreobj().getListening();
        speak = speak + temp->getToeflScoreobj().getSpeaking();

        count++;
        temp = temp->next;
        //}
    }
    averageTotal = total / count; // calculating averages
    averageListen = listen / count;
    averageRead = read / count;
    averageWrite = write / count;
    averageSpeak = speak / count;

    // output to user
    cout << "There are " << count << " international students with an average Total Score of " << averageTotal << endl;
    cout << "There are " << count << " international students with an average Reading Score of " << averageRead << endl;
    cout << "There are " << count << " international students with an average Writing Score of " << averageWrite << endl;
    cout << "There are " << count << " international students with an average Speaking Score of " << averageSpeak << endl;
    cout << "There are " << count << " international students with an average Listening Score of " << averageListen << endl;
    delete (temp);
    return averageTotal;
}

string InternationalList::stringFormat(string &s)
{ // capitalizes the first letter of the string
    s[0] = toupper(s[0]);
    int stringLength = s.length();
    for (int j = 1; j < stringLength; j++)
    {
        s[j] = tolower(s[j]);
    }

    return s;
}

// edits international student info
void InternationalList::editInternational()
{
    string firstName, lastName, country;
    int choice = -1;
    float cgpa = -1;
    int researchscore = -1;
    int count = 0;

    InternationalStudent *temp;
    temp = head;

    // gettting and checking user input to see if the student exists
    string name1, name2;
    cout << "First search For a user to edit" << endl;
    cout << "Please enter a first name" << endl;
    cin >> name1;
    name1 = stringFormat(name1);
    cout << "Please enter a last name" << endl;
    cin >> name2;
    name2 = stringFormat(name2);

    if (searchInternationalNames(name1, name2) == 1)
    {

        cout << "[1] Press 1 to edit first name" << endl;
        cout << "[2] Press 2 to edit last name" << endl;
        cout << "[3] Press 3 to edit CGPA" << endl;
        cout << "[4] Press 4 to edit Research Score" << endl;
        cout << "[5] Press 5 to edit Country" << endl;
        cin >> choice;

        if (choice == 1)
        { // changing first name
            cout << "Please enter the new first name" << endl;
            cin >> firstName;
            firstName = stringFormat(firstName);

            while (temp != NULL)
            {
                if (temp->getFirstName() == name1 && temp->getLastName() == name2)
                {
                    temp->setFirstName(firstName);
                }
                temp = temp->next;
            }
            cout << "Success!" << endl;
        }
        else if (choice == 2)
        { // changing last name

            cout << "Please enter the new last name" << endl;
            cin >> lastName;
            lastName = stringFormat(lastName);

            while (temp != NULL)
            {
                if (temp->getFirstName() == name1 && temp->getLastName() == name2)
                {
                    temp->setLastName(lastName);
                }
                temp = temp->next;
            }
            cout << "Success!" << endl;
        }
        else if (choice == 3)
        { // changing cgpa
            while (cgpa < 0 || cgpa > 4.33)
            {
                if (count > 0)
                {
                    cout << "Invalid Input Try Again" << endl;
                }

                cout << "Please enter the new CGPA" << endl;
                cin >> cgpa;
                count++;
            }
            while (temp != NULL)
            {
                if (temp->getFirstName() == name1 && temp->getLastName() == name2)
                {
                    temp->setCGPA(cgpa);
                }
                temp = temp->next;
            }
            cout << "Success!" << endl;
        }
        else if (choice == 4)
        { // changing research score

            while (researchscore < 0 || researchscore > 100)
            {
                if (count > 0)
                {
                    cout << "Invalid Input Try Again" << endl;
                }
                cout << "Please enter a new Research Score" << endl;
                cin >> researchscore;
                count++;
            }
            while (temp != NULL)
            {
                if (temp->getFirstName() == name1 && temp->getLastName() == name2)
                {
                    temp->setResearchScore(researchscore);
                }
                temp = temp->next;
            }
            cout << "Success!" << endl;
        }
        else if (choice == 5)
        { // changing countrys

            cout << "Please enter a new Country" << endl;
            cin >> country;
            country = stringFormat(country);

            while (temp != NULL)
            {
                if (temp->getFirstName() == name1 && temp->getLastName() == name2)
                {
                    temp->setCountryOrigin(country);
                }
                temp = temp->next;
            }
            cout << "Success!" << endl;
        }
    }
    else
    {
        cout << "The user you entered does not exist, please try again" << endl;
    }

    delete (temp);
}

bool Student::FilterStudents()
{

    int type = 0;
    int CGPA = 0;
    int researchScore = 0;
    int totalsum = 0;
    int reading = 0;
    int writing = 0;
    int speaking = 0;
    int listening = 0;

    cout << "Please Enter the type Students you would like to filter (1 for Domestic or 2 for International) " << endl;
    cin >> type;
    if (type == 1)
    {
        cout << "Please enter in the requried CGPA: " << endl;
        cin >> CGPA;
        cout << "Please enter in the required Research Score: " << endl;
        cin >> researchScore;
        // run algo
    }
    else if (type == 2)
    {
        int choice = 0;
        cout << "Please enter in the requried CGPA: " << endl;
        cin >> CGPA;
        cout << "Please enter in the required Research Score: " << endl;
        cin >> researchScore;

        cout << "Would you like to enter in TOEFL Score by Total Sum or Individual Fields (1 for Total Sum, 2 for Individual Fields" << endl;
        cin >> choice;

        if (choice == 1)
        {

            cout << "Please enter in the total sum: " << endl;
            cin >> totalsum;
            // run algo here
            return true;
        }
        else if (choice == 2)
        {

            cout << "Please enter in the required Reading Score: " << endl;
            cin >> reading;
            cout << "Please enter in the required Writing Score: " << endl;
            cin >> writing;
            cout << "Please enter in the required Listening Score: " << endl;
            cin >> listening;
            cout << "Please enter in the required Speaking Score: " << endl;
            cin >> speaking;
            // run algo here
            return true;
        }
        else
        {

            if (cin.fail())
            {
                cout << "Error, invalid entry.\n\n";
                cin.clear(); // Clears any error flags
                cin.ignore(1000, '\n');
            }
        }
    }
    else
    {

        if (cin.fail())
        {
            cout << "Error, invalid entry.\n\n";
            cin.clear(); // Clears any error flags
            cin.ignore(1000, '\n');
        }
        return false;
    }
    return false;
}

void DomesticList::deleteDomesticCGPA(float CGPA)
{
    bool notFound = 1;
    DomesticStudent *nodeToDelete;

    if (head == NULL)
    {
        return;
    }

    if (head == tail && tail->getCGPA() == CGPA)
    {
        nodeToDelete = head;
        head = NULL;
        tail = NULL;
        delete (nodeToDelete);
        cout << "Deleted final element in list, list is now empty" << endl;
        return;
    }

    if (head != NULL && head->getCGPA() == CGPA)
    {
        nodeToDelete = head;
        head = head->next;
        head->previous = NULL;
        delete (nodeToDelete);
        notFound = 0;
    }

    // if tail is chosen
    if (tail != NULL && tail->getCGPA() == CGPA)
    {
        tail = tail->previous;
        nodeToDelete = tail->next;
        tail->next = NULL;
        delete (nodeToDelete);
        notFound = 0;
    }

    DomesticStudent *temp = head;

    while (temp->next != NULL)
    {

        if (temp->next->getCGPA() == CGPA)
        {
            nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete (nodeToDelete);
            notFound = 0;
        }
        else
        {
            temp = temp->next;
        }
    }

    if (notFound)
    {
        cout << "Student with CGPA " << CGPA << " is not within the list." << endl;
    }
    delete (temp);
}

void DomesticList::deleteDomesticRS(int researchScore)
{
    bool notFound = 1;
    DomesticStudent *nodeToDelete;

    if (head == NULL)
    {
        return;
    }

    if (head == tail && tail->getResearchScore() == researchScore)
    {
        nodeToDelete = head;
        head = NULL;
        tail = NULL;
        delete (nodeToDelete);
        cout << "Deleted final element in list, list is now empty" << endl;
        return;
    }

    if (head != NULL && head->getResearchScore() == researchScore)
    {
        nodeToDelete = head;
        head = head->next;
        head->previous = NULL;
        delete (nodeToDelete);
        notFound = 0;
    }

    // if tail is chosen
    if (tail != NULL && tail->getResearchScore() == researchScore)
    {
        tail = tail->previous;
        nodeToDelete = tail->next;
        tail->next = NULL;
        delete (nodeToDelete);
        notFound = 0;
    }

    DomesticStudent *temp = head;

    while (temp->next != NULL)
    {

        if (temp->next->getResearchScore() == researchScore)
        {
            nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete (nodeToDelete);
            notFound = 0;
        }
        else
        {
            temp = temp->next;
        }
    }

    if (notFound)
    {
        cout << "Student with research score " << researchScore << " is not within the list." << endl;
    }
    delete (temp);
}

void InternationalList::deleteInternationalCGPA(float CGPA)
{
    bool notFound = 1;
    InternationalStudent *nodeToDelete;

    if (head == NULL)
    {
        return;
    }

    if (head == tail && tail->getCGPA() == CGPA)
    {
        nodeToDelete = head;
        head = NULL;
        tail = NULL;
        delete (nodeToDelete);
        cout << "Deleted final element in list, list is now empty" << endl;
        return;
    }

    if (head != NULL && head->getCGPA() == CGPA)
    {
        nodeToDelete = head;
        head = head->next;
        head->previous = NULL;
        delete (nodeToDelete);
        notFound = 0;
    }

    // if tail is chosen
    if (tail != NULL && tail->getCGPA() == CGPA)
    {
        tail = tail->previous;
        nodeToDelete = tail->next;
        tail->next = NULL;
        delete (nodeToDelete);
        notFound = 0;
    }

    InternationalStudent *temp = head;

    while (temp->next != NULL)
    {

        if (temp->next->getCGPA() == CGPA)
        {
            nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete (nodeToDelete);
            notFound = 0;
        }
        else
        {
            temp = temp->next;
        }
    }

    if (notFound)
    {
        cout << "Student with CGPA " << CGPA << " is not within the list." << endl;
    }
    delete (temp);
}

void InternationalList::deleteInternationalRS(int researchScore)
{
    bool notFound = 1;
    InternationalStudent *nodeToDelete;

    if (head == NULL)
    {
        return;
    }

    if (head == tail && tail->getResearchScore() == researchScore)
    {
        nodeToDelete = head;
        head = NULL;
        tail = NULL;
        delete (nodeToDelete);
        cout << "Deleted final element in list, list is now empty" << endl;
        return;
    }

    if (head != NULL && head->getResearchScore() == researchScore)
    {
        nodeToDelete = head;
        head = head->next;
        head->previous = NULL;
        delete (nodeToDelete);
        notFound = 0;
    }

    // if tail is chosen
    if (tail != NULL && tail->getResearchScore() == researchScore)
    {
        tail = tail->previous;
        nodeToDelete = tail->next;
        tail->next = NULL;
        delete (nodeToDelete);
        notFound = 0;
    }

    InternationalStudent *temp = head;

    while (temp->next != NULL)
    {

        if (temp->next->getResearchScore() == researchScore)
        {
            nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete (nodeToDelete);
            notFound = 0;
        }
        else
        {
            temp = temp->next;
        }
    }

    if (notFound)
    {
        cout << "Student with research score " << researchScore << " is not within the list." << endl;
    }
    delete (temp);
}