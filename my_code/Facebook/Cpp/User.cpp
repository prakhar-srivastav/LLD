
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include "../Header/User.h"
using namespace std;


User::User() 
{
	userName = "";
	id = "";
}

User::User(string name,string id0): userName(name),id(id0)
{} 


string User::getName()
{
	return userName;
}