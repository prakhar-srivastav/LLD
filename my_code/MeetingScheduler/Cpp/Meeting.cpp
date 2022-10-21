#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <string>
#include "../Header/App.h"

using namespace std;


Meeting::Meeting()
{
	start =0;
	finish =0 ;
	name = "";
	description ="";
	roomName ="";
}
Meeting::Meeting(string meetingName,string description0,int start0,int finish0,string roomName0)
{
	start =start0;
	finish =finish0;
	name = meetingName;
	description = description0;
	roomName = roomName0;
}
void Meeting::update()
{
	start++;
	finish++;
}
vector<string> Meeting::getInfo()
{
	vector<string> message;
	message.push_back("The meeting name is " + name);
	message.push_back("The Description is" + description);
	message.push_back("Start = "+ to_string(start) + ", End = "+ to_string(finish));
	return message;
}
pair<int,int> Meeting::getRange()
{
	return {start,finish};
}