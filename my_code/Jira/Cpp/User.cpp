
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "../Header/User.h"


using namespace std;



User::User()
{
	name = "";
	sprints = map<string,Sprint> {};
	date=0;
}
User::User(string userName)
{
	name = userName;
	sprints = map<string,Sprint> {};
	date =0;
}
vector<string> User::sprintDetails(string sprintName)
{
	if(sprints.find(sprintName)==sprints.end())
		return vector<string>{"Sprint Does not exists"};
	return sprints[sprintName].getDetails(date);
}
vector<string> User::taskAssigned()
{
	vector<string> message;

	for(auto &sprint:sprints)
	{
		vector<string> taskInSprint = sprint.second.getTaskAssigned();
		for(auto &task:taskInSprint)
			message.push_back("Sprint = "+ sprint.second.getName()+ " "+ task);
	}

	return message;

}
vector<string> User::delayedTask()
{
	vector<string> message;

	for(auto &sprint:sprints)
	{
		vector<string> taskInSprint = sprint.second.getDelayedTask(date);
		for(auto &task:taskInSprint)
			message.push_back("Sprint = "+ sprint.second.getName()+ " "+ task);
	}

	return message;
}

vector<string> User::changeTaskStatus(string sprintName,string taskName,string taskStatus)
{
	if(sprints.find(sprintName)!=sprints.end())
		return vector<string>{"Sprint already exists"};
	
	return sprints[sprintName].changeTaskStatus(taskName,taskStatus);
}
vector<string> User::createTask(string sprintName,string taskName,string taskStatus,string taskType,string subtract)
{
if(sprints.find(sprintName)!=sprints.end())
		return vector<string>{"Sprint already exists"};
	
	return sprints[sprintName].createTask(taskName,taskStatus,taskType,subtract);
}
vector<string> User::createSprint(string sprintName,int start,int finish)
{

	if(sprints.find(sprintName)!=sprints.end())
		return vector<string>{"Sprint already exists"};
	if(start>finish)
		return vector<string> {"Start should be less than finish"};
	Sprint newSprint = Sprint(sprintName,start,finish);
	sprints[sprintName] = newSprint;
	return vector<string>{"Sprint created"};
}
vector<string> User::removeTask(string sprintName,string taskName)
{

	vector<string> message;

	for(auto &sprint:sprints)
	{
		vector<string> taskInSprint = sprint.second.getDelayedTask(date);
		for(auto &task:taskInSprint)
			message.push_back("Sprint = "+ sprint.second.getName()+ " "+ task);
	}

	return message;
}