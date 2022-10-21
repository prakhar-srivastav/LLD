#include<iostream>
#include<vector>
#include<string>
#include<map>



using namespace std;

class User
{
private:
	string name;
	string id;
	string mail;
	string phone;
	string pass;
	vector<map<int,pair<string,string>>> routine;
public:
	User();
	User(string n,string i,string m,string p,string ps);
	bool free(int day,int slotTime);
	void bookSlot(string centerName,string workOut,int day,int slotTime);
	vector<string> plan(int d);

};