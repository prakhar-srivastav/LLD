#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>


using namespace std;



class Task
{
private:
	string taskName;
	string taskType;
	string taskStatus;
	string substract;
public:
	Task();
	Task(string taskName0,string taskStatus0,string taskType0,string substract0);
	vector<string> getInfo();
	bool isCompleted();
	vector<string> changeTaskStatus(string newStatus);

};