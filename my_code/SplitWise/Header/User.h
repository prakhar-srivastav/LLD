#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<string>


using  namespace std;




class User
{
private:
	string name, id;
	map<string, float> sheet;
	float totalSum;
	string getMessage(string x, float i);
public:
	User();
	User(string name0, string id0);
	string getId();
	void update(string name, float amount);
	vector<string> p2pDetails();
	vector<string> printTotalSum();
};