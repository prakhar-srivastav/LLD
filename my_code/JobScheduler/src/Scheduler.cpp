#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include "../header/Scheduler.h"
#include <map>



Scheduler::Scheduler()
{
	timer =0 ; 
	threadCnt=0;
	jobCnt=0;
	threads = std::vector<int>{};
	jobs = std::vector<Job>{};
}

bool isNumber(std::string str)
{


	for(auto ch : str)
	{
		if(ch<'0' || ch>'9')
			return false;
	}

	return true;
}
bool isName(std::string str)
{


	for(auto ch : str)
	{
		if(ch<'A' || ch>'Z')
			return false;
	}

	return true;
}

bool Scheduler::validateJob(std::vector<std::string> job)
{

	bool Success = isNumber(job[1]) && isNumber(job[2]) && isNumber(job[3]);
	bool correctUserType=false;

	for(auto userType0 : userType)
	{
		if(userType0 ==job[4])
			correctUserType = true;
	}

	return Success && correctUserType;
}


bool SJFCompatator(Job &x, Job &y)
{
	std::vector<int> A{x.getDuration(),-1 * x.getPriority(), x.getID()};
	std::vector<int> B{y.getDuration(),-1 * y.getPriority(), y.getID()};	

	return A<B;

}
bool FCFSCompatator(Job &x, Job &y)
{
	std::vector<int> A{-1 * x.getPriority(),x.getUserType(), -1 *x.getDuration(), x.getID()};
	std::vector<int> B{-1 * y.getPriority(),y.getUserType(), -1 *y.getDuration(), y.getID()};

	return A<B;
}
bool EDFompatator(Job &x, Job &y)
{
	std::vector<int> A{-1 * x.getDeadLine(),-1 * x.getPriority(), x.getDuration(), x.getID()};
	std::vector<int> B{-1 * y.getDeadLine(),-1 * y.getPriority(), y.getDuration(), y.getID()};

	return A<B;
}

bool Scheduler::validateAlgorithm(std::string algorithmChoice)
{
	bool correctAlgoType=false;
	for(auto algoType0 : Algos)
	{
		if(algoType0 ==algorithmChoice)
			correctAlgoType = true;
	}
	std::cout << correctAlgoType << std::endl;
	return correctAlgoType;
}



void Scheduler::setThreads(int thread)
{
	threadCnt = thread;
	threads.resize(threadCnt,0);
}
void Scheduler::addJobs(std::vector<std::vector<std::string>> allJob)
{
	jobCnt = (int)(allJob.size());
	jobs = std::vector<Job>(jobCnt,Job());
	for(int i=0;i<jobCnt;i++)
		jobs[i].initialize(allJob[i],i);
}


std::vector<std::string> Scheduler::run(std::string algorithmChoice)
{

	
	if(algorithmChoice=="FCFS")
	{
		std::sort(jobs.begin(),jobs.end(),FCFSCompatator);
	}
	if(algorithmChoice=="SJF")
	{
		std::cout << "RUNNING SJFCompatator" << std::endl;
		std::sort(jobs.begin(),jobs.end(),SJFCompatator);
		std::cout << "COMPLETED SJFCompatator" << std::endl;
	}
	if(algorithmChoice=="EDF")
	{
		std::sort(jobs.begin(),jobs.end(),EDFompatator);
	}
	int itr =0 ;
	std::vector<std::vector<std::string>> threadAnswer(threadCnt);
	while(true)
	{
		
		for(int i =0 ; i<threadCnt;i++)
		{
			if(itr == jobCnt)
				break;
			if(threads[i]==0)
			{
				if(jobs[itr].getDeadLine()>timer) 
					{
						threadAnswer[i].push_back(jobs[itr].getString(timer));
						threads[i] = jobs[itr].findEndTime(timer);
					}
				itr = itr + 1;
			}
		}
		if(itr == jobCnt)
			break;
		int newTimer = -1;
		for(int i=0;i<threadCnt;i++)
		{
			if(threads[i]!=0)
			{
				if(newTimer == -1)
					newTimer = threads[i];
				else if(newTimer>threads[i])
					newTimer = threads[i]; 

			}
		}
		for(int i=0;i<threadCnt;i++)
		{
			if(threads[i]==newTimer)
			{
				threads[i] =0 ;
				 
			}
		}

		timer = newTimer;
	}
	std::vector<std::string> Outputs;
	for(int i=0;i<threadCnt;i++)
	{
		std::string threadStr = "Thread " + std::to_string(i+1);
		Outputs.push_back(threadStr);
		for(auto line : threadAnswer[i])
			Outputs.push_back(line);
	}
	return Outputs;
}

