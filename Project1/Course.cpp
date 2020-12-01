/************************
	Pandemic Programmers

	Goshtasbi, Bamdad
	Nguyen, Charlie
	Rogers, Ryan
	Tran, Han
	
	CS A250 - Fall 2020
	
	Project 1
************************/

#include "Course.h"
#include <iostream>
#include <iomanip>

using namespace std;

// default constructor
Course::Course()
{
	courseNo = 0;
	courseUnits = 0;	
}

// setCourseInfo
void Course::setCourseInfo(const string& name, const string& prefix,
									int number, double units)
{
	courseName = name;
	coursePrefix = prefix;
	courseNo = number;
	courseUnits = units;
}

// getCourseName
string Course::getCourseName() const
{
	return courseName;
}

// getCoursePrefix
string Course::getCoursePrefix() const
{
	return coursePrefix;
}

// getCourseNo
int Course::getCourseNo() const
{
	return courseNo;
}

// getCourseUnits
double Course::getCourseUnits() const
{
	return courseUnits;
}

// printCourseInfo
void Course::printCourseInfo() const
{
	cout << left;
	cout << setw(4) << coursePrefix << setw(8) << courseNo;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << setw(4) << courseUnits;
}

//overloaded operator<
bool Course::operator<(const Course& rhs) const{
	return courseName < rhs.courseName;
}

// destructor;
Course::~Course(){}