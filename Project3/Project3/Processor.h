#ifndef PROCESSOR_H
#define PROCESSOR_H
#pragma once

/**
	Processor class is responsible for simulation of real processor in supercomputer.
	This class is used by Nodes class.
**/

class Processor
{
public:
	/**
		Enum type. Inlcude: 
		0 = typical multicore CPU 
		1 = typical GPU dedicated to computations
		2 = advanced GPU dedicated to rendering
	**/
	enum TypeOfProcessor
	{
		CPU_multicore = 0,
		GPU_computations = 1,
		GPU_rendering = 2,
	};

	/**
		Type of processor described by enum.
	**/
	TypeOfProcessor type;

private:
	/**
		Processor id in each node. From 0 to 15.
	**/
	int id;
	/**
		If processor is busy by any job. Depends on nodes.
	**/
	bool busy;

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

	/**
		Return information about id processor.
		@return int
	**/
	int GetIdProcessor();

	/**
		Return information about busy paremeter: if processor is busy by any job.
		@return bool
	**/
	bool ifBusy();
};

#endif

