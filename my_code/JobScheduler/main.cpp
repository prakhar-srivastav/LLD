#include<iostream>
#include<vector>
#include "header/Scheduler.h"
#include<string>



signed main()
{


	Scheduler scheduler = Scheduler();

	while(true)
	{
		std::cout <<"1.Begin Process" << std::endl;
		std::cout <<"2.Exit" << std::endl;
		std::cout << "Enter your choide" << std::endl;
		int Choice;
		std::cin >> Choice;
		
		switch(Choice)
		{
			case 1:
			{
				std::cout << "Enter the number of jobs and threads respectively" << std::endl; 
				int jobCnt,threadCnt;
				std::cin >> jobCnt >> threadCnt;
				std::vector<std::vector<std::string>> jobs(jobCnt);
				int itr = 0;
				for(itr =0 ; itr< jobCnt ; itr++)
				{
					std::cout << "Enter Job:" << (itr+1) << std::endl;
					jobs[itr].resize(5);
					for(auto &enteries: jobs[itr])
						std::cin >> enteries;
					bool check = scheduler.validateJob(jobs[itr]);
					if(!check)
					{
						std::cout << "Invalid Job entry" << std::endl;
						break; 
					}
				}

				if(itr!=jobCnt)
				{
					std::cout << "Job entries were found incorrect." << std::endl;
					break;
				}
				std::cout << "Enter Algorithm Name" << std::endl;	
				std::string algorithmChoice;
				std::cin >> algorithmChoice;

				bool check = scheduler.validateAlgorithm(algorithmChoice);
				if(!check)
				{
					std::cout <<"Invalid Algorithmn" << std::endl;
					break;
				}

				scheduler.addJobs(jobs);
				scheduler.setThreads(threadCnt);
				std::vector<std::string> Output = scheduler.run(algorithmChoice);

				for(auto line : Output)
					std::cout << line << std::endl;

				break;
			}
			case 2:
			{
				std::cout << "Exiting System" << std::endl;
				return 0;
			}
			default:
			{
				std::cout << "Invalid Choice" << std::endl;
				break;
			}
		}



	}






	return 0; 
}