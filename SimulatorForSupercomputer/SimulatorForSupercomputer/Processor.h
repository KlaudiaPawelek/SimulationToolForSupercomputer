#ifndef PROCESSOR_H
#define PROCESSOR_H
#pragma once

class Processor
{
public:
	enum TypeOfProcessor
	{
		//typical multicore CPU
		CPU_multicore = 0,
		//typical GPU dedicated to computations
		GPU_computations = 1,
		//advanced GPU dedicated to rendering
		GPU_rendering = 2,
	};

	TypeOfProcessor type;
	int id;
	bool engaged;

public:

	/**
	* Default empty constructor.
	**/
	Processor();

	/** 
	* Create processor 
	* Typical CPU, GPU for computations or GPU for rendering.
	**/
	Processor(TypeOfProcessor type, int id);

	/**
	* Destructor
	**/
	~Processor();
};

#endif

