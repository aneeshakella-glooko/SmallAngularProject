/************************
	Pandemic Programmers

	Goshtasbi, Bamdad
	Nguyen, Charlie
	Rogers, Ryan
	Tran, Han

	CS A250 - Fall 2020

	Project 1
************************/

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class Course
{
public:
	// default constructor
	Course();

	// setCourseInfo
	void setCourseInfo(const std::string& name,
		const std::string& prefix, int number, double units);

	// getCourseName
	std::string getCourseName() const;

	// getCoursePrefix
	std::string getCoursePrefix() const;

	// getCourseNo
	int getCourseNo() const;

	// getCourseUnits
	double getCourseUnits() const;

	// printCourseInfo
	void printCourseInfo() const;

	// destructor;
	~Course();

	//overloaded operator<
	bool operator<(const Course& rhs) const;
	
private:
	std::string courseName;
	std::string coursePrefix;
	int courseNo;
	double courseUnits;
};

#endif
