#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;


class User
{
private:
	string userName;
	string id;
public:
	User();
	User(string name,string id0);
	string getName();
};