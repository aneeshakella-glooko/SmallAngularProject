/************************
	Pandemic Programmers

	Goshtasbi, Bamdad
	Nguyen, Charlie
	Rogers, Ryan
	Tran, Han

	CS A250 - Fall 2020

	Project 1
************************/

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person
{
public:
	// default constructor
	Person();
	// overloaded constructor
	Person(const std::string& first, const std::string& last);
	
	// setName
	void setName(const std::string& first, const std::string& last);
	
	// getLastName
	std::string getLastName() const;

	// printName
	void printName() const;

	// destructor
	~Person();

private:
	std::string firstName;
	std::string lastName;
};

#endif 