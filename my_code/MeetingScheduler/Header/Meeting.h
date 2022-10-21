#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <string>
#include "Room.h"
#include "Meeting.h"
using namespace std;

class Meeting
{
private:
	int start;
	int finish;
	string name;
	string description;
	string roomName;
public:
	void update();
	Meeting();
	Meeting(string meetingName,string description0,int start0,int finish0,string roomName0);
	vector<string> getInfo();
	pair<int,int> getRange();
};






