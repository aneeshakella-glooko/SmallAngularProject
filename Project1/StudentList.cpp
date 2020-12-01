/************************
    Pandemic Programmers

    Goshtasbi, Bamdad
    Nguyen, Charlie
    Rogers, Ryan
    Tran, Han

    CS A250 - Fall 2020

    Project 1
************************/

#include "StudentList.h"

using namespace std;

// default constructor
StudentList::StudentList() {

    first = nullptr;
    last = nullptr;
    count = 0;
}

// Copy constructor
StudentList::StudentList(const StudentList& other) {

    count = other.count;
    first = nullptr;
    last = nullptr;

    if (count > 0) {
        first = new Node(other.first->getStudent(), nullptr);

        Node* curr = first;
        Node* next;
        Node* otherNext = other.first->getNext();

        while (otherNext != nullptr) {
            next = new Node(otherNext->getStudent(), nullptr);
            curr->setNext(next);
            curr = next;

            otherNext = otherNext->getNext();
        }
        curr->setNext(nullptr);
        last = curr;
    }
}

// Overloaded operator=
StudentList& StudentList::operator=(const StudentList& other) {
    if (&other != this) {
        if (count == 0) {
            copyCallingObjIsEmpty(other);
        }
        else if (count == other.count) {
            copyObjectsSameLength(other);
        }
        else if (count < other.count) {
            copyCallingObjShorter(other);
        }
        else {
            copyCallingObjLonger(other);
        }
                    
    }
    else {
        cerr << "Self-assignment is attempted." << endl;
    }

    return *this;
}

// addStudent
void StudentList::addStudent(const Student& student) {        
    first = new Node(student, first);
    if(count == 0){
        last = first;
    } 
    count++;
}

// getNoOfStudents
int StudentList::getNoOfStudents() const {
    return count;
}

// printStudentByID
void StudentList::printStudentByID(int id) const {
    bool flag = false;

    if (first == nullptr) {
        cout << "List is empty" << endl;
    }
    else {
        Node* curr = first;

        while (!flag && curr != nullptr) {
            if (curr->getStudent().getID() == id) {
                flag = true;
                curr->getStudent().printStudentInfo();
            }
            //if (!flag) {
            //    curr = curr->getNext();
            //}
            curr = curr->getNext();
        }

        //if (flag) {
        //    curr->getStudent().printStudentInfo();
        //}
        if(!flag) {
            cout << "No student with ID " << id 
                << " found in the list" << endl;
        }

    }
}

// printStudentsByCourse
void StudentList::printStudentsByCourse(const string& coursePrefix,
                                            int courseNo) const {

    if (first == nullptr) {
        cout << "List is empty" << endl;
    }
    else {
        Node* curr = first;
        bool studentsFound = false;

        while (curr != nullptr) {

            if (curr->getStudent().getNumberOfCourses() > 0){

                if (curr->getStudent().courseIsCompleted
                                    (coursePrefix, courseNo)){

                    curr->getStudent().printStudent();
                    studentsFound = true;
                }      

            }
            curr = curr->getNext();
        }

        if (!studentsFound) {
            cout << "No students completed " << coursePrefix
                                << " " << courseNo << endl;
        }
    }
}

// printStudentByName
void StudentList::printStudentByName(const string& lastName) const {
    if (first == nullptr) {
        cout << "List is empty" << endl;
    }
    else {
        Node* curr = first;
        bool studentsFound = false;

        while (curr != nullptr) {

            if (curr->getStudent().getLastName() == lastName) {
                curr->getStudent().printStudent();
                studentsFound = true;
            }

            curr = curr->getNext();
        }

        if (!studentsFound) {
            cout << "No student with last name " << lastName 
                            << " found in the list" << endl;
        }

    }
}

// printStudentsOnHold
void StudentList::printStudentsOnHold() const {

    if (first == nullptr) {
        cout << "No students in the list." << endl;
    }
    else {
        Node* curr = first;
        bool studentFound = false;

        while (curr != nullptr) {
            if (!curr->getStudent().isTuitionPaid()) {

                curr->getStudent().printStudentInfo();
                studentFound = true;
            }
            curr = curr->getNext();
        }
        if (!studentFound) {
            cout << "There are no students on hold." << endl;
        }
    }
}

// printAllStudents
void StudentList::printAllStudents() const {

    if (first == nullptr) {
        cout << "List is empty" << endl;
    }
    else {
        Node* curr = first;

        while (curr != nullptr) {
            curr->getStudent().printStudentInfo();
            curr = curr->getNext();
        }
    }
}

// destroyStudentList
void StudentList::destroyStudentList() {

    Node* temp = first;

    while (first != nullptr)
    {
        first = first->getNext();
        delete temp;
        temp = first;
    }

    count = 0;
}

// destructor
StudentList::~StudentList() {
    destroyStudentList();
}

//private helper functions for copy functions
void StudentList::copyCallingObjIsEmpty(const StudentList& other) {
    count = other.count;

    first = new Node(other.first->getStudent(), nullptr);
    Node* curr = first;
    Node* otherCurr = other.first->getNext();

    while (otherCurr != nullptr) {
        curr->setNext(new Node(otherCurr->getStudent(), nullptr));

        curr = curr->getNext();
        otherCurr = otherCurr->getNext();
    }
    last = curr;
}

void StudentList::copyObjectsSameLength(const StudentList& other) {
    Node* curr = first;
    Node* otherCurr = other.first;

    while (curr != nullptr) {
        curr->setStudent(otherCurr->getStudent());

        curr = curr->getNext();
        otherCurr = otherCurr->getNext();
    }
}

void StudentList::copyCallingObjLonger(const StudentList& other) {
    //meaning this.count > other.count
    count = other.count;

    Node* curr = first;
    Node* otherCurr = other.first;

    while (otherCurr->getNext() != nullptr) {
        curr->setStudent(otherCurr->getStudent());

        curr = curr->getNext();
        otherCurr = otherCurr->getNext();

    }
    curr->setStudent(otherCurr->getStudent());
    last = curr;
    curr = curr->getNext();
    
    //delete the rest of this list
    while (curr != nullptr) {
        Node* next = curr->getNext();
        delete curr;
        curr = next;
    }
    last->setNext(nullptr);
}

void StudentList::copyCallingObjShorter(const StudentList& other) {
    //meaning this.count < other.count
    count = other.count;

    Node* curr = first;
    Node* otherCurr = other.first;

    //fill the first node
    curr->setStudent(otherCurr->getStudent());

    //using the space already had in this list to copy
    //check if the next is null
    while (curr->getNext() != nullptr) {
        curr = curr->getNext();
        otherCurr = otherCurr->getNext();
        curr->setStudent(otherCurr->getStudent());
    }

    //start creating new nodes to copy other elements
    //curr = new Node(otherCurr->getStudent(), nullptr);
    //otherCurr = otherCurr->getNext();
    //curr = curr->getNext();
    
    //if the next one is null, meaning that this list ends
    //then start copying from the other list
    while (otherCurr->getNext() != nullptr) {
        //curr = curr->getNext();
        otherCurr = otherCurr->getNext();
        curr->setNext(new Node(otherCurr->getStudent(), nullptr));
        curr = curr->getNext();
        //otherCurr = otherCurr->getNext();
    }
    last = curr;
}
