#include<iostream>
#include<vector>
#include<string>
#include<map>
#include "User.h"
#include "Center.h"

using namespace std;

class Admin
{
private:
	int userCnt;
	map<string,User> users;
	map<string,Center> centers;
	bool isNumber();
	bool valid(string s);
public:
	Admin();
	vector<string> userRegister(string userName, string email, string Phone, string password);
	vector<string> addSlot(string centerName,int slotTiming, string workOut,int  capacity);
	vector<string> viewWorkout(int day);
	vector<string> bookSlot(string userID, string centerID, int slotTiming,int day);
	vector<string> userPlan(string userID,int day);
	vector<string> uodateSlot(string centerID, int slotTiming,int capacity);
	vector<string> addCenter(string centerName);
};