#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Task.h"

using namespace std;


class Sprint
{
private:

	string name;
	int start;
	int finish;
	map<string,Task> tasks;
	

public:
	Sprint();
	Sprint(string name0,int start0, int finish0);
	string getName();
	vector<string> getDelayedTask(int date);
	vector<string> changeTaskStatus(string taskName,string taskStatus);
	vector<string> createTask(string taskName,string taskStatus,string taskType,string substract);	
	vector<string> getTaskAssigned();
	vector<string> getDetails(int date);
	};
