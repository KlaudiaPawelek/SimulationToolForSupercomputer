#include "pch.h"
#include "Users.h"

Users::Users()
{
	this->course.resize(3);
	this->course[0] = Course(Course::ComputerMachineVision, 10);
	this->course[1] = Course(Course::ComputerAidedEngineering, 10);
	this->course[2] = Course(Course::SoftwareEngineering, 10);
}


Users::~Users()
{
}
