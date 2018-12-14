#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Project3/Student.h"
#include "../Project3/Course.h"
#include "../Project3/Processor.h"
#include "../Project3/Nodes.h"
#include "../Project3/Storage.h"
#include "../Project3/Job.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{		
	TEST_CLASS(CreatingObjects)
	{
	public:
		
		TEST_METHOD(CreateStudent)
		{
			int id = 10;
			Student student(id);
			Assert::AreEqual(id, student.GetStudentId());
		}

		TEST_METHOD(CreateCourse)
		{
			int numberOfStudentInCourse = 10;
			int budgetPerCourse = 100;
			Course course(Course::ComputerAidedEngineering, numberOfStudentInCourse, budgetPerCourse);
			Assert::AreEqual(numberOfStudentInCourse, course.GetNumberOfStudents());
			Assert::AreEqual(budgetPerCourse, course.GetBudget());

		}

		TEST_METHOD(CreateProcessor)
		{
			int id = 0;
			bool busy = false;
			Processor processor(Processor::CPU_multicore, id);
			Assert::AreEqual(id, processor.GetIdProcessor());
			Assert::AreEqual(busy, processor.ifBusy());
		}

		TEST_METHOD(CreateNode)
		{
			int id = 0; //id of node starts from 1 not from 0
			bool busy = false;
			Nodes node(Nodes::accelerated, busy);
			Assert::AreEqual(busy, node.ifBusy());
			Assert::AreEqual(id, node.getId());
		}

		TEST_METHOD(CreateStorage)
		{
			int generalSize = 10000;
			Storage storage(Storage::SSD);
			Assert::AreEqual(generalSize, storage.GetGeneralSize());
		}

		TEST_METHOD(CreateJob)
		{
			int createTime = 0; //not every job has createTime 0! is it proper unit test?
			Job job(Job::_small, createTime);
			Assert::AreEqual(createTime, job.GetCreateTime());
			
		}

	};
}