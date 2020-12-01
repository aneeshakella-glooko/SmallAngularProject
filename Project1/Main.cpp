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
#include "Course.h"
#include "InputHandler.h"
#include "CourseList.h"
#include "StudentList.h"
#include "ExceptionHandler.h"

#include <algorithm> 

#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

/////////////////	PROVIDED MAIN.CPP	////////////////////


void displayMenu();
void processChoice(const StudentList& studentList,
	const CourseList& courseList);

int main()
{
	system("Color 3F");
	CourseList courseList;
	StudentList studentList;

	readData(courseList, studentList);
	displayMenu();
	processChoice(studentList, courseList);

	//cout << endl;
	system("Pause");
	return 0;
}

void displayMenu()
{
	cout << "\n*** MAIN MENU ***\n";
	cout << "\nSelect one of the following:\n\n";
	cout << "    1: Search student by last name" << endl;
	cout << "    2: Print student information" << endl;
	cout << "    3: Print all students" << endl;
	cout << "    4: Print students by course" << endl;
	cout << "    5: Print students on hold" << endl;
	cout << "    6: Exit" << endl;
}

void processChoice(const StudentList& studentList,
	const CourseList& courseList)
{
	int id = 0, courseNo = 0;
	bool valid = false;
	string inputID, inputCourseNo, input, coursePrefix, lastName;
	ExceptionHandler exception;

	cout << "\nEnter your selection: ";
	getline(cin, input);
	int selection = exception.validateSelection(input);
	cout << endl;

	cout << fixed << showpoint << setprecision(2);

	while (selection != 6)
	{
		string fName, lName;

		switch (selection)
		{

			// Search student by last name
		case 1:
			cout << "  => Please enter the student's last name: ";
			getline(cin, lastName);
			exception.lastNameValid(lastName);
			cout << endl;
			if (exception.lastNameValid(lastName))
				studentList.printStudentByName(lastName);
			else
				cout << "Incorrect input. Try again.\n";
			cout << endl;

			break;

			// Print student information
		case 2:
			cout << "  => Please enter student's ID: ";
			getline(cin, input);
			cout << endl;
			if (exception.validateID(input, id))
				studentList.printStudentByID(id);
			cout << endl;

			break;

			// Print all students
		case 3:
			studentList.printAllStudents();
			cout << endl;

			break;

			// Print students by course 
		case 4:
			cout << "  => Please enter the course prefix (CSC, HIS, etc.): ";
			getline(cin, coursePrefix);
			cout << "  => Please enter the course number: ";
			getline(cin, inputCourseNo);
			cout << endl;
			valid = exception.validateCoursePrefix(coursePrefix);
			if (exception.validateCourseNo(inputCourseNo, courseNo) && valid)
			{
				if (!courseList.searchCourse(coursePrefix, courseNo))
					cout << "This course is not in the catalog." << endl;
				else
					studentList.printStudentsByCourse(coursePrefix, courseNo);
			}
			cout << endl;

			break;

			// Print students on hold
		case 5:
			studentList.printStudentsOnHold();
			cout << endl;

			break;

			// Incorrect selection
		default:
			cout << "  => Invalid entry. Please try again.\n\n";

			break;
		}

		cout << "  => ";
		system("Pause");
		cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
		displayMenu();

		cout << "\nEnter your selection: ";
		getline(cin, input);
		selection = exception.validateSelection(input);
		cout << endl;
	}

	if (selection == 6)
		cout << "Thank you for using our software! Good-bye!\n";
	cout << endl;
}






///////////////////////		OUR MAIN.CPP	//////////////////////////
/*
int main()
{
	system("Color 3F");
	//The start of Course Class testing
	cout << "************************"
		<< "Testing Course Class"
		<< "************************";
	cout << "\n\nTesting Default contructor and get functions"
		<< "\nExpecting empty strings as well as 0's:";

	Course defaultCourse;

	cout << "\ncourseName: " << defaultCourse.getCourseName()
		<< "\ncoursePrefix: " << defaultCourse.getCoursePrefix()
		<< "\nccourseNo: " << defaultCourse.getCourseNo()
		<< "\ncourseUnits: " << defaultCourse.getCourseUnits();

	cout << "\n\nTesting setCourseInfo and getters."
		<< "\nExpecting,' C++ 2, CS, 250, 4':";

	defaultCourse.setCourseInfo("C++ 2", "CS", 250, 4.0);

	cout << "\ncourseName: " << defaultCourse.getCourseName()
		<< "\ncoursePrefix: " << defaultCourse.getCoursePrefix()
		<< "\nccourseNo: " << defaultCourse.getCourseNo()
		<< "\ncourseUnits: " << defaultCourse.getCourseUnits();

	cout << "\n\nTesting Print Info."
		<< "\nExpecting, 'CS, 250, 4':\n";

	defaultCourse.printCourseInfo();

	//The start of Person Class testing.
	cout << "\n\n************************"
		<< "Testing Person Class"
		<< "************************";
	cout << "\n\nTesting Default contructor, get function, and printName"
		<< "\nExpecting lastname 'N/A' and 'N/A, N/A' for print Name:";

	Person defaultPerson;

	cout << "\nLast Name: " << defaultPerson.getLastName()
		<< "\nprintName: ";
	defaultPerson.printName();

	cout << "\nTesting Overloaded contructor, get function, and printName"
		<< "\nExpecting lastname 'Rogers' and 'Rogers, Ryan' for print Name:";

	Person overloadPerson("Ryan", "Rogers");

	cout << "\nLast Name: " << overloadPerson.getLastName()
		<< "\nprintName: ";
	overloadPerson.printName();

	cout << "\nTesting setName, get function, and printName"
		<< "\nExpecting lastname 'Tran' and 'Tran, Han' for print Name:";

	overloadPerson.setName("Han", "Tran");

	cout << "\nLast Name: " << overloadPerson.getLastName()
		<< "\nprintName: ";
	overloadPerson.printName();

	//The start of Student Class testing
	cout << "\n\n************************"
		<< "Testing Student Class"
		<< "************************" << endl;

	//multimap<Course, char> charsCourses;
	Course bio;
	bio.setCourseInfo("Biology", "BIO", 234, 4.0);
	//course1.insert({ bio, 'A' });

	Course chem;
	chem.setCourseInfo("Chemistry", "CHM", 348, 4.0);
	//course1.insert({ chem, 'B' });

	Course compsci;
	compsci.setCourseInfo("CompSci", "CSC", 150, 4.0);
	//course1.insert({ compsci, 'A' });

	Course eng;
	eng.setCourseInfo("English", "ENG", 101, 3.0);
	//course1.insert({ eng, 'A' });


	multimap<Course, char> charsCourses = { {bio, 'A'},
	{chem, 'B'}, {compsci, 'A'}, {eng, 'B'} };

	Student charlie;
	charlie.setStudentInfo("Charlie", "Nguyen", 123456, true, charsCourses);
	charlie.printStudentInfo();


	Course psych;
	psych.setCourseInfo("Psychology", "PSYC", 100, 3.0);

	Course film;
	film.setCourseInfo("Film", "FILM", 100, 3.0);

	Course calc;
	calc.setCourseInfo("Calculus 3", "MATH", 280, 4.0);

	Course physics;
	physics.setCourseInfo("Physics", "PHY", 140, 4.0);


	multimap<Course, char> hansCourses = { {psych, 'A'},
	{film, 'A'}, {calc, 'A'}, {physics, 'A'} };

	Student han;
	han.setStudentInfo("Han", "Tran", 120920, true, hansCourses);
	han.printStudentInfo();


	Course comm;
	comm.setCourseInfo("Communication", "COM", 100, 3.0);

	Course viet;
	viet.setCourseInfo("Vietnamese", "VIET", 100, 3.0);


	multimap<Course, char> ryansCourses = { {comm, 'A'},
	{viet, 'A'} };

	Student ryan;
	ryan.setStudentInfo("Ryan", "Rogers", 714714, false, ryansCourses);
	ryan.printStudentInfo();


	Course softeng;
	softeng.setCourseInfo("Software Engineering", "CSC", 220, 4.0);

	Course econ;
	econ.setCourseInfo("Economics", "ECON", 110, 4.0);


	multimap<Course, char> bamsCourses = { {comm, 'B'},
	{viet, 'B'}, {softeng, 'A'}, {econ, 'A'} };

	Student bamdad;
	bamdad.setStudentInfo("Bamdad", "Goshtasbi", 654321, false, bamsCourses);
	bamdad.printStudentInfo();

	cout << "Testing Student functions on Han" << endl;

	cout << "Function: getID()" << endl;
	cout << "Expected: 12092000" << endl;
	cout << "Actual: " << han.getID() << endl;

	cout << "Function: getNumberOfCourses" << endl;
	cout << "Expected: 4" << endl;
	cout << "Actual: " << han.getNumberOfCourses() << endl;

	cout << "Function: getUnitsCompleted" << endl;
	cout << "Expected: 14" << endl;
	cout << "Actual: " << han.getUnitsCompleted() << endl;

	cout << "Function: getGPA" << endl;
	cout << "Expected: 4.0" << endl;
	cout << "Actual: " << han.getGPA() << endl;

	cout << "Function: isTuitionPaid" << endl;
	cout << "Expected: yes" << endl;
	cout << "Actual: ";
	if (han.isTuitionPaid()) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	cout << "Function: courseIsCompleted (comp sci)" << endl;
	cout << "Expected: no" << endl;
	cout << "Actual: ";
	if (han.courseIsCompleted("CSC", 150)) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	cout << "Function: courseIsCompleted (psychology)" << endl;
	cout << "Expected: yes" << endl;
	cout << "Actual: ";
	if (han.courseIsCompleted("PSYC", 100)) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}


	//The start of CourseList Class testing
	cout << "\n\n************************"
		<< "Testing CourseList Class"
		<< "************************" << endl;	

	CourseList list1;
	CourseList list2(20);

	list1.addCourse(bio);
	list1.addCourse(chem);
	list1.addCourse(compsci);
	list1.addCourse(eng);
	list1.addCourse(psych);
	list1.addCourse(film);
	list1.addCourse(calc);
	list1.addCourse(physics);
	list1.addCourse(comm);
	list1.addCourse(viet); //resize the array here
	list1.addCourse(econ);
	list1.addCourse(softeng);

	list2 = list1;
	CourseList list3(list1);

	cout << "Testing CourseList functions on list1" << endl;

	cout << "Function: getCourseUnit (software engineering)" << endl;
	cout << "Expected: 4" << endl;
	cout << "Actual: " << list1.getCourseUnits("CSC", 220) << endl;

	cout << "Function: searchCourse (comp sci)" << endl;
	cout << "Expected: yes" << endl;
	cout << "Actual: ";
	if (list1.searchCourse("CSC", 150)) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	cout << "Testing CourseList functions on list2" << endl;

	cout << "Function: getCourseUnit (vietnamese)" << endl;
	cout << "Expected: 3" << endl;
	cout << "Actual: " << list2.getCourseUnits("VIET", 100) << endl;

	cout << "Function: searchCourse (political science)" << endl;
	cout << "Expected: no" << endl;
	cout << "Actual: ";
	if (list1.searchCourse("POLSCI", 150)) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	cout << "Testing CourseList functions on list3" << endl;

	cout << "Function: getCourseUnit (film)" << endl;
	cout << "Expected: 3" << endl;
	cout << "Actual: " << list3.getCourseUnits("FILM", 100) << endl;

	cout << "Function: searchCourse (communication)" << endl;
	cout << "Expected: yes" << endl;
	cout << "Actual: ";
	if (list1.searchCourse("COM", 100)) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}


	//The start of StudentList Class testing
	cout << "\n\n************************"
		<< "Testing StudentList Class"
		<< "************************" << endl;

	StudentList ourgroup;

	cout << "Testing StudentList functions on our group" << endl;

	cout << "Function: getNoOfStudents" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual: " << ourgroup.getNoOfStudents() << endl;

	ourgroup.addStudent(han);
	ourgroup.addStudent(charlie);
	ourgroup.addStudent(ryan);
	ourgroup.addStudent(bamdad);

	cout << "Function: getNoOfStudents" << endl;
	cout << "Expected: 4" << endl;
	cout << "Actual: " << ourgroup.getNoOfStudents() << endl;

	cout << "Function: printStudentByID (12092000)" << endl;
	cout << "Expected: Han's information" << endl;
	cout << "Actual: ";
	ourgroup.printStudentByID(12092000);
	cout << endl;

	cout << "Function: printStudentByCourse (CSC)" << endl;
	cout << "Expected: Charlie's information" << endl;
	cout << "Actual: ";
	ourgroup.printStudentsByCourse("CSC", 150);
	cout << endl;

	cout << "Function: printStudentsOnHold" << endl;
	cout << "Expected: Bamdad's & Ryan's information" << endl;
	cout << "Actual: ";
	ourgroup.printStudentsOnHold();
	cout << endl;

	cout << "Making a copy of our group using copy constructor" << endl;
	StudentList ourclones(ourgroup);
	
	cout << "Testing StudentList functions on our clones" << endl;

	cout << "Function: getNoOfStudents" << endl;
	cout << "Expected: 4" << endl;
	cout << "Actual: " << ourgroup.getNoOfStudents() << endl;

	cout << "Function: printStudentByName (Goshtasbi)" << endl;
	cout << "Expected: Bamdad's information" << endl;
	cout << "Actual: ";
	ourgroup.printStudentByName("Goshtasbi");
	cout << endl;

	cout << "Function: printAllStudents" << endl;
	cout << "Expected: our clones' information" << endl;
	cout << "Actual: ";
	ourgroup.printAllStudents();
	cout << endl;

	//The start of 4 helper functions testing
	cout << "\n\n************************"
		<< "Testing 4 helper functions in StudentList"
		<< "************************" << endl;

	
	StudentList boys;
	boys.addStudent(charlie);
	boys.addStudent(bamdad);
	boys.addStudent(ryan);

	StudentList labPartners;
	labPartners.addStudent(han);
	labPartners.addStudent(charlie);
	labPartners.addStudent(bamdad);

	StudentList girlAndBoy;
	girlAndBoy.addStudent(bamdad);
	girlAndBoy.addStudent(han);

	cout << "Function: copyCallingObjIsEmpty" << endl;
	StudentList empty;
	cout << "Printing empty" << endl;
	empty.printAllStudents();
	cout << "Printing empty after using operator=" << endl;
	empty = ourclones;
	empty.printAllStudents();
	cout << endl;

	cout << "Function: copyObjectsSameLength" << endl;
	cout << "Printing boys" << endl;
	boys.printAllStudents();
	cout << "Printing labPartners" << endl;
	labPartners.printAllStudents();
	cout << "Printing boys after boys = labPartners" << endl;
	boys = labPartners;
	boys.printAllStudents();
	cout << endl;

	cout << "Function: copyCallingObjLonger" << endl;
	cout << "Printing our clones" << endl;
	ourclones.printAllStudents();
	cout << "Printing boys" << endl;
	boys.printAllStudents();
	cout << "Printing ourclones after ourclones = boys" << endl;
	ourclones = boys;
	ourclones.printAllStudents();
	cout << endl;

	cout << "Function: copyCallingObjShorter" << endl;
	cout << "Printing girlAndBoy" << endl;
	girlAndBoy.printAllStudents();
	cout << "Printing labPartners" << endl;
	labPartners.printAllStudents();
	cout << "Printing girlAndBoy after girlAndBoy = labPartners" << endl;
	girlAndBoy = labPartners;
	girlAndBoy.printAllStudents();
	cout << endl;
	






	cout << endl;
	system("Pause");
	return 0;
}

*/
