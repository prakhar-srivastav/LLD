
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "../Header/Sprint.h"
using namespace std;

Sprint::Sprint()
{
	start =0;
	finish =0 ;
	name ="";
	tasks = map<string,Task>{};
}
Sprint::Sprint(string name0,int start0, int finish0)
{
	start =start0;
	finish =finish0 ;
	name =name0;
	tasks = map<string,Task>{};
}
string Sprint::getName()
{
	return name;
}

vector<string> Sprint::getDelayedTask(int date)
{
	if(date<=finish)
	{
		return vector<string>{};
	}
	vector<string> message;
	for(auto task : tasks)
	{
		if (!task.second.isCompleted())
		{
			vector<string> info = task.second.getInfo();
			for (auto line : info)
				message.push_back(line);
		}
				
	}
	return message;


}
vector<string> Sprint::changeTaskStatus(string taskName,string taskStatus)
{
	if(tasks.find(taskName)==tasks.end())
		return vector<string>{"Task does not exists"};

	return tasks[taskName].changeTaskStatus(taskStatus);
}
vector<string> Sprint::createTask(string taskName,string taskStatus,string taskType,string substract)
{

	if(tasks.find(taskName)!=tasks.end())
		return vector<string>{"Task already exists"};

	if(!(taskStatus=="InProgess" || taskStatus=="Completed"))
		return vector<string>{"Invalid Task Status"};

	if(!(taskType=="Bug" || taskType=="Feature" || taskType=="Story"))
		return vector<string>{"Invalid Story Type"};

	
	Task newTask = Task(taskName,taskStatus,taskType,substract);
	tasks[taskName] = newTask;
	return vector<string> {"Task Created"};

}	
vector<string> Sprint::getTaskAssigned()
{
	vector<string> message;
	for(auto& task : tasks)
	{
		if (!task.second.isCompleted())
		{
			vector<string> info = task.second.getInfo();
			for (auto line : info)
				message.push_back(line);
		}
	}

	return message;
}
vector<string> Sprint::getDetails(int date)
{

	vector<string> message;
	int total=0;
	int completed=0;
	message.push_back("Sprint = " + name);
	message.push_back("Start = " + start);
	message.push_back("End = " + finish);
	for(auto &task: tasks)
	{
		if(task.second.isCompleted())
			completed++;
		total++;
	}
	message.push_back("Total Task = " + to_string(total));
	message.push_back("Task in progress = " + to_string(total-completed));
	message.push_back("Completed Task = " + to_string(completed));
	if(date>finish)
		message.push_back("Task are delayed");
	return message;
}