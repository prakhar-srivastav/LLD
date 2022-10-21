#include<iostream>
#include<vector>
#include<string>
#include<map>
#include "../Header/Admin.h"

bool Admin::isNumber()
{
	return true;
}
bool Admin::valid(string s)
{
	return true;
}
Admin::Admin()
{
	users = map<string,User> {};
	centers = map<string,Center> {};
	userCnt =0 ;
}
vector<string> Admin::userRegister(string userName, string email, string Phone, string password)
{
	if(!(valid(userName) && valid(email)))
	{
		return vector<string>{"Invalid input"};
	}
	string userID = userName + to_string(userCnt);
	userCnt++;
	users[userID] =  User(userName,userID,email,Phone,password);
	return vector<string>{"UserID = " + userID};
}
vector<string> Admin::addSlot(string centerName,int slotTiming, string workOut,int capacity)
{
	if(!(valid(centerName) && valid(workOut) ))
	{
		return vector<string>{"Invalid input"};
	}
	return centers[centerName].addSlot(slotTiming,workOut,capacity);
}
vector<string> Admin::viewWorkout(int day)
{
	if(day>7 || day<1)
		return vector<string>{"Invalid Day"};
	vector<string> message;
	for(auto &center:centers)
	{
		auto info = center.second.getDetails(day);
		for(auto line:info)
			message.push_back(line);
	}
	return message;

}
vector<string> Admin::bookSlot(string userID, string centerID, int slotTiming, int day)
{
	if(users.find(userID)==users.end())
		return vector<string>{"Invalid ID"};
	if(centers.find(centerID)==centers.end())
		return vector<string>{"Invalid CenterID"};

	if(day>7 || day<1)
		return vector<string>{"Invalid Day"};

	// if(centers[centerID].free(day,slotTiming) && centers[centerID].isCapFree(day,slotTiming)&& users[userID].free(day,slotTiming) )
	// {

		centers[centerID].bookSlot(userID,slotTiming,day);
		users[userID].bookSlot(centerID,centers[centerID].getWorkOut(day,slotTiming),day,slotTiming);
		return vector<string>{"Booked"};
	// }
	return vector<string>{"Failed"};


}
vector<string> Admin::userPlan(string userID,int day)
{
	if(users.find(userID)==users.end())
		return vector<string>{"No such ids"};


	return users[userID].plan(day);
}
vector<string> Admin::uodateSlot(string centerID, int slotTiming, int capacity)
{
	
	if(centers.find(centerID)==centers.end())
		return vector<string>{"Invalid CenterID"};

	return centers[centerID].uodateSlot(slotTiming,capacity);
}

vector<string> Admin::addCenter(string centerName)
{
	if(centers.find(centerName)!=centers.end())
		return vector<string>{"Center exist"};
	centers[centerName] = Center(centerName);
	return vector<string>{"Created"};
}
