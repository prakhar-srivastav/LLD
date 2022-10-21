#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <set>
#include <string>
#include "../Header/Room.h"

using namespace std;




Room::Room()
{
	meetings = vector<Meeting*>{};
	name = "";
	range = set<pair<int,int>>{};
}
Room::Room(string name0)
{
	meetings = vector<Meeting*>{};
	name = name0;
	range = set<pair<int,int>>{};
}
string Room::getName()
{
	return name;
}
void Room::bookMeeting(Meeting* meeting)
{


	meetings.push_back(meeting);
	range.insert((*(meeting)).getRange());
	// (*meetings.back()).update()
	cout << range.size() << endl;
}
bool Room::isAvailable(int start,int finish)
{
	for(auto p : meetings)
	{
		auto q = (*p).getRange();
		if(!(start>q.second || finish<q.first))
			return false;
	}
	return true;
}
vector<string> Room::getDetails()
{

	vector<string> message;
	message.push_back("Room name = " + name );
	message.push_back("Number of meeting =" + to_string((int)(meetings.size())));
	for(auto p : meetings)
	{
		auto q = (*p).getInfo();
		for(auto l : q)
			message.push_back(l);
	}
	return message;
}