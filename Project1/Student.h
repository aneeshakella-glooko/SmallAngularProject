/************************
	Pandemic Programmers

	Goshtasbi, Bamdad
	Nguyen, Charlie
	Rogers, Ryan
	Tran, Han

	CS A250 - Fall 2020

	Project 1
************************/

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Course.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <iterator>
#include <fstream>
#include <string>

class Student : public Person
{
public:
	// default constructor
	Student(); 
	// setStudentInfo
	void setStudentInfo(const std::string& first, 
		const std::string& last, int id, bool tuitionPaid,
						std::multimap<Course, char> courses);

	// getID
	int getID() const;

	// getNumberOfCourses
	int getNumberOfCourses() const;

	// getUnitsCompleted
	double getUnitsCompleted() const;
	// getGpa
	double getGPA() const;

	// isTuitionPaid
	bool isTuitionPaid() const;

	// courseIsCompleted
	bool courseIsCompleted(const std::string& prefix, int number) const;


	// printStudent
	void printStudent() const;
	// printStudentInfo
	void printStudentInfo() const;

	// destructor
	~Student();
	

private:
	int studentID;		
	int totalCourses;
	bool tuitionWasPaid;
	std::multimap<Course, char> coursesCompleted;
};

#endif


