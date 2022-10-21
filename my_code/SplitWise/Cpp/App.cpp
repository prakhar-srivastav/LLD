#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "../Header/App.h"

using namespace std;


App::App()
{
	users = map<string,User>{};
	groups = map<string,Group>{};
}
vector<string> App::createUser()
{
	string userName,userID;
	cin >> userName >> userID;

	if(users.find(userID)!=users.end())
		return vector<string>{"ID should be unique"};
	User newUser = User(userName,userID);
	users[userID] = newUser;
	return vector<string>{"Welcome "+ userName };
}
vector<string> App::createGroup()
{
	string groupName,description;
	cin >> groupName >> description;
	if(groups.find(groupName)!=groups.end())
		return vector<string>{"Group name already exists"};
	Group newGroup = Group(groupName,description);
	groups[groupName] = newGroup;
	return vector<string>{"Group added" };

}
vector<string> App::createExpense()
{
	string userID,groupName,balanceType;
	int size;
	float amount;
	vector<string> userIDs;
	vector<float> splits;

	cin >> userID >> groupName >> balanceType >> amount;
	cin >> size;
	userIDs.resize(size);
	for(auto &eachID:userIDs)
		cin >> eachID;
	if(balanceType!="EQUAL")
	{
		splits.resize(size);
		for(auto &split:splits)
			cin >> split;
	}

// userIDS should be different and userID should not be in userIDS
// every userIDS include userID should be in a group
// splitsType should be correct
// splits should be correct

	if(users.find(userID)==users.end())
		return vector<string>{"UserID doesNot exists"};
	if(groups.find(groupName)==groups.end())
		return vector<string>{"Group name doesNot exists"};
	return groups[groupName].createExpense(userID,balanceType,userIDs,splits,amount);


}
vector<string> App::addUserToGroup()
{
	string userName,groupName;
	cin >> userName >> groupName;
	if(users.find(userName)==users.end())
		return vector<string>{"User not registered"};
	if(groups.find(groupName)==groups.end())
		return vector<string>{"No such groups"};
	return groups[groupName].addUserToGroup(users[userName]);
}
vector<string> App::printTotalSum()
{
	string userName;
	cin >> userName;
	if(users.find(userName)==users.end())
		return vector<string>{"User not registered"};

	return users[userName].printTotalSum();
}
vector<string> App::p2pDetails()
{
	string userName;
	cin >> userName;
	if(users.find(userName)==users.end())
		return vector<string>{"User not registered"};

	return users[userName].p2pDetails();
}