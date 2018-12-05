#ifndef USERS_H
#define USERES_H

#pragma once
#include "Course.h"
#include "ResearchGroup.h"
#include "Staff.h"
#include <vector>
class Users
{
public:
	vector<Course> course;
	vector<ResearchGroup> researcherGroup;
	vector<Staff> staff;
public:
	Users();
	~Users();
};

#endif

