#ifndef COMPUTINGSYSTEM_H
#define COMPUTINGSYSTEM_H

#pragma once
#include "Nodes.h"
#include "Storage.h"
#include <vector>

using namespace std;

class ComputingSystem
{
public:
	static const int amountNodes = 128;
	vector<Nodes> nodes;
	Storage storage;
public:
	ComputingSystem();
	~ComputingSystem();
};

#endif

