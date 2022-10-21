#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <string>
#include "Meeting.h"
using namespace std;

class Room
{

private:
vector<Meeting*> meetings;
string name;
set<pair<int,int>> range;
public:
Room();
Room(string name0);
string getName();
void bookMeeting(Meeting* meeting);
bool isAvailable(int start,int finish);
vector<string> getDetails();


};