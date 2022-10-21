#include<iostream>
#include<vector>
#include<string>
#include<map>
#include "../Header/App.h"

using namespace std;



App::App()
{
	employees=map<string,Employee>{};
	dsu = Dsu();
}
vector<string> App::listSubordinate()
{
	vector<string> message;
	int Type;
	cin >> Type;
	if(Type==0)
	{
		string id;
		cin >> id;
		if(employees.find(id)==employees.end())
			return vector<string>{"No employee with a given id"};
		
		return employees[id].getSubordinate();
	}
	else
	{
		string name;
		cin >> name;
		auto vec = findPrefix(name);
		for(auto match: vec)
		{
			auto info = employees[match].getSubordinate();
			message.push_back("Manager = " + employees[match].getName());
			for(auto line:info)
				message.push_back(line);
		}

	}
	return message;
}
vector<string> App::findPrefix(string name)
{
	vector<string> message;
	for(auto &e : employees)
	{
		auto &employee = e.second;
		auto &curId    = e.first;
		if(employee.isPrefix(name))
			message.push_back(employee.getId());
	}
	return message;
}
vector<string> App::findPrefix()
{
	string name;
	cin >> name;

	return findPrefix(name);
}
vector<string> App::addEmployee()
{
	string name, id;
	cin >> name >> id;
	if(employees.find(id)!=employees.end())
		return vector<string>{"ID already Exists"};

	dsu.addNode(id);
	Employee newEmployee = Employee(name,id);
	employees[id] = newEmployee;
	return vector<string>{"Employee created"};
}
vector<string> App::addRelation()
{
	string id0,id1;
	cin >> id0 >> id1;
	if(employees.find(id0)==employees.end() || employees.find(id1)==employees.end())
		return vector<string>{"ID does not exists"};

	bool success = dsu.addRelation(id0,id1);
	if(success)
	{
		auto &manager = employees[id0];
		auto &subordinate = employees[id1];
		subordinate.addManager(&manager);
		manager.addSubordinate(&subordinate);
		return vector<string>{"Relation added"};
	}
	return vector<string>{"Complicated Relation given"};
}
vector<string> App::getEmployeeDetails()
{
	string id;
	cin >> id;
	if(employees.find(id)==employees.end())
		return vector<string> {"No id found"};
	return employees[id].getDetails();
}