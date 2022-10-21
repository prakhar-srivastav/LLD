#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "../Header/Group.h"

using namespace std;

bool Group::validateSplit(vector<float> &splits,float amount, string balanceType)
{
	vector<float> answer;
	int sz= (int)(splits.size());
	float sum =0 ;
	for(auto split:splits)
	{
		if(split<0) return false;
		sum+=split;
	}
	if(amount<0) return false;
	if(balanceType=="EQUAL")
	{
		float div = amount/sz;
		answer=vector<float>(sz,div);
		return true;
	}
	else if(balanceType=="EXACT")
	{
		if(sum!=amount) return false;
		answer = splits;
		return true;
	}
	else
	{
		if(sum!=100) return false;
		answer = splits;
		for(auto &val:answer) val*=amount;
		return true;
	}
	return false;
}
bool Group::validateUsers(vector<string> &userIDs,string userID)
{

	vector<string> arr = userIDs;
	arr.push_back(userID);
	sort(arr.begin(),arr.end());
	for(int i=0;i<(int)(arr.size())-1;i++)
	{
		if(arr[i]==arr[i+1]) return false;
		if(users.find(arr[i])==users.end()) return false;
	}
	return (users.find(arr.back())!=users.end());
}
vector<float> Group::generateSplit(vector<float> &splits,float amount,string balanceType)
{
	vector<float> answer;
	int sz= (int)(splits.size());
	float sum =0 ;
	
	if(balanceType=="EQUAL")
	{
		float div = amount/sz;
		answer=vector<float>(sz,div);
		return answer;
	}
	else if(balanceType=="EXACT")
	{
		
		answer = splits;
		return answer;
	}
	else
	{
		
		answer = splits;
		for(auto &val:answer) val*=amount;
		return answer;
	}
	return answer;
}

Group::Group()
{
	groupName="";
	description="";
}
Group::Group(string groupName0,string description0)
{
	groupName = groupName0;
	description=description0;
	users = map<string,User>{};
}
vector<string> Group::createExpense(string userId,string balanceType,vector<string> &userIDs,vector<float>& splits,float amount)
{
	if(!validateUsers(userIDs,userId))
		return vector<string>{"Something wrong with userIDs"};
	if(!(balanceType=="EQUAL" || balanceType=="PERCENT" || balanceType=="EXACT"))
		return vector<string>{"Invalid balanceType"};
	if(!validateSplit(splits,amount,balanceType))
		return vector<string>{"Something wrong with splits"};

	auto bill = generateSplit(splits,amount,balanceType);


	for(int i=0;i<(int)(bill.size());i++)
	{
		users[userIDs[i]].update(userId,bill[i]);
		users[userId].update(userIDs[i],-1*bill[i]);
	}

	return vector<string>{"successful"};
}
vector<string> Group::addUserToGroup(User &user)
{
	string userId = user.getId();
	if(users.find(userId)!=users.end())
		return vector<string>{"users already exists in the group"};

	users[userId] = user;
	return vector<string>{"Successful"};
}