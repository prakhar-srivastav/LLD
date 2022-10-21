#pragma once


#include<iostream>
#include<vector>
#include<string>
#include "Job.h"
#include <map>

const std::vector<std::string> Algos = {"SJF","FCFS","FPS","EDF"};
const std::vector<std::string> userType = {"ROOT","ADMIN","USER"};


bool isNumber(std::string str);
bool isName(std::string str);

bool SJFCompatator(Job &x, Job &y);
bool FCFSCompatator(Job &x, Job &y);
bool EDFompatator(Job &x, Job &y);


class Scheduler
{
private:
int timer; 
int threadCnt;
int jobCnt;
std::vector<int> threads;
std::vector<Job> jobs;



public:
Scheduler();
bool validateJob(std::vector<std::string> job);
bool validateAlgorithm(std::string algorithmChoice);
void setThreads(int thread);
void addJobs(std::vector<std::vector<std::string>> allJob);
std::vector<std::string> run(std::string algorithmChoice);


};