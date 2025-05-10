#pragma once
#include <string>
#include <vector>

struct Student
{
	Student(int id, std::string name);

	int id;
	std::string name;
	float grade;
	std::vector<int> assignmentMarks;
};