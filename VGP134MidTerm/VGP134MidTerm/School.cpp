#include "School.h"

School::School(int id, std::string name)
	: mID(id), mName(name)
{

}

School::~School()
{
	for (std::shared_ptr<Student> student : mStudents)
	{
		student.reset();
	}
}

void School::AddStudent(std::shared_ptr<Student>& student)
{
	mStudents.push_back(student);
}

int School::GradeStudents()
{
	int studentsPassed = 0;

	for (std::shared_ptr<Student> student : mStudents)
	{
		int gradeTotal = 0;
		int assignments = student->assignmentMarks.size();

		for (int i = 0; i < assignments; ++i)
		{
			gradeTotal += student->assignmentMarks[i];
		}

		student->grade = (float)gradeTotal / (float)assignments;

		if (student->grade > 54)
		{
			++studentsPassed;
		}
	}

	return studentsPassed;
}

float School::GetAverage()
{
	float gradesTotal = 0;

	for (std::shared_ptr<Student> student : mStudents)
	{
		gradesTotal += student->grade;
	}

	float gradesAverage = gradesTotal / (float)mStudents.size();

	return gradesAverage;
}

std::vector<std::shared_ptr<Student>>& School::GetStudents()
{
	return mStudents;
}

int School::GetSchoolID()
{
	return mID;
}

std::string School::GetSchoolName()
{
	return mName;
}

int School::ReturnSchoolSize()
{
	return mStudents.size();
}

void School::PrintAllStudents()
{
	std::cout << mName << " students: \n";

	for (std::shared_ptr<Student> student : mStudents)
	{
		std::cout << student->name << "\n";
	}

	std::cout << "\n";
}
