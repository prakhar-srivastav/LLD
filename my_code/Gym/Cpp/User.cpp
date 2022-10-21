#include<iostream>
#include<vector>
#include<string>
#include<map>

#include "../Header/User.h"






using namespace std;









User::User()
{
	name = "";
	id ="";
	mail = "";
	phone = "";
	pass = "";
	routine = vector<map<int,pair<string,string>>>(7);
}
User::User(string n,string i,string m,string p,string ps)
{
	name = n;
	id =i;
	mail = m;
	phone = p;
	pass = ps;
	routine = vector<map<int,pair<string,string>>>(7);
}
bool User::free(int day,int slotTime)
{
	if(routine[day].find(slotTime)==routine[day].end())
		return true;
	return false;
}
void User::bookSlot(string centerName,string workOut,int day,int slotTime)
{
	routine[day][slotTime] = {workOut,centerName};
}
vector<string> User::plan(int d)
{
	vector<string> msg;
	for (auto& x : routine[d])
	{
		msg.push_back("Slot time =" + to_string(x.first) );
		msg.push_back("WorkOut =" + x.second.first);
		msg.push_back("Center =" + x.second.second);

	}
	return msg;
}

