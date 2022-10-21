#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include "Dsu.h"
#include "Employee.h"

using namespace std;
class App
{
private:
	map<string,Employee> employees;
	Dsu dsu;
	vector<string> findPrefix(string name);
public:
	App();
	vector<string> listSubordinate();
	vector<string> findPrefix();
	vector<string> addEmployee();
	vector<string> addRelation();
	vector<string> getEmployeeDetails();
};