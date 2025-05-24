#include "Registry.h"
#include <iostream>

Registry* Registry::Get()
{
	static std::unique_ptr<Registry> sInstance;

	if (sInstance == nullptr)
	{
		sInstance = std::make_unique<Registry>();
	}

	return sInstance.get();
}

Registry::Registry()
{
	RegisterSchool("LCV");
	RegisterSchool("VFS");
	RegisterSchool("ISB");

	int schoolIndex = 0;

	while (!mStudentNamesVector.empty())
	{
		int r = rand() % mStudentNamesVector.size();
		RegisterStudent(mStudentNamesVector[r], schoolIndex);
		mStudentNamesVector.erase(mStudentNamesVector.begin() + r);

		if (mAllSchools[schoolIndex]->ReturnSchoolSize() >= 10) // Each school gets an evenly distributed 10 students to start
		{
			++schoolIndex;
		}
	}
}

Registry::~Registry()
{
	for (School* school : mAllSchools)
	{
		delete school;
	}

	mAllSchools.clear();

	for (std::shared_ptr<Student> student : mAllStudents)
	{
		student.reset();
	}

	mAllStudents.clear();
}

void Registry::RegisterSchool(std::string name)
{
	School* school = new School(mAllSchools.size() + 1, name);
	mAllSchools.push_back(school);
}

void Registry::RegisterStudent(std::string name, int school)
{
	std::shared_ptr<Student> student = std::make_shared<Student>(mAllStudents.size() + 1, name);
	mAllStudents.push_back(student);

	mAllSchools[school]->AddStudent(student);
}

void Registry::DistributeAssignments(int assignemntsToDistribute)
{
	for (std::shared_ptr<Student> student : mAllStudents)
	{
		for (int i = 0; i < assignemntsToDistribute; ++i)
		{
			int g = rand() % 101;

			student->assignmentMarks.push_back(g);
		}
	}

	int schoolHighestIndex = 0;

	for (int i = 0; i < mAllSchools.size(); ++i)
	{
		int studentsPassed = mAllSchools[i]->GradeStudents();

		float gradesAverage = mAllSchools[i]->GetAverage();
		schoolHighestIndex = gradesAverage > mAllSchools[schoolHighestIndex]->GetAverage() ? i : schoolHighestIndex;

		std::cout << "Average Grade of all Students at " << mAllSchools[i]->GetSchoolName() << ": " << gradesAverage << ".\n";
		std::cout << studentsPassed << " students from " << mAllSchools[i]->ReturnSchoolSize() << " passed.\n\n";
	}

	std::cout << mAllSchools[schoolHighestIndex]->GetSchoolName() << " has the highest average!\n\n";
}

bool Registry::ExchangeStudent(int studentID, int schoolID)
{
	studentID = ValidateIntIndex(studentID, mAllStudents.size() - 1); // Safety net in case ID is out of range
	schoolID = ValidateIntIndex(schoolID, mAllSchools.size() - 1); // Safety net in case ID is out of range

	if (studentID >= 0 && schoolID >= 0)
	{
		for (int i = 0; i < mAllSchools.size(); ++i)
		{
			int studentIndex = 0;

			for (std::shared_ptr<Student> student : mAllSchools[i]->GetStudents())
			{
				if (student->id == studentID)
				{
					if (schoolID == i)
					{
						//std::cout << "Can't transfer the student to the same school!\n";
						return false;
					}

					mAllSchools[schoolID]->AddStudent(student);
					mAllSchools[i]->GetStudents().erase(mAllSchools[i]->GetStudents().begin() + studentIndex);

					std::cout << "Transfered " << student->name << " from " << mAllSchools[i]->GetSchoolName() << " to " << mAllSchools[schoolID]->GetSchoolName() << ".\n";

					return true;
				}

				++studentIndex;
			}
		}
	}

	return false;
}

School* Registry::GetSchool(int id)
{
	for (School* school : mAllSchools)
	{
		if (school->GetSchoolID() == id)
		{
			return school;
		}
	}

	return nullptr;
}

const std::vector<School*> Registry::GetAllSchools()
{
	return mAllSchools;
}

const std::list<std::shared_ptr<Student>> Registry::GetAllStudents()
{
	return mAllStudents;
}

void Registry::PrintEachSchoolsStudents()
{
	for (School* school : mAllSchools)
	{
		school->PrintAllStudents();
	}
}

int Registry::ValidateIntIndex(int index, int maxRangeInclusive)
{
	if (index < 0 || index > maxRangeInclusive)
	{
		return -1;
	}

	return index;
}