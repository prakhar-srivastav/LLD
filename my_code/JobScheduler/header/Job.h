#pragma once


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <map>

int toNumber(std::string str);


class Job
{
private:
int id;
std::string name;
int duration;
int priority;
int deadLine;
int userType; // 3:ROOT, 2:ADMIN, 1:USER

public:
Job();
void initialize(std::vector<std::string> info,int id0);
int getDeadLine();
std::string getString(int timer);
int findEndTime(int timer);
int getDuration();
int getPriority();
int getUserType();
int getID();


};