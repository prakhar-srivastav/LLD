#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "User.h"
#include "Group.h"

using  namespace std;


class App
{
private:
	map<string,User> users;
	map<string,Group> groups;
public:
	App();
	vector<string> createUser();
	vector<string> createGroup();
	vector<string> createExpense();
	vector<string> addUserToGroup();
	vector<string> printTotalSum();
	vector<string> p2pDetails();
};