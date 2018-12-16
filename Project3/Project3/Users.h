#ifndef USERS_H
#define USERES_H

#pragma once
#include "Course.h"
#include "ResearchGroup.h"
#include "Staff.h"
#include <vector>

/**
	Users class is responsible for simlation of users in supercomputer environment.
	We can recognize different types of user: students in course, researcher in research group, IT member in staff.
	Not all class of users have been implemented.
**/

class Users
{
public:
	vector<Course> course;
	vector<ResearchGroup> researcherGroup;
	vector<Staff> staff;
public:
	Users();
	Users(int amount, int budget);
	~Users();
};

#endif

