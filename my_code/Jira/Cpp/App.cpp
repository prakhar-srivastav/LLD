
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "../Header/App.h"

using namespace std;

App::App()
{
	users = map<string,User>{};
}

vector<string> App::createUser()
{
	string userName;
	cin >> userName;
	if(users.find(userName)!=users.end())
		return vector<string>{"Error user already exists"};


	User newUser = User(userName);
	users[userName] = newUser;
	return vector<string>{"Welcome "+ userName};
}


vector<string> App::createSprint()
{

	string userName,sprintName;
	int start,finish;
	cin >> userName >> sprintName >> start >> finish;

	if(users.find(userName)==users.end())
		return vector<string>{"Error user doesnot exists"};

	return users[userName].createSprint(sprintName,start,finish);
}





vector<string> App::createTask()
{
	string userName,sprintName,taskName,taskStatus,taskType,subtract;

	cin >> userName >> sprintName >> taskName >> taskStatus >> taskType;

	if(taskType =="Story")
		cin >> subtract;

	if(users.find(userName)==users.end())
		return vector<string>{"User does not exists"};

	return users[userName].createTask(sprintName,taskName,taskStatus,taskType,subtract);
}
vector<string> App::changeTaskStatus()
{
	string userName,sprintName,taskName,taskStatus;

	cin >> userName >> sprintName >> taskName >> taskStatus;

	if(users.find(userName)==users.end())
		return vector<string>{"User does not exists"};

	return users[userName].changeTaskStatus(sprintName,taskName,taskStatus);
}

vector<string> App::removeTask()
{
	string userName,sprintName,taskName;

	cin >> userName >> sprintName >> taskName;

	if(users.find(userName)==users.end())
		return vector<string>{"User does not exists"};

	return users[userName].removeTask(sprintName,taskName);	
}
vector<string> App::delayedTask()
{
	string userName;
	cin >> userName;

	if(users.find(userName)==users.end())
		return vector<string>{"User does not exists"};

	return users[userName].delayedTask();		
}

vector<string> App::taskAssigned()
{
	string userName;
	cin >> userName;

	if(users.find(userName)==users.end())
		return vector<string>{"User does not exists"};

	return users[userName].taskAssigned();	
}

vector<string> App::sprintDetails()
{
	string userName,sprintName;
	cin >> userName >> sprintName;

	if(users.find(userName)==users.end())
		return vector<string>{"User does not exists"};

	return users[userName].sprintDetails(sprintName);	
}
