#include "student.hpp"
#include "mergedList.hpp"
#include <iostream>
#include <string>

using namespace std;

StudentList::StudentList()
{
    head = NULL;
    tail = NULL;
 
}

Node *StudentList::getHead() const
{
    return head;
}

Node *StudentList::getTail() const
{
    return tail;
}

Node::Node()
{
    next = NULL;
    previous = NULL;
    internationalStudent = InternationalStudent();
    domesticStudent = DomesticStudent();

}

bool StudentList::mergeLists(DomesticList *domesticList, InternationalList *internationalList)
{

    InternationalStudent *tempInternational;
    DomesticStudent *tempDomestic;
    tempDomestic = domesticList->getHead();
    tempInternational = internationalList->getHead();
    int domCount = 0;
    int intCount = 0;

    Node nodelist;

    while (tempDomestic != NULL)
    {
    
        nodelist.studentObj.setFirstName(tempDomestic->getFirstName());
        nodelist.studentObj.setLastName(tempDomestic->getLastName());
        //nodelist.studentObj.setRegion(tempDomestic->getProvince());
        nodelist.studentObj.setCGPA(tempDomestic->getCGPA());
        nodelist.studentObj.setResearchScore(tempDomestic->getResearchScore());
        nodelist.studentObj.setApplicationID(tempDomestic->getAppIdNumber());
        nodelist.domesticStudent.setProvince(tempDomestic->getProvince());
        insert(nodelist);
        domCount++;
        tempDomestic = tempDomestic->next;
        
    }

    while (tempInternational != NULL)
    {
        int readingScore = tempInternational->getToeflScoreobj().getReading();
        int listeningScore = tempInternational->getToeflScoreobj().getListening();
        int speakingScore = tempInternational->getToeflScoreobj().getSpeaking();
        int writingScore = tempInternational->getToeflScoreobj().getWriting();
        int totalscore = readingScore + writingScore + listeningScore + speakingScore;

        nodelist.studentObj.setFirstName(tempInternational->getFirstName());
        nodelist.studentObj.setLastName(tempInternational->getLastName());
        //nodelist.studentObj.setRegion(tempInternational->getCountryOrigin());
        nodelist.studentObj.setCGPA(tempInternational->getCGPA());
        nodelist.studentObj.setResearchScore(tempInternational->getResearchScore());
        nodelist.studentObj.setApplicationID(tempInternational->getAppIdNumber());
        nodelist.domesticStudent.setProvince("EMPTY");
        nodelist.internationalStudent.setToeflScoreHelper(readingScore,listeningScore,speakingScore,writingScore);
        nodelist.internationalStudent.setCountryOrigin(tempInternational->getCountryOrigin());

        if ((readingScore >= 20 && writingScore >= 20 && listeningScore >= 20 && speakingScore >= 20 && totalscore > 92))
        {
            insert(nodelist);
            intCount++;  
        }

        tempInternational = tempInternational->next;
        
    }

    return 1;
}

void StudentList::insert(Node nextStudent)
{
    if (head == NULL)
    {
        Node *headNode;
        try
        {
            headNode = new Node(nextStudent);
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

    Node *newNode;
    try
    {
        newNode = new Node(nextStudent);
    }
    catch (bad_alloc &ba)
    {
        cout << "Bad Memory Allocation Caught: " << ba.what() << '\n';
    }

    Node *tempNode = head;

    
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
            Node *parentNode = tempNode->previous;
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


// returns 0 if same, 1 if stu1 is greater, -1 if stu2 is greater
int StudentList::isStudentCurrentGreater(Node *stu1, Node *stu2)
{
    DomesticList object;
    // TWO DOMESTIC STUDENTS STUDENTS
    if (stu1->studentObj.getResearchScore() > stu2->studentObj.getResearchScore())
    {
        // cout << "First student has a greater research score" <<endl;
        return 1;
    }
    else if (stu1->studentObj.getResearchScore() < stu2->studentObj.getResearchScore())
    {
        // cout << "Second student has a greater research score" <<endl;
        return -1;
    }
    else if (stu1->studentObj.getCGPA() > stu2->studentObj.getCGPA())
    {
        // cout << "First student has a greater CGPA" <<endl;
        return 1;
    }
    else if (stu1->studentObj.getCGPA() < stu2->studentObj.getCGPA())
    {
        // cout << "Second student has a greater CGPA" <<endl;
        return -1;
    }
    else if (stu1->studentObj.getAppIdNumber() > stu2->studentObj.getAppIdNumber()) 
    {
        return -1;
    } 
    else if(stu1->studentObj.getAppIdNumber() < stu2->studentObj.getAppIdNumber())
    {
        return 1;
    }
    

    return 0;
}

void StudentList::printHelper()
{
    Node *headNode;
    
    headNode = this->getHead();
    

    while(headNode != NULL) {

        headNode->studentObj.virtualPrint();
        //if(head->internationalStudent.getCGPA() != 0){
            //cout << "here";
        if(headNode->internationalStudent.getToeflScoreobj().getTotalSum() == 0){
            headNode->domesticStudent.virtualPrint();

        }
        
        if(headNode->domesticStudent.getProvince() == "EMPTY"){
            headNode->internationalStudent.virtualPrint();

        }
        cout << endl;
        headNode = headNode ->next;
    }
}

void StudentList::printHelper1(Node *nextStudent)
{
    
        nextStudent->studentObj.virtualPrint();

        if(nextStudent->internationalStudent.getToeflScoreobj().getTotalSum() == 0){
            nextStudent->domesticStudent.virtualPrint();

        }

        if(nextStudent->studentObj.getAppIdNumber() >= 20220100 && nextStudent->studentObj.getAppIdNumber() <= 20220200){
            nextStudent->internationalStudent.virtualPrint();

        }
        cout << endl;
}

void StudentList::deleteNode(string firstName, string lastName) {       //this function deletes the node
    bool notFound = 1;
    Node *nodeToDelete;

    if (head == NULL)
    {
        return;
    }

    if (head == tail && tail->studentObj.getFirstName() == firstName && tail->studentObj.getLastName() == lastName)
    {
        nodeToDelete = head;
        head = NULL;
        tail = NULL;
        delete (nodeToDelete);
        cout << "Deleted final element in list, list is now empty" << endl;
        return;
    }

    if (head != NULL && head->studentObj.getFirstName() == firstName && head->studentObj.getLastName() == lastName)
    {
        nodeToDelete = head;
        head = head->next;
        head->previous = NULL;
        delete (nodeToDelete);
        notFound = 0;
    }

    // if tail is chosen
    if (tail != NULL && tail->studentObj.getFirstName() == firstName && tail->studentObj.getLastName() == lastName)
    {
        tail = tail->previous;
        nodeToDelete = tail->next;
        tail->next = NULL;
        delete (nodeToDelete);
        notFound = 0;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {

        if (temp->next->studentObj.getFirstName() == firstName && temp->next->studentObj.getLastName() == lastName)
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

bool StudentList::searchNames(string firstname, string lastname)    {
    // similar to previous, convert UI to lowercase w my toLower function in main
    //  (ie. impliment this in Stu/stusort class?)

    bool notFound = 1;

    Node *temp;
    temp = head;

    // insert string conversion here

    while (temp != NULL)
    {
        // TODO: check if this works, or only compares first letter of string
        if (temp->studentObj.getFirstName() == firstname && temp->studentObj.getLastName() == lastname) // not sure if its a ptr or a .
        {
            cout << "First Name: " << temp->studentObj.getFirstName() << endl;
            cout << "Last Name: " << temp->studentObj.getLastName() << endl;
            cout << "CGPA: " << temp->studentObj.getCGPA() << endl;
            cout << "Research Score: " << temp->studentObj.getResearchScore() << endl;
            cout << "Application ID Number: " << temp->studentObj.getAppIdNumber() << endl;
            cout << "Region of Student: " << temp->studentObj.getRegion() << endl;
            cout << "\n";
            notFound = 0;
        }
        temp = temp->next;
    }
    if (notFound)
    {
        cout << "Student with name " << firstname << " " << lastname << " is not within the list." << endl;
        return 0;
    }
    delete (temp);
    return 1;
}

void StudentList::deleteHeadAndTail()  {       //deletes head and tail
    
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
    head->studentObj.setApplicationID(head->next->studentObj.getAppIdNumber());
    head->studentObj.setCGPA(head->next->studentObj.getCGPA());
    head->studentObj.setFirstName(head->next->studentObj.getFirstName());
    head->studentObj.setLastName(head->next->studentObj.getLastName());
    head->studentObj.setResearchScore(head->next->studentObj.getResearchScore());
    head->studentObj.setRegion(head->next->studentObj.getRegion());
    head->internationalStudent.setToeflScoreHelper(head->next->internationalStudent.getToeflScoreobj().getReading(), head->next->internationalStudent.getToeflScoreobj().getListening(), head->next->internationalStudent.getToeflScoreobj().getSpeaking(), head->next->internationalStudent.getToeflScoreobj().getWriting());
    // r l s w
    head->next = head->next->next;
    head->next->previous = NULL;
    delete (head->next->previous);
    head->next->previous = head;
    return;
}

ostream *operator<<(ostream &os, StudentList *stuList)
{

    stuList->printHelper();
    return &os;
}


ostream& StudentList::isSuccessful( ostream& os, DomesticList *domesticList, InternationalList *internationalList)
{ 
    int countDomestic = 0;
    int countInternational = 0;

    InternationalStudent *tempInternational;
    DomesticStudent *tempDomestic;
    tempDomestic = domesticList->getHead();
    tempInternational = internationalList->getHead();

    while(tempDomestic != NULL && countDomestic <= 59){
        os << "Congratulations Domestic Student " << tempDomestic->getFirstName() << ' ' << tempDomestic->getLastName() << endl;
        os << "You have been admitted to SFU! ";
        os << '\n' << endl;
        os << "Full Student Details Below:" << '\n' << endl;
        os << *tempDomestic;

        os << '\n';
        os << "For more information contact us here: " << endl;
        os << "https://www.sfu.ca/students/contact.html" << endl;
        os << '\n' << endl;
        os << "-=-=-=-=-=-=-=--=-=-=--=-=-=--=-=-=--=-=-=-=-=-=-=-=-=-=--=-=-=--=-=-=--=-=-=--=-=-=-=-=-=-=-=-=-=--=-=-=--=-=-=--=-=-=--=-=-=-" << endl;
        os << '\n' << endl;

        tempDomestic = tempDomestic->next;
        countDomestic++;
    }

    while(tempInternational != NULL && countInternational <= 55){
        os << "Congratulations International Student " << tempInternational->getFirstName() << ' ' << tempInternational->getLastName() << endl;
        os << "You have been admitted to SFU! ";
        os << '\n' << endl;

        os << "Full Student Details Below:" << '\n' << endl;

        os << *tempInternational; 


        os << '\n';
        os << "For more information contact us here: " << endl;
        os << "https://www.sfu.ca/students/contact.html" << endl;
        os << '\n' << endl;

        os << "-=-=-=-=-=-=-=--=-=-=--=-=-=--=-=-=--=-=-=-=-=-=-=-=-=-=--=-=-=--=-=-=--=-=-=--=-=-=-=-=-=-=-=-=-=--=-=-=--=-=-=--=-=-=--=-=-=-" << endl;
        os << '\n' << endl;

        tempInternational = tempInternational->next;
        countInternational++;
    }

    return os;
}

ostream& StudentList::failedStudents(ostream &os, DomesticList *domesticList, InternationalList *internationalList)
{
    int countDomestic;
    int countInternational;

    InternationalStudent *tempInternational;
    DomesticStudent *tempDomestic;
    tempDomestic = domesticList->getHead();
    tempInternational = internationalList->getHead();

    for (countDomestic = 0; countDomestic <= 59; countDomestic++ ){
        tempDomestic = tempDomestic->next; 
    }
    tempDomestic = tempDomestic->next;
    countDomestic++;

    for (countInternational = 0; countInternational <= 55; countInternational++){
        tempInternational = tempInternational->next;
    }

    tempInternational = tempInternational->next; 
    countInternational++;

    while(tempDomestic != NULL && countDomestic >=60 && countDomestic <= 100){
        os << "Dear Domestic Student " << tempDomestic->getFirstName() << ' ' << tempDomestic->getLastName() << endl;
        os << "Unfortunately your scores were not competitive enough to be admitted into SFU " << endl;
        os << "Thank you so much for you application and we wish you the best in the future! " << endl;
        os << endl;

        os << "See Full Student Details Below:" << '\n' << endl;
        os << *tempDomestic;

        os << '\n';
        os << "For more information contact us here: " << endl;
        os << "https://www.sfu.ca/students/contact.html" << endl;
        os << '\n' << endl;

        os << "-=-=-=-=-=-=-=--=-=-=--=-=-=--=-=-=--=-=-=-=-=-=-=-=-=-=--=-=-=--=-=-=--=-=-=--=-=-=-=-=-=-=-=-=-=--=-=-=--=-=-=--=-=-=--=-=-=-" << endl;
        os << '\n' << endl;

        tempDomestic = tempDomestic->next;
        countDomestic++;
    }

    while(tempInternational != NULL && countInternational >= 56 ){
        os << "Dear International Student " << tempInternational->getFirstName() << ' ' << tempInternational->getLastName() << endl;
        os << "Unfortunately your scores were not competitive enough to be admitted into SFU " << endl;
        os << "Thank you so much for you application and we wish you the best in the future! " << endl;
        os << endl;

        os << "See Full Student Details Below:" << '\n' << endl;

        os << *tempInternational; 


        os << '\n';
        os << "For more information contact us here: " << endl;
        os << "https://www.sfu.ca/students/contact.html" << endl;
        os << '\n' << endl;

        os << "-=-=-=-=-=-=-=--=-=-=--=-=-=--=-=-=--=-=-=-=-=-=-=-=-=-=--=-=-=--=-=-=--=-=-=--=-=-=-=-=-=-=-=-=-=--=-=-=--=-=-=--=-=-=--=-=-=-" << endl;
        os << '\n' << endl;
        
        tempInternational = tempInternational->next;
        countInternational++;
    }

    return os;

}

void StudentList::printCutCGPA(float cgpa,int reasearchScore)   {  //print based on cgpa cutoff
    
    int count = 0;
    Node *temp = getHead();

    while(temp != NULL) {
        if(temp->studentObj.getCGPA() >= cgpa &&temp->studentObj.getResearchScore() >= reasearchScore) {    //traverse the list and check if value is higher then or equal to cutoff
            
            this->printHelper1(temp);
            count++;
            cout<<endl;
        }
        temp = temp->next;
    }

    if(count == 0)  {
        cout << "No one made the cutoff"<<endl;
    }
}

void StudentList::printCutRS(int reasearchScore) {      //print based on rs cutoff

    int count = 0;
    Node *temp = getHead();

    while(temp != NULL) {
        if(temp->studentObj.getResearchScore() >= reasearchScore) {     //traverse the list and check if value is higher then or equal to cutoff
            
            this->printHelper1(temp);
            count++;
            cout<<endl;
        }
        temp = temp->next;
    }

    if(count == 0)  {
        cout << "No one made the cutoff"<<endl;
    }
}

