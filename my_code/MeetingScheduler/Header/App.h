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


class App
{
private:
map<string,Room> rooms;
map<string,Meeting> meetings;
map<pair<int,int>,vector<Meeting*>> dict;
public:
App();
vector<string> update();
vector<string> createRoom();
vector<string> bookMeeting();
vector<string> getMeetingHistory();
vector<string> returnMeetingScheduled();
};