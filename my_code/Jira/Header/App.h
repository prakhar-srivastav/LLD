#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "User.h"

using namespace std;


class App
{
private:
	
	map<string,User> users;
public:
	App();
	vector<string> createUser();
	vector<string> createTask();
	vector<string> changeTaskStatus();
	vector<string> createSprint();
	vector<string> removeTask();
	vector<string> delayedTask();
	vector<string> sprintDetails();
	vector<string> taskAssigned();

};