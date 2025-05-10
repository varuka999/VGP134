// VGP134MidTerm.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "Registry.h"

//Part 2: The Schools District (70%)
//  Create a struct Student
//      id, name, grade, assignmentMarks (id does not have to be const)
//  Create a class School
//      id, name, students  (id does not have to be const) 
//      AddStudent
//      GradeStudents
//      GetAverage
//      GetStudents
//  Create a singleton Registry
//      schools, students
//      RegisterSchool - stores the new school
//      RegisterStudent - stores the new student and gets randomly assigned to a registered school
//      DistributeAssignments - randomly gives a mark to each student from 0-100
//      GetSchoolIds - returns all the school ids
//      GetSchool - returns the school with the id
//      ExchangeStudent - takes the id of student and a different school id, removes the student from their current school and adds to the new school
// 
//FLOW
//  Register 3 schools
//  Register 30 students
//  Distribute a random number of assignments (between 5-10)
//  Calculate the overall average for each student
//  In each School, Print the overall average of all the students as well as the number of students that pass (average over 54%)
//  Print which school has the heighest average
//  Exchange 6 students between the schools
//  Distribute 3 more assignments
//  In each School, Print the overall average of all the students as well as the number of students that pass (average over 54%)
//  Print which school has the heighest average


//  Application builds and runs:                    /50
//  Application functions as described:             /20
//  Build uses global accessors and stl containers: /20
//  Coding standards, minor errors:                 /10


int main()
{
	srand(time(NULL));

	std::cout << "The Schools District\n\n";

	int r = 5 + rand() % 6; // 5-10
	Registry::Get()->PrintEachSchoolsStudents();
	Registry::Get()->DistributeAssignments(r);

	for (int i = 0; i < 6; ++i)
	{
		int schoolID = rand() % Registry::Get()->GetAllSchools().size(); // 0-2
		int studentID = rand() % Registry::Get()->GetAllStudents().size(); // 0-29

		i = Registry::Get()->ExchangeStudent(studentID, schoolID) == true ? i : --i; // Ensures 6 transfers are made in case any failed transfers happen (exchanging a student to the same school they are at)
	}
	std::cout << "\n";

	Registry::Get()->PrintEachSchoolsStudents();
	Registry::Get()->DistributeAssignments(3);

	return 0;
}