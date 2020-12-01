/************************
	Pandemic Programmers

	Goshtasbi, Bamdad
	Nguyen, Charlie
	Rogers, Ryan
	Tran, Han

	CS A250 - Fall 2020

	Project 1
************************/

#include "Student.h"
#include <iostream>
#include <iomanip>
#include <map>
#include <iterator>

using namespace std;

// default constructor
Student::Student() : Person(), studentID(0), totalCourses(0),
									tuitionWasPaid(false) {}

// setStudentInfo
void Student::setStudentInfo(const string& first, const string& last,
	int id, bool tuitionPaid, multimap<Course, char> courses)
{
	Person::setName(first, last);
	studentID = id;
	tuitionWasPaid = tuitionPaid;
	coursesCompleted = courses;
	totalCourses = getNumberOfCourses();
}

// getID
int Student::getID() const
{
	return studentID;
}

// getNumberOfCourses
int Student::getNumberOfCourses() const
{
	//int count = 0;

	//multimap<Course, char>::const_iterator start
	//	= coursesCompleted.cbegin();
	//multimap<Course, char>::const_iterator end
	//	= coursesCompleted.cend();
	//for (; start != end; start++) {
	//	//count++;
	//	++totalCourses;
	//}
	//this->totalCourses += count;
	int sizeOfCourses = static_cast<int>(coursesCompleted.size());
	return sizeOfCourses;
}

// getUnitsCompleted
double Student::getUnitsCompleted() const
{
	
	multimap<Course, char>::const_iterator start 
						= coursesCompleted.cbegin();
	multimap<Course, char>::const_iterator end 
						= coursesCompleted.cend();
	
	double totalUnits = 0;

	for (; start != end; start++) {
		//Course courseFirst = start->first;
		totalUnits += (start->first).getCourseUnits();
	}
	return totalUnits;
}

// getGpa
double Student::getGPA() const
{
	double totalGPA = 0.0;
	double total = 0;
	double count = 0;

	multimap<Course, char>::const_iterator start
							= coursesCompleted.cbegin();
	multimap<Course, char>::const_iterator end
							= coursesCompleted.cend();

	for (; start != end; start++) {
		//char gradeLetter = start->second;
		switch (start->second) {
			case('A'):
				total += 4.0 * (start->first.getCourseUnits());
				count += start->first.getCourseUnits();
				break;
			case('B'):
				total += 3.0 * (start->first.getCourseUnits());
				count += start->first.getCourseUnits();
				break;
			case ('C'):
				total += 2.0 * (start->first.getCourseUnits());
				count += start->first.getCourseUnits();
				break;
			case ('D'):
				total += (start->first.getCourseUnits());
				count += start->first.getCourseUnits();
				break;
			case('F'):
				count += start->first.getCourseUnits();
				break;
			default:
				cerr << "Invalid Course Grade" << endl;
			
		}
	}
	totalGPA = total / count;
	return totalGPA;
}

// isTuitionPaid
bool Student::isTuitionPaid() const
{
	return tuitionWasPaid;
}

// courseIsCompleted
bool Student::courseIsCompleted(const string& prefix, int number) const
{
	multimap<Course, char>::const_iterator start 
							= coursesCompleted.cbegin();
	multimap<Course, char>::const_iterator end
							= coursesCompleted.cend();

	for (; start != end; start++) {
		if (prefix == (start->first).getCoursePrefix()
			&& number == (start->first).getCourseNo()) {
			return true;
		}
	}
	return false;
}

// printStudent
void Student::printStudent() const
{
	cout << studentID << " - ";
	Person::printName();
	//cout << endl;
}

// printStudentInfo
void Student::printStudentInfo() const
{
	cout << "Student Name: ";
	Person::printName();
	cout << endl;

	cout << endl;

	cout << "Student ID: " << studentID << endl;
	cout << "Number of courses completed: " << totalCourses << endl;
	cout << endl;

	//cout << setw(14) << "Course" << setw(16) 
	//<< "Units" << setw(15) << "Grade" << endl;

	cout << left << setw(11) << "Course" << left 
					<< setw(10) << "Units" << "Grade" << endl;

	multimap<Course, char>::const_iterator start
								= coursesCompleted.cbegin();
	multimap<Course, char>::const_iterator end
								= coursesCompleted.cend();

	for (; start != end; start++) {
		(start->first).printCourseInfo();
		if (tuitionWasPaid) {
			cout << right << setw(8) << start->second << endl;
		}
		else {
			cout << right << setw(10) << "***" << endl;
		}
	}

	cout << endl;
	cout << "Total number of unit hours: " 
				<< static_cast<int> (getUnitsCompleted()) << endl;
	cout << setprecision(2);
	if (tuitionWasPaid) {
		cout << "Current Term GPA: " << getGPA() << endl;
	}
	else {
		cout << "*** Grades are being held for"
			<< " not paying the tuition. ***" << endl;
	}
	cout << endl;
	for (int i = 0; i < 24; i++) {
		cout << "-*";
	}
	cout << "-";
	cout << endl;
}

// destructor
Student::~Student() {}