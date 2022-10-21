

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include "../Header/Center.h"

using namespace std;

Center::Center()
{
	name = "";
	slotsInDay = vector<map<int,pair<int,pair<string,vector<string>>>>>(7);
}
Center::Center(string centerName)
{
	name = centerName;
	slotsInDay = vector<map<int,pair<int,pair<string,vector<string>>>>>(7);
}
vector<string> Center::addSlot(int slotTiming, string workOut,int capacity)
{

	for(auto &d : slotsInDay)
	{
		d[slotTiming] = {capacity,{workOut,vector<string>{}}};
	}
	return vector<string>{"Added"};
}
vector<string> Center::getDetails(int day)
{

	vector<string> message;

	message.push_back("Center name = " +name);

	
		for (auto& slot : slotsInDay[day])
		{
			message.push_back("Slot Timing =" + to_string(slot.first));

			auto& obj = slot.second;
			message.push_back("Capaciy = " + to_string(obj.first));
			message.push_back("workOut = " + obj.second.first);
		}
	
	return message;

}
bool Center::free(int day , int slotTiming)
{
	if(slotsInDay[day].find(slotTiming)==slotsInDay[day].end())
		return true;
	return false;
}
bool Center::isCapFree(int slotTiming,int day)
{
	if(slotsInDay[day][slotTiming].first>
	slotsInDay[day][slotTiming].second.second.size())
		return true;
	return false;
}
void Center::bookSlot(string userID, int slotTiming,int day)
{
	slotsInDay[day][slotTiming].second.second.push_back(userID);
}

string Center::getWorkOut(int day, int slotTiming)
{
	return slotsInDay[day][slotTiming].second.first;
}
vector<string> Center::uodateSlot(int slotTiming,int capacity)
{
	for(auto &d : slotsInDay)
	{
		d[slotTiming].second.first = capacity;
	}
	return vector<string>{"Slot updated"};
}