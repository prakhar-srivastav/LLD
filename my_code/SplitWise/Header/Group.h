#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "User.h"


using  namespace std;

class Group
{
private:
	string groupName,description;
	map<string,User> users;
	bool validateSplit(vector<float> &splits,float amount, string balanceType);
	bool validateUsers(vector<string> &userIDs,string userID);
	vector<float> generateSplit(vector<float> &splits,float amount,string balanceType);
public :
	Group();
	Group(string groupName0,string description0);
	vector<string> createExpense(string userId,string balanceType,vector<string> &userIDs,vector<float>& splits,float amount);
	vector<string> addUserToGroup(User &user);
};