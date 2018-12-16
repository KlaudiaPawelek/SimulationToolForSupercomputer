 #include "Course.h"

// Default, empty constructor.
Course::Course()
{

}

// Constructor with parameters.
Course::Course(TypeOfCourse typeOfCourse, int numberOfStudents, int budget)
{
	this->typeOfCourse = typeOfCourse;
	this->numberOfStudents = numberOfStudents;
	this->student.resize(numberOfStudents);
	for (int i = 0; i < numberOfStudents; i++)
	{
		//Create students and save it into vector.
		this->student[i] = Student(i);
	}
	this->budget = budget;
}

// Default destructor.
Course::~Course()
{
	
}

// Return job from each student, for given course.
vector<Job>* Course::GetJobs()
{
	for (int i = 0; i < this->student.size(); i++)
	{
		for (int j = 0; j < this->student[i].GetNumbersOfJobs(); j++)
		{
			// save jobs into vector
			this->jobs.push_back(this->student[i].GetJob(j));
		}
		
	}
	//return address/pointer of this vector
	return &jobs;
}

// Return number of student from given course.
int Course::GetNumberOfStudents()
{
	return this->numberOfStudents;
}

// Return budget from given course.
int Course::GetBudget()
{
	return this->budget;
}
