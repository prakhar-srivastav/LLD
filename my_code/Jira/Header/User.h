#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Sprint.h"

using namespace std;


class User
{
	
private:
	int date; 
	string name;
	map<string,Sprint> sprints;
public:
	User();
	User(string userName);
	vector<string> sprintDetails(string sprintName);
	vector<string> taskAssigned();
	vector<string> delayedTask();
	vector<string> removeTask(string sprintName,string taskName);
	vector<string> changeTaskStatus(string sprintName,string taskName,string taskStatus);
	vector<string> createTask(string sprintName,string taskName,string taskStatus,string taskType,string subtract);
	vector<string> createSprint(string sprintName,int start,int finish);
};
