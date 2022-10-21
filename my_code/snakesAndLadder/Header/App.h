#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "Board.h"
#include "User.h"

using namespace std;
class App
{
private:
	vector<User> users;
	map<string,bool> userId;
	Board board;
	string Winner;
public:
	App();
	void createBoard();
	void createUser();
	void play();
};