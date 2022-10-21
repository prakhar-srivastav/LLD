


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <map>
#include "../header/Job.h"




int toNumber(std::string str)
{
	int res =0 ; 
	for(auto ch : str)
	{
		res= res*10 + ch - '0';
	}
	return res;
}


Job::Job()
{
	id = 0;
	duration = 0 ;
	priority =0;
	deadLine =0 ;
	userType =0 ;
}

void Job::initialize(std::vector<std::string> info,int id0)
{
	id = id0;
	name = info[0];
	duration = toNumber(info[1]);
	priority = toNumber(info[2]);
	deadLine = toNumber(info[3]);
	if(info[4]=="ROOT") userType = 3;
	if(info[4]=="ADMIT") userType = 2;
	if(info[4]=="USER") userType =1;

}
int Job::getDeadLine()
{
	return deadLine;
}
std::string Job::getString(int timer)
{
	return "Job " + std::to_string(id) + " added at time: " + std::to_string(timer);
}
int Job::findEndTime(int timer)
{
	return timer + duration;
}
int Job::getDuration()
{
	return duration;
}
int Job::getPriority()
{
	return priority;
}
int Job::getUserType()
{
	return userType;
}
int Job::getID()
{
	return id;
}