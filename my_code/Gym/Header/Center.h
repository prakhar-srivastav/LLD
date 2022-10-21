#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class Center
{
private:
	string name;
	vector<map<int,pair<int,pair<string,vector<string>>>>> slotsInDay;

public:
	Center();
	Center(string centerName);
	vector<string> addSlot(int slotTiming, string workOut,int capacity);
	vector<string> getDetails(int day);
	bool free(int day , int slotTiming);
	void bookSlot(string userID, int slotTiming,int day);
	vector<string> uodateSlot(int slotTiming,int capacity); // whole week
	bool isCapFree(int slotTiming,int day);
	string getWorkOut(int day, int slotTiming);
};