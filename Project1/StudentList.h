/************************
	Pandemic Programmers

	Goshtasbi, Bamdad
	Nguyen, Charlie
	Rogers, Ryan
	Tran, Han

	CS A250 - Fall 2020

	Project 1
************************/

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

#include <iostream>
#include <string>

class Node
{
public:
	Node() : student(), next(nullptr) {}
	Node(const Student& newStudent, Node* newNext)
		: student(newStudent), next(newNext) {}
	Student getStudent() const { return student; }
	Node* getNext() const { return next; }
	void setStudent(const Student& newStudent) { student = newStudent; }
	void setNext(Node* newNext) { next = newNext; }
private:
	Student student;
	Node* next;
};

class StudentList
{
public:
	// default constructor
	StudentList();

	//copy constructor
	StudentList(const StudentList& other);
	//overloaded operator=
	StudentList& operator=(const StudentList& other);

	// addStudent
	void addStudent(const Student& student);

	// getNoOfStudents
	int getNoOfStudents() const;


	// printStudentByID
	void printStudentByID(int id) const;

	// printStudentsByCourse
	void printStudentsByCourse(const std::string& coursePrefix,
											int courseNo) const;
	// printStudentByName

	void printStudentByName(const std::string& lastName) const;

	// printStudentsOnHold
	void printStudentsOnHold() const;

	// printAllStudents
	void printAllStudents() const;


	// destroyStudentList
	void destroyStudentList();

	// destructor
	~StudentList();

private:
	Node* first;
	Node* last;
	int count;
	
	//private copy functions
	void copyCallingObjIsEmpty(const StudentList& other);
	void copyObjectsSameLength(const StudentList& other);
	void copyCallingObjLonger(const StudentList& other);
	void copyCallingObjShorter(const StudentList& other);

};

#endif