
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "../Header/User.h"

using namespace std;

User::User()
{
	name ="";
	id = "";
	totalSum = 0;
	sheet = map<string,float>{};
}

string User::getMessage(string x, float i)
{
	return x + " have an issue of " + to_string(i);
}
User::User(string name0,string id0)
{
	name =name0;
	id = id0;
	totalSum = 0;
	sheet = map<string,float>{};
}
string User::getId()
{
	return id;
}
void User::update(string name,float amount)
{
	sheet[name]+=amount;
}
vector<string> User::p2pDetails()
{
	vector<string> message;
	for(auto &user:sheet)
	{
		message.push_back(getMessage(name,user.second) + " to/from " + user.first);
	}
	return message;
}
vector<string> User::printTotalSum()
{
	return vector<string>{getMessage(name,totalSum)};
}