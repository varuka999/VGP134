#pragma once
#include <iostream>
#include <string>
#include <list>
#include "School.h"
#include "Student.h"

class Registry
{
public:
	static Registry* Get();

	Registry();
	~Registry();

	void RegisterSchool(std::string name);
	void RegisterStudent(std::string name, int school);
	void DistributeAssignments(int assignemntsToDistribute);
	bool ExchangeStudent(int studentID, int schoolID);

	School* GetSchool(int id);
	const std::vector<School*> GetAllSchools();
	const std::list<std::shared_ptr<Student>> GetAllStudents();

	void PrintEachSchoolsStudents();
	int ValidateIntIndex(int index, int maxRangeInclusive);

private:
	std::vector<School*> mAllSchools;
	std::list<std::shared_ptr<Student>> mAllStudents;

	std::vector<std::string> mStudentNamesVector { "Sarah", "Jayden", "Hunter", "Timothy", "Trinette", "Chloe", "Jina", "Renee", "Markus", "Sean", "Emmy", "Sabrina", "Michael", "Michelle", "Kelly", "Ashley", "April", "Mark", "Ryan", "Johnathan", "Donovan", "Arunav", "Nicole", "Arthur", "Joe", "Thiago", "Santiago", "Aiden", "Kobe", "Vincent"};
};