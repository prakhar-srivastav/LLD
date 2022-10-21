
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include "../Header/Employee.h"
using namespace std;

Employee::Employee()
{
	name = "";
	id ="";
	manager = NULL;
	subordinates = vector<Employee*>{};
}
Employee::Employee(string name0,string id0)
{
	name = name0;
	id = id0;
	manager = NULL;
	subordinates = vector<Employee*>{};
}
vector<string> Employee::getSubordinate()
{	
	vector<string> message;
	for(auto employee: subordinates)
	{
		message.push_back((*employee).getName());
	}
	return message;
}
string Employee::getName()
{
	return name;
}
bool Employee::isPrefix(string str)
{
	if(name.size()>str.size())
		return false;
	if(name.substr(0,str.size())== str)
		return true;
	return false;
}
string Employee::getId()
{
	return id;
}
void Employee::addManager(Employee *employee)
{
 manager = employee;
}	
void Employee::addSubordinate(Employee *subordinate)
{
	subordinates.push_back(subordinate);
}
vector<string> Employee::getDetails()
{
	return vector<string> {"Employee Name = " + name };
}