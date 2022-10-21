#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <string>
#include "../Header/App.h"

using namespace std;



App::App()
{
	rooms = map<string,Room>{};
	meetings = map<string,Meeting>{};
	dict = map<pair<int,int>,vector<Meeting*>>{};
}
vector<string> App::createRoom()
{
	string roomName;
	cin >> roomName;
	if(rooms.find(roomName)!=rooms.end())
	{
		return vector<string>{"Room " + roomName + " already exists"};
	}
	Room newRoom = Room(roomName);
	rooms[roomName] = newRoom;
	return vector<string>{"Room created"};
}
vector<string> App::bookMeeting()
{
	string meetingName,description;
	int start, finish;

	cin >> meetingName >> description >> start >> finish;

	if(meetings.find(meetingName)!=meetings.end())
	{
		return vector<string>{"Meeting name must be unique"};
	}

	for(auto &room : rooms)
	{
		auto roomName = room.first;
		auto& roomObject = room.second;

		if(roomObject.isAvailable(start,finish))
		{
			Meeting newMeeting = Meeting(meetingName,description,start,finish,roomName);
			meetings[meetingName] = newMeeting;
			roomObject.bookMeeting(&meetings[meetingName]);
			dict[{start,finish}].push_back(&meetings[meetingName]);
			// meetings[meetingName].update();
			 return vector<string>{meetingName + " created at Room " + roomName};
		}
	}

	return vector<string>{"No room available"};
}
vector<string> App::getMeetingHistory()
{
	string roomName;
	cin >> roomName;
	if(rooms.find(roomName)==rooms.end())
	{
		return vector<string>{"Room "+roomName + " does not exists" };
	}
	return rooms[roomName].getDetails();
}
vector<string> App::returnMeetingScheduled()
{
	int start,finish;
	cin >> start >> finish;
	auto& vec = dict[{start,finish}];
	vector<string> message;
	
	for(auto &meeting: vec )
	{
		auto meetingInfo = (*meeting).getInfo();
		for(auto line: meetingInfo)
			message.push_back(line);
	}
	return message;
}
