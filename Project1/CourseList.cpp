/************************
    Pandemic Programmers

    Goshtasbi, Bamdad
    Nguyen, Charlie
    Rogers, Ryan
    Tran, Han

    CS A250 - Fall 2020

    Project 1
************************/

#include "CourseList.h"

using namespace std;

const int CourseList::CAP = 10;

// CourseList
CourseList::CourseList() {
    capacity = CAP;
    totalCourses = 0;
    courseList = new Course[CAP];
}

// Overloaded constructor
CourseList::CourseList(int _capacity) {
    capacity = _capacity;
    totalCourses = 0;
    courseList = new Course[capacity];
}

// Copy constructor
CourseList::CourseList(const CourseList& other) {
    capacity = other.capacity;
    totalCourses = other.totalCourses;

    courseList = new Course[capacity];

    for (int i = 0; i < capacity; ++i)
    {
        courseList[i] = other.courseList[i];
    }
}

// addCourse
void CourseList::addCourse(const Course& courseToAdd) {
    if (totalCourses >= capacity) {
        resize();
    }
    courseList[totalCourses++] = courseToAdd;
}

// getCourseUnits
double CourseList::getCourseUnits(const string& coursePrefix,
                                    int courseNo) const {

    for (int i = 0; i < totalCourses; i++) {
        if (courseList[i].getCoursePrefix() == coursePrefix
            && courseList[i].getCourseNo() == courseNo) {

            return courseList[i].getCourseUnits();
        }
    }
    return 0.0;
}

// searchCourse
bool CourseList::searchCourse(const string& coursePrefix,
                                        int courseNo) const {

    for (int i = 0; i < totalCourses; i++) {
        if (courseList[i].getCoursePrefix() == coursePrefix
            && courseList[i].getCourseNo() == courseNo) {

            return true;
        }
    }
    return false;
}

// overloaded operator=
CourseList& CourseList::operator=(const CourseList& other) {
    if (&other != this) {
        totalCourses = other.totalCourses;

        if (capacity != other.capacity) {
            delete[] courseList;
            capacity = other.capacity;
            courseList = new Course[other.capacity];
        }

        for (int i = 0; i < capacity; ++i)
        {
            courseList[i] = other.courseList[i];
        }
    }
    else {
        cerr << "Self-assignment is attempted" << endl;
    }

    return *this;    
}

// destructor
CourseList::~CourseList() {
    delete[] courseList;
    courseList = nullptr;
}

// resize
void CourseList::resize() {
    capacity *= 2;
    Course* newCourseList = new Course[capacity];

    for (int i = 0; i < totalCourses; i++) {
        newCourseList[i] = courseList[i];
    }

    delete[] courseList;
    courseList = newCourseList;
    newCourseList = nullptr;
}