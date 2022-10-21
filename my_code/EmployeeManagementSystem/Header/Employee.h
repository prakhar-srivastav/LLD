#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;



class Employee
{
private:
	string name;
	string id;
	Employee* manager;
	vector<Employee*> subordinates;
public:
	Employee();
	Employee(string name0,string id0);
	vector<string> getSubordinate();
	string getName();
	bool isPrefix(string str);
	string getId();
	void addManager(Employee *employee);
	void addSubordinate(Employee *subordinate);
	vector<string> getDetails();

};