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

#ifndef COURSELIST_H
#define COURSELIST_H


class CourseList
{
public:
	// CourseList
	CourseList();

	// Overloaded constructor
	CourseList(int _capacity);

	// Copy constructor
	CourseList(const CourseList& courseList);

	// addCourse
	void addCourse(const Course& course);

	// getCourseUnits
	double getCourseUnits(const std::string &coursePrefix, 
		int courseNo) const;

	// searchCourse
	bool searchCourse(const std::string& coursePrefix, 
		int courseNo) const;

	// overloaded operator=
	CourseList& operator=(const CourseList& courseList);

	// destructor
	~CourseList();

private:
	Course* courseList;	
	int totalCourses;
	int capacity;
	static const int CAP;

	void resize();
};

#endif
