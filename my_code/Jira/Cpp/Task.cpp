
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "../Header/Task.h"




Task::Task()
{
	taskName="";
	taskType="";
	taskStatus="";
	substract="";
}
Task::Task(string taskName0,string taskStatus0,string taskType0,string substract0)
{
	taskName=taskName0;
	taskType=taskType0;
	taskStatus=taskStatus0;
	substract=substract0;
}
vector<string> Task::getInfo()
{
	string message = "TaskName = "+taskName; 
	return vector<string>{message};
}
bool Task::isCompleted()
{

	if (taskStatus == "Completed")
		return true;
	return false;
}
vector<string> Task::changeTaskStatus(string newStatus)
{
	if(!(newStatus=="InProgress" || newStatus=="Completed"))
		return vector<string>{"Invalid Status"};

	taskStatus=newStatus;
	return vector<string>{"Change Task Status"};

}
