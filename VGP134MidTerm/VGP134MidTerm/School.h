#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

class School
{
public:
	School(int id, std::string name);
	~School();

	void AddStudent(std::shared_ptr<Student>& student);
	int GradeStudents();
	float GetAverage();

	std::vector<std::shared_ptr<Student>>& GetStudents();
	int GetSchoolID();
	std::string GetSchoolName();
	int ReturnSchoolSize();

	void PrintAllStudents();

private:
	int mID;
	std::string mName;
	std::vector<std::shared_ptr<Student>> mStudents;
};