/************************
	Pandemic Programmers

	Goshtasbi, Bamdad
	Nguyen, Charlie
	Rogers, Ryan
	Tran, Han

	CS A250 - Fall 2020

	Project 1
************************/

#include "Person.h"
#include <iostream>

using namespace std;

// default constructor
Person::Person() {
	firstName = "N/A";
	lastName = "N/A";
}

// overloaded constructor
Person::Person(const string& first, const string& last) 
{
	firstName = first;
	lastName = last;
}

// setName
void Person::setName(const string& first, const string& last) 
{
	firstName = first;
	lastName = last;
}

// getLastName
string Person::getLastName() const
{
	return lastName;
}

// printName
void Person::printName() const
{
	cout << lastName << ", " << firstName << endl;
}

// destructor
Person::~Person() {}